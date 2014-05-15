//
//  Parser.cpp
//  COP1
//
//  Created by Niklas Breuer on 07.05.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#include "Parser.h"

Parser::Parser(){
    this->currentpos = NULL;
    symbols["c"] = 9;
}

//Checks if a certain value is equal to the value of the next token
//If true, "eat" the token by increasing the reading position and return true
//If false, just return false
bool Parser::checkNextToken(string valueToCheck){
    Token testToken = *currentpos;
    if (testToken.getValue() == valueToCheck) {
        testToken.printToken();
        currentpos++;
        return true;
    }
    return false;
}

//Gets the next Token
Token Parser::getNextToken(){
    
    Token nextToken = *currentpos;
    nextToken.printToken(); //for testing purposes
    this->currentpos++;
    
    return nextToken;
}

//Helper-Method, gets a valueClass and transforms it's value into an int, if the type is a string/char, confirms if the variable is defined, else throws an error
int Parser::checkID(ValueClass vc){
    if (vc.getType() == 'c') {
        if (symbols.find(vc.getValue()) == symbols.end()) {
            cout << "Variable " << vc.getValue() << " not found" << endl;
            return -1;
        }else{
            return symbols[vc.getValue()];
        }
    }
    return atoi(vc.getValue().c_str());
}

//API-Method for starting the recursive parsingprocess
void Parser::startParsing(vector<Token> input){
    this->currentpos = &input.at(0);
    if (this->currentpos != NULL) {
        parseStatement();
    }else{
        cout << "No input found" << endl;
    }
}


//Rule 0: S -> E | F = E
void Parser::parseStatement(){
    while (currentpos->getType() != 'e') {
        currentpos++;
    if (currentpos->getValue() != ("=")) {
        currentpos--;
        int result = parseExpr();
        cout << result << endl;
    }else{
        currentpos--;
        ValueClass var = parseFactor();
        if (var.getType() == 'c') {
            if (checkNextToken("=")) {
                int value = parseExpr();
                symbols[var.getValue()] = value; //funktioniert noch nicht, weil parseFactor() noch int statt valueType zurückliefert
            }
        }
    }
    }
}

//Mir fehlt hier noch die Abbruchbedingung

//Rule 1: E -> T {+ T | -T}
int Parser::parseExpr() {
    int expr = parseTerm();
    
    while (checkNextToken("+") || checkNextToken("-")) {
        currentpos--; //Notwendig wegen "checkNextToken()", Design könnte besser sein
        if(checkNextToken("+")){
            expr += parseTerm();
        }else if(checkNextToken("-")){
            expr -= parseTerm();
        }
    }
    
    return expr;
}

//Rule 2: T -> F {* F | / F}
int Parser::parseTerm() {
    
    int factor = checkID(parseFactor());
    
    while (checkNextToken("*") || checkNextToken("/")) {
        currentpos--; //Notwendig wegen "checkNextToken()", Design könnte besser sein
        if(checkNextToken("*")){
            factor *= checkID(parseFactor());
        }else if(checkNextToken("/")){
            int operand = checkID(parseFactor());
            if (operand != 0) {
                factor /= operand;
            }else{
                cout << "Error: Division with 0" << endl;
            }
        }
    }
    return factor;
}

//Rule 3: F -> (E) | id | epsilon
ValueClass Parser::parseFactor(){
    
    Token token = getNextToken();
    token.printToken(); //for testing purposes
    
    if (token.getType() != 'o') {
        return ValueClass(token);
    }
    throw logic_error("Error: Expected id, but was operation");
}