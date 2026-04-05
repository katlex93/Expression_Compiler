#include <iostream>
#include "Lexer.h"

int main(){
    std::string input ="x=5; y=x+2";
    Lexer lexer(input);
    lexer.runLexer();
    lexer.printVector();


    return 0;
}