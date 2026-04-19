#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Node.h"
#include "CodeGen.h"

int main(){ 
    std::string input = "y = 7; x = 4 + y ; print y;  x = y; ";
    Lexer lexer(input);
    lexer.runLexer();
    // lexer.printVector();

    Parser parser(lexer.tokens);
    // Node* tree = parser.buildAST();
    Node* tree = parser.buildAST2();
    // parser.printTree(tree);

    CodeGen codeGenerate(tree);
    codeGenerate.genProgramm();

    return 0;
}

//Next steps
/**
 * Next steps
 * Handle =, ( ) , ; unsigned int space etc 
 * in both Lexer and Parser
 * fix Nodes to store key value pairs
 */