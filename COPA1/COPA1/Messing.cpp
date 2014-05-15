//
//  Messing.cpp
//  COP1
//
//  Created by Niklas Breuer on 13.05.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#include "Messing.h"

Messing::Messing(){
    
}

void Messing::startStuff(){
    //---- messing around with ASCII and Pointers
    char testIntCast = '0';
    int castedChar = (int)testIntCast;
    
    cout << castedChar-48 << endl;
    
    string inputTest = "Hello World";
    char* testPtr = &inputTest[0];
    
    cout << "testPtr points to " << inputTest[0]<< " with the value of " << *testPtr << endl;
    
    testPtr++;
    
    cout << "testPtr points to " << &testPtr << " with the value of " << *testPtr << endl;
    
    int a = 10;
    int* aPtr = &a;
    
    
    cout << aPtr << " has the value of " << *aPtr << endl;
    
    *aPtr = 20;
    
    cout << aPtr << " has the value of " << *aPtr << endl;
    
    int b = 25;
    aPtr = &b;
    
    cout << aPtr << " has the value of " << *aPtr << endl;
    
    int c = 28;
    int& bPtr = c;
    
    cout << &bPtr << " is a reference to " << c << endl;
    
    //------
}