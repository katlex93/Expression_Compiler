#pragma once
#include <string>
#include <vector>
#include "Node.h"
#include "Lexer.h"

class Parser{
    public:
    Parser(const std::vector<Lexer::tokensStructure>& _tokens);
    Node* buildAST();
    void printTree(Node* node, int depth = 0);

    //New version
    Node* buildAST2();


    private:
    std::vector<Lexer::tokensStructure> tokens;
    int position;
    Lexer::tokensStructure nextToken;
    void scanToken();
    Node* parseE();
    Node* parseT();
    Node* parseF();

    //New addons
    Node* parseSL();
    Node* parseS();
    Node* parseID();
    Node* parsePrint();

    
};