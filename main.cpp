#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Node.h"

int main(){
    std::string input = "6* 2 - 4 * 2";
    Lexer lexer(input);
    lexer.runLexer();
    // lexer.printVector();

    Parser parser(lexer.tokens);
    Node* tree = parser.buildAST();
    parser.printTree(tree);

    return 0;
}

//Next steps
/**
 * Next steps
 * Handle =, ( ) , ; unsigned int space etc 
 * in both Lexer and Parser
 * fix Nodes to store key value pairs
 */