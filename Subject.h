//
//  Subject.h
//  ObserverSample
//
//  Created by devtak on 2017. 5. 28..
//  Copyright (c) 2017 devtak. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "Singleton.h"
#include "EventNotifier.h"
#include "ISubjectListener.h"


class Subject :
    public Singleton<Subject>,
    public EventNotifier<ISubjectListener>
{
public:
    void addEventListener(ISubjectListener& listener);
    void removeEventListener(ISubjectListener& listener);

    void foo();
    void bar(const std::string& param1, int param2);
    
private:
};

