//
//  Token.h
//  COP1
//
//  Created by Niklas Breuer on 13.05.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#ifndef __COP1__Token__
#define __COP1__Token__

#include <iostream>
#include <string>

using namespace std;

class Token{
public:
    Token();
    ~Token();
    Token(char type, string value);
    
    char getType();
    string getValue();
    
    void printToken();
    
private:
    char type;
    string value; //could be refactored with ValueClass kind of type
};

#endif /* defined(__COP1__Token__) */
