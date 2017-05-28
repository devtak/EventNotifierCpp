//
//  Observer.cpp
//  ObserverSample
//
//  Created by devtak on 2017. 5. 28..
//  Copyright (c) 2017 devtak. All rights reserved.
//

#include "Observer.h"
#include <iostream>
#include "Subject.h"


Observer::Observer()
{
    Subject::instance()->addEventListener(*this);
}

Observer::~Observer()
{
    Subject::instance()->removeEventListener(*this);
}

void Observer::onSubjectEvent1()
{
    std::cout << "event1" << std::endl;
}

void Observer::onSubjectEvent2(std::string strParam, int iParam)
{
    std::cout << strParam << std::endl;
    std::cout << iParam << std::endl;
}

