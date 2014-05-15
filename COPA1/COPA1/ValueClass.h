//
//  ValueClass.h
//  COP1
//
//  Created by Niklas Breuer on 15.05.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#ifndef __COP1__ValueClass__
#define __COP1__ValueClass__

#include <iostream>
#include "Token.h"

using namespace std;

//The purpose of this class is to give the parser the ability to return any kind of value as long as the value can be expressed in a string

class ValueClass{
public:
    ValueClass(char type, string value);
    ValueClass(Token& t);
    char getType();
    string getValue();
    
private:
    char type;
    string value;
};

#endif /* defined(__COP1__ValueClass__) */
