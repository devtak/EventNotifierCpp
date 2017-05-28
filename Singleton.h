//
//  Singleton.h
//  ObserverSample
//
//  Created by devtak on 2017. 5. 28..
//  Copyright (c) 2017 devtak. All rights reserved.
//

#pragma once

template <class T>
class Singleton
{
public:
    static T* instance()
    {
        if (nullptr == _instance)
        {
            _instance = new T();
            _instance->onInit();
        }
        return _instance;
    }
    
    static void release()
    {
        if (_instance)
        {
            _instance->onRelease();
            delete _instance;
        }
        _instance = nullptr;
    }
    
protected:
    Singleton() {}
    virtual ~Singleton() {}
    
    virtual void onInit() {}
    virtual void onRelease() {}
    
private:
    Singleton(Singleton const&)
    {
        _instance = static_cast<T*>(this);
    }
    Singleton& operator=(Singleton const&) {}
    
    static T* _instance;
};

template<class T> T* Singleton<T>::_instance = nullptr;

