//
//  main.cpp
//  COP1
//
//  Created by Niklas Breuer on 14.04.14.
//  Copyright (c) 2014 Niklas Breuer. All rights reserved.
//

#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

#include "Lexer.h"
#include "Parser.h"
#include "Messing.h"

using namespace std;

int main(int argc, const char * argv[])
{

    //--- Lexer (primitiv)
    string input = "foo = 8 foo-2*5+foo";
    
    Lexer lexer;
    cout << "LexerTestOutputs:" << endl;
    vector<Token> tokenarray = lexer.stateMachine(input);
    
    for (int i=0; i < tokenarray.size(); i++){
        cout << &tokenarray.at(i) << endl;
    }
    cout << endl;
    
    //----Parser (primitiv) ------
    /*
     - Schnittstelle zwischen Lexer und Parser ist das Array
     ---> Funktion von Lexer und Parser unabhängig (evtl. Zugriffsproblem beim Array)
     - Der Input ist ein Tokenfeld(evtl. Vektor oder String besser statt char-array?)
     - Der Parser analysiert Token1, erreicht dadurch einen Zustand(? ein Parser/Interpreter hat keine States (oder?)) von dem er ein weiteres Token einer gewissen Art erwartet, falls nicht Fehler (siehe auch Folien)
     ---> Ich brauche eine Grammatik (siehe Zettel)
     - Wie soll das Interface aussehen? Brauche ich einen Pointer der auf das aktuelle Token zeigt? (Attribut des Parsers? Gibt es eine andere Möglichkeit?)
     - Wie startet der Parser? Wie muss getToken() designed werden, damit die Methode abstrakt ist?
     ---> Weiß der Lexer oder der Interpreter welches das letzte analysierte Token ist? (Parser(?))
     
     */
    
    
    
    Parser* aparser = new Parser(); //Testing parser with lexer generated vectorinput (works)
    if (!tokenarray.empty()) {
        cout << "ParserTestOutputs:" << endl;
        aparser->startParsing(tokenarray);
    }
    //Parser works with Tokens now and simple grammar(tracer bullet code)
    //Works with variables too, but variables cannot be defined by inputstring
    //Can now define variables in the code, but code design is still kind of messy
    
    
    Messing stuff;
    //stuff.startStuff();  //used for testing purposes (includes pointer operations) 
    
    return 0;
}

