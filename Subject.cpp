//
//  Subject.cpp
//  ObserverSample
//
//  Created by devtak on 2017. 5. 28..
//  Copyright (c) 2017 devtak. All rights reserved.
//

#include "Subject.h"


void Subject::addEventListener(ISubjectListener& listener)
{
    addObserver(&listener);
}

void Subject::removeEventListener(ISubjectListener& listener)
{
    removeObserver(&listener);
}

void Subject::foo()
{
    fireEvent(&ISubjectListener::onSubjectEvent1);
}

void Subject::bar(const std::string& param1, int param2)
{
    fireEvent(&ISubjectListener::onSubjectEvent2, param1, param2);
}
