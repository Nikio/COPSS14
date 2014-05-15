//
//  Parser.h
//  COP1
//
//  Created by Niklas Breuer on 07.05.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#ifndef __COP1__Parser__
#define __COP1__Parser__

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Token.h"
#include "ValueClass.h"

using namespace std;

class Parser{
public:
    Parser();
    
    Token getNextToken();
    bool checkNextToken(string valueToCheck);
    void startParsing(vector<Token> input);
    
private:
    void parseStatement();
    int parseExpr();
    int parseTerm();
    ValueClass parseFactor();
    int checkID(ValueClass vc);
    
    map<string,int> symbols;
    Token* currentpos;

};

#endif /* defined(__COP1__Parser__) */
