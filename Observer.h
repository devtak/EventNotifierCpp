//
//  Observer.h
//  ObserverSample
//
//  Created by devtak on 2017. 5. 28..
//  Copyright (c) 2017 devtak. All rights reserved.
//


#pragma once

#include <stdio.h>
#include "ISubjectListener.h"

class Observer :
    public ISubjectListener
{
public:
    Observer();
    virtual ~Observer();
    
    virtual void onSubjectEvent1();
    virtual void onSubjectEvent2(std::string strParam, int iParam);

};

