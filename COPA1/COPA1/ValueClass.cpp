//
//  ValueClass.cpp
//  COP1
//
//  Created by Niklas Breuer on 15.05.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#include "ValueClass.h"

ValueClass::ValueClass(char type, string value){
    this->type = type;
    this->value = value;
}

ValueClass::ValueClass(Token& t){
    this->type = t.getType();
    this->value = t.getValue();
}

char ValueClass::getType(){
    return type;
}

string ValueClass::getValue(){
    return value;
}