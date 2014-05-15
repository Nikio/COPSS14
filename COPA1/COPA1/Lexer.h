//
//  Lexer.h
//  COP1
//
//  Created by Niklas Breuer on 14.04.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#ifndef __COP1__Lexer__
#define __COP1__Lexer__

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

#include "Token.h"

using namespace std;

class Lexer{
public:
    Lexer();
    //vector<Token> startLexing(string input);
    vector<Token> stateMachine(string input);
    bool checkForSpecialchars(char currentchar);
    char* getTokenStartPos();
    char* getCurrentReadPos();
    char next(); //Possible addition to the stateMachine, not sure yet
    Token runNumber(); //Runs if Token starts with a number
    Token runChar();
    
private:
    char* tokenStartPos;
    char* currentReadPos;
};

#endif /* defined(__COP1__Lexer__) */
