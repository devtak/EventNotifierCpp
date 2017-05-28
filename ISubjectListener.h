//
//  ISubjectListener.h
//  ObserverSample
//
//  Created by devtak on 2017. 5. 28..
//  Copyright (c) 2017 devtak. All rights reserved.
//


#pragma once

#include <string>


class ISubjectListener
{
public:
    virtual ~ISubjectListener() {}
    
    virtual void onSubjectEvent1() {}
    virtual void onSubjectEvent2(std::string strParam, int iParam) {}
};


