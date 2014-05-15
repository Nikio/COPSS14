//
//  Token.cpp
//  COP1
//
//  Created by Niklas Breuer on 13.05.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#include "Token.h"

//Standardconstructor
Token::Token(){
    
}

Token::~Token(){
    
}

Token::Token(char type, string value){
    this->type = type;
    this->value = value;
}

char Token::getType(){
    return this->type;
}

string Token::getValue(){
    return this->value;
}

void Token::printToken(){
    cout << "type:" << this->type << "\tvalue:" << this->value << endl;
}