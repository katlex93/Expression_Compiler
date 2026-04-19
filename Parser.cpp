/**
 * //adding statments  S - statement SL Statment list
 * programm → SL
 * SL → S {; S}
 * S → ID = E | PRINT E
 * E → T { (+|-) T }
T → F { (*|/) F }
F → number | identifier | -F |(E)

FIXED 
 * programm → SL
 * SL → {S}
 * S → ID = E; | PRINT E;
 * E → T { (+|-) T }
T → F { (*|/) F }
F → number | identifier | -F |(E)
 */
#include "Parser.h"
#include <iostream>
#include "Lexer.h"

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

    printTree(node-> next, depth);
}
//New version of AST
Node* Parser::buildAST2(){
    return parseSL();
}
/**

 */
Node* Parser::parseSL(){
 Node* root = nullptr;
 Node* current = nullptr;

 while(position < tokens.size()){
    Node* statement = parseS();
    if(statement == nullptr){
        std::cerr << "Syntax error\n";
        return nullptr;
    }

    if(root == nullptr){
        root= statement;
        current = statement; 
    }else {
        current -> next = statement;
        current = statement;
    }
    
 }
 return root;
}

Node* Parser::parseS(){
    if(nextToken.key == Lexer::tokenType::ID){
        Node* a = parseID();
        if(nextToken.key != Lexer::tokenType::ASSIGN){
            std::cerr << "Error, = expected\n";
            return nullptr;
        }
        scanToken();
        Node* b = parseE();
        if(nextToken.key != Lexer::tokenType::ENDL){
            std::cerr << "Error, ; expected\n";
            return nullptr;
        }
        scanToken();
        a = new Node(Lexer::tokenType::ASSIGN, "=", a , b);
        return a;
        
    }
    else if(nextToken.key == Lexer::tokenType::PRINT){
        scanToken();
        Node* b = parseE();
        if (nextToken.key != Lexer::tokenType::ENDL){
            std::cerr << "Error, ; expected\n";
            return nullptr;
        }
        scanToken();

        return new Node(Lexer::tokenType::PRINT,"print", nullptr, b);
        

    }

    return nullptr;


};


Node* Parser::parseID(){
    Node* node = new Node(nextToken.key, nextToken.value, nullptr, nullptr);
    scanToken();
    return node;
};


//Old version of AST
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
        a = new Node(Lexer::tokenType::PLUS , "+", a, b);
    }
    else if(nextToken.key == Lexer::tokenType::MINUS){
        scanToken();
        Node* b = parseT();
        a = new Node(Lexer::tokenType::MINUS ,"-", a, b);
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
        a = new Node(Lexer::tokenType::MULTIPLY ,"*", a, b);
    }
    else if(nextToken.key == Lexer::tokenType::DIVIDE){
        scanToken();
        Node* b = parseF();
        a = new Node(Lexer::tokenType::DIVIDE, "/", a, b);
    }else {
        return a;
    }}
}
Node* Parser::parseF(){
    if(nextToken.key == Lexer::tokenType::ID || 
        nextToken.key == Lexer::tokenType::NUM)
    {
        Node* node = new Node(nextToken.key, nextToken.value, nullptr, nullptr);
        scanToken();
        return node;
    }
    else if(nextToken.key == Lexer::tokenType::LPARENTHESIS){
        scanToken();
        Node* a = parseE(); //check
        if(a == nullptr) return nullptr;

        if(nextToken.key == Lexer::tokenType::RPARENTHESIS){
            scanToken();
            return a;
        }
        std::cerr << "Error: ')' expected \n";
        return nullptr;
    
    }
    //check this 
    else if(nextToken.key == Lexer::tokenType::MINUS){
        scanToken();
        Node* a = parseF();
        if( a == nullptr) return nullptr;
        return new Node(Lexer::tokenType::MINUS, "-", nullptr, a);
    }
    return nullptr;
    
}

/**
 * 
unary minus
handle assignment 
handle ;
parentheses precedence
syntax errors
AST evaluation
print statement handling
 */
   