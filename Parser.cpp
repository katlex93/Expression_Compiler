/**
 * E → T { (+|-) T }
T → F { (*|/) F }
F → number | identifier
 */
#include "Parser.h"
#include <iostream>

Parser::Parser(const std::vector<Lexer::tokensStructure>& _tokens)
    :tokens(_tokens),
     position{0},
     nextToken(_tokens.empty() ? Lexer::tokensStructure{} : tokens[0])
{
}
//debug
void Parser::printTree(Node* node, int depth){
    if (node == nullptr)
        return;

    for (int i = 0; i < depth; i++)
        std::cout << "  " ;

    std::cout << node->value << std::endl;

    printTree(node->left, depth + 1);
    printTree(node->right, depth + 1);
}

Node* Parser::buildAST(){
    return parseE();   
}
void Parser::scanToken(){
     position++;
    if(position < tokens.size()){
        nextToken = tokens[position];
    }
}
Node* Parser::parseE(){
    Node* a = parseT();

    while(true){
        if(nextToken.key == Lexer::tokenType::PLUS){
        scanToken();
        Node* b = parseT();
        a = new Node("+", a, b);
    }
    else if(nextToken.key == Lexer::tokenType::MINUS){
        scanToken();
        Node* b = parseT();
        a = new Node("-", a, b);
    }
    else{
        return a;
    }}
}

Node* Parser::parseT(){
    Node* a = parseF();

    while(true){
        if(nextToken.key == Lexer::tokenType::MULTIPLY){
        scanToken();
        Node* b = parseF();
        a = new Node("*", a, b);
    }
    else if(nextToken.key == Lexer::tokenType::DIVIDE){
        scanToken();
        Node* b = parseF();
        a = new Node("/", a, b);
    }else {
        return a;
    }}
}
Node* Parser::parseF(){
    if(nextToken.key == Lexer::tokenType::ID || 
        nextToken.key == Lexer::tokenType::NUM)
    {
        Node* node = new Node(nextToken.value, nullptr, nullptr);
        scanToken();
        return node;
    }
    return nullptr;
    
}

/**
 * 
unary minus
parentheses precedence
syntax errors
AST evaluation
print statement handling
 */
   