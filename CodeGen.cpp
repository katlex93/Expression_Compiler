#include "CodeGen.h"
#include "Node.h"
#include "Lexer.h"
#include <fstream>

CodeGen::CodeGen(Node* _root)
    : root (_root),
    output("output.asm")
    {
    }

void CodeGen::genProgramm(){
    //Check this later
    // output << "global _start\n\n";
    // output << "section .data\n";

    Node* current = root;
    while(current != nullptr){
        genStatement(current);
        current = current -> next;
    }

}

void CodeGen::genStatement(Node* node){
    if(node->key == Lexer::tokenType::ASSIGN){
        genExpression(node->right); //evaluate right side
        output << "mov [" << node->left-> value <<"], rax\n"; //store variable in register
    }else if(node->key == Lexer::tokenType::PRINT){
        genExpression(node->right); //evaluate right side
        output << "call print_int\n";
    }

}

void CodeGen::genExpression(Node* node){
    if(node == nullptr) return;

    if(node->key == Lexer::tokenType::NUM){
        output << "mov rax, " << node-> value <<"\n";
    }
    else if(node->key == Lexer::tokenType::ID){
        output << "mov rax, [" << node-> value <<"]\n";
    }  

    //else if assignment
    //else if print
    else{
        genExpression(node->left);
        output << "push rax\n";
        genExpression(node->right);
        output << "pop rbx\n";  
        
        //Arithmetics
        if(node->key == Lexer::tokenType::PLUS){
            output << "add rax, rbx\n";
        }
        else if(node->key == Lexer::tokenType::MINUS){
            output << "sub rax, rbx\n";
        }
        else if(node->key == Lexer::tokenType::MULTIPLY){
            output << "imul rax, rbx\n";
        }
        else if(node->key == Lexer::tokenType::DIVIDE){
            output << "cqo\n"; //CHECK THIS
            output << "idiv rbx\n";
        }
    }
}

