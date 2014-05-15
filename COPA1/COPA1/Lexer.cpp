//
//  Lexer.cpp
//  COP1
//
//  Created by Niklas Breuer on 14.04.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#include "Lexer.h"

/*
 * Der Lexer ist ein Werkzeug. Brauche ich den Inputstring als Variable?
    Ja, gebraucht für die Positionsbestimmungen
 
 * Was brauche ich?
 - startPos() - Positionen des ersten Tokencharacters
 - currentPos() - aktuelle Leseposition
 - Auswertungsmethoden() -> Char is Number? Char? Operation? SomethingElse?
 - Was ist die Idee hinter der Valueclass? Benötigt für Lexer oder für Parser?
 
 * Was sind die Zustände?
- Die Zustände sind die eingegeben Zeichen
 Bsp. = , kommt danach >,<, Zahl, Character, was anderes? --> neuer Zustand --> irgendwann reset der Eingabe (wenn Tokenerkennung abgeschlossen ist)
 
 - Wie verhindert man unendliche Strings?
 - Statemachine: Ansatz von Rob Pike in C++ möglich?
    -> Wie funktioniert der Statescanner?
 */


/*
 get a State -> call it -> get a State
 statefunction
 func run(){
    for state := StartState; state != nil; {
        state = state(lexer)
    }
 }
 */

Lexer::Lexer(){
    
}

char* Lexer::getTokenStartPos(){
    return this->tokenStartPos;
}

char* Lexer::getCurrentReadPos(){
    return this->currentReadPos;
}

//Evtl. nutzbar für die State Machine, Konzept noch etwas schwammig
char Lexer::next(){
    this->tokenStartPos = this->currentReadPos;
    return *currentReadPos;
}


//Creates a numbertoken and it's value
Token Lexer::runNumber(){
    stringstream tokenvalue;
    while (isdigit(*currentReadPos)){
        tokenvalue << *currentReadPos;
        currentReadPos++;
        if (currentReadPos == NULL) {
            break;
        }
    }
    return Token('n',tokenvalue.str());
}


//Creates a chartoken and it's value
Token Lexer::runChar(){
    stringstream tokenvalue;
    while (!checkForSpecialchars(*currentReadPos) && *currentReadPos != ' '){
        tokenvalue << *currentReadPos;
        currentReadPos++;
        if (*currentReadPos == '\0') {
                break;
        }
    }
    return Token('c', tokenvalue.str());
}

/*
 Checks if the character on the currentReadPos is an operation
 */
bool Lexer::checkForSpecialchars(char currentchar){
    string specialchars = "+-*/=";
    
    long isSpecialchar = distance(specialchars.begin(), find(specialchars.begin(), specialchars.end(), currentchar));
    if (isSpecialchar < specialchars.length()) {
        return true;
    }
    return false;
}


//Calculates the different possible states and takes the corresponding actions
vector<Token> Lexer::stateMachine(string input){
    this->currentReadPos = &input[0];
    vector<Token> tokenvector;
    
    while (*currentReadPos != '\0') {
        Token token;
        if (isdigit(*currentReadPos)) { //checks if the first character from the input is a number
            token = runNumber();
            //Checking the next char(has to be an operation) for error handling
            if (!checkForSpecialchars(*currentReadPos)
                && *currentReadPos != '\0' && *currentReadPos != ' ')
            {
                cout << "Error: expected an operation or eof but was character '" << *currentReadPos << "'" << endl;
                vector<Token> failedvector;
                return failedvector;
            }
        }else if(*currentReadPos == ' '){ //checks for whitespace
            this->currentReadPos++;
            continue;
            
        }else{
            if (checkForSpecialchars(*currentReadPos)) { //checks for operations
                stringstream valuestream;
                valuestream << *currentReadPos;
                token = Token('o', valuestream.str());
                currentReadPos++;
            }else{ //defaultcase since any other char can be part of a name
                token = runChar();
            }
        }
        tokenvector.push_back(token);
    }
    //-------!Quick-Fix, sollte nochmal überarbeitet werden!
    Token endtoken = Token('e', "eof");
    tokenvector.push_back(endtoken);
    //------
    return tokenvector;
}


/*
vector<Token> Lexer::startLexing(string input){
    this->inputString = input;
    this->currentReadPos = &input[0];
    string specialchars = "+*-/=";
    vector<Token> tokenarray;
    char currentchar;
    
    for (int i=0; i< input.length(); i++) {
        stringstream tokenvalue;
        Token token;
        //currentchar = input[i];
        currentchar = next();
        if (isdigit(currentchar)) { //checking for numbers
            
            //loop for summing up the number, breaks when the next character is not a number
            do{
                tokenvalue << currentchar;
                i++;
                currentReadPos++;
                currentchar = input[i];
            }while (isdigit(currentchar) && i < input.length());
            
            //checking if the next character is an operation, otherwise returns an error message
            long isSpecialchar = distance(specialchars.begin(), find(specialchars.begin(), specialchars.end(), currentchar));
            if (isSpecialchar == specialchars.length() && i<input.length()-1) {
                cout << "Error: expected an operation but was character '" << currentchar <<"' at #" << i <<" ." << endl;
                return tokenarray;
            }
            i--;
            token = Token('n', tokenvalue.str());
            
        }else if(currentchar == ' '){ //checking for whitespace
            //do nothing
            //continue;
            
        }else{
            long isSpecialchar = distance(specialchars.begin(), find(specialchars.begin(), specialchars.end(), currentchar));
            if (isSpecialchar < specialchars.length()) {
                
                tokenvalue << currentchar;
                token = Token('o', tokenvalue.str());
                currentReadPos++;
                
            }else{ //checking for characters
                //loop for summing up the characters to identify the keywords/variables, (confirms if the variable is declared?)
                //breaks if the next character is a special character or a whitespace
                do{
                    tokenvalue << currentchar;
                    i++;
                    currentReadPos++;
                    currentchar = input[i];
                    isSpecialchar = distance(specialchars.begin(), find(specialchars.begin(), specialchars.end(), currentchar));
                }while ((isSpecialchar == specialchars.length() && i < input.length()-1) && (currentchar != ' ' && i < input.length()-1));
                
                i--;
                token = Token('c', tokenvalue.str());
            }
            
        }
        
        tokenvalue.clear();
        tokenarray.push_back(token);
    }
    
    return tokenarray;
}*/