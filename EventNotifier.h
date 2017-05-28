//
//  EventNotifier.h
//  ObserverSample
//
//  Created by devtak on 2017. 5. 28..
//  Copyright (c) 2017 devtak. All rights reserved.
//

#pragma once


#include <list>
#include <algorithm>
#include <future>

//#define _USE_MUTEX_

#ifdef _USE_MUTEX_
#include <mutex>
#endif

template <class T>
class EventNotifier
{
public:
    void addObserver(T* observer)
    {
#ifdef _USE_MUTEX_
        std::unique_lock<std::mutex> lock(_mutex);
#else
        _changed = true;
#endif
        _observers.push_back(observer);
    }
    
    void removeObserver(T* observer)
    {
#ifdef _USE_MUTEX_
        std::unique_lock<std::mutex> lock(_mutex);
#else
        _changed = true;
#endif
        _observers.remove(observer);
    }
    
    void getObservers(std::list<T*>& observers)
    {
        observers = _observers;
    }
    
    bool IsExist(const T* observer)
    {
#ifdef _USE_MUTEX_
        std::unique_lock<std::mutex> lock(_mutex);
#endif
        auto it = std::find(_observers.begin(), _observers.end(), observer);
        if (it != _observers.end())
        {
            return true;
        }
        return false;
    }
    
    template <typename TResult, typename... MethodArgTypes, typename... ActualArgTypes>
    void fireEvent(TResult (T::*method)(MethodArgTypes...), ActualArgTypes&&... args)
    {
#ifdef _USE_MUTEX_
        std::unique_lock<std::mutex> lock(_mutex);
        for (auto observer : _observers)
#else
            _copyObservers();
        for (auto observer : _copiedObservers)
#endif
        {
            //			auto func = std::bind(method, observer, args...);
            //			func();
            (observer->*method)(args...);
        }
    }
    
    template <typename TResult, typename... MethodArgTypes, typename... ActualArgTypes>
    TResult fireEvent(T* observer, TResult (T::*method)(MethodArgTypes...), ActualArgTypes&&... args)
    {
        return (observer->*method)(args...);
    }
    
    
private:
    
#ifndef _USE_MUTEX_
    void _copyObservers()
    {
        if (_changed)
        {
            _copiedObservers = _observers;
            _changed = false;
        }
    }
#endif
    
    std::list<T*> _observers;
    
#ifdef _USE_MUTEX_
    std::mutex _mutex;
#else
    std::list<T*> _copiedObservers;
    bool _changed = false;
#endif
};
