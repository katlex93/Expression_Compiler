#include "Lexer.h"
#include <iostream>


//constract
Lexer::Lexer(std::string _input)
    :input(_input)
{
   

}

void Lexer::runLexer(){
    tokens.clear();
    std::string current = ""; //to build string

    for(auto &ch : input){
        switch(ch){
        case ' ':
            pushBackCurrent(current);
            break;
        case '=':
            pushBackCurrent(current);
            tokens.push_back({tokenType::ASSIGN, "="});
            break;
         case '+':
            pushBackCurrent(current);
            tokens.push_back({tokenType::PLUS, "+"});
            break;
         case '-':
            pushBackCurrent(current);
            tokens.push_back({tokenType::MINUS, "-"});
            break;
        case '*':
            pushBackCurrent(current);
            tokens.push_back({tokenType::MULTIPLY, "*"});
            break;
         case '/':
            pushBackCurrent(current);
            tokens.push_back({tokenType::DIVIDE, "/"});
            break;
        case ';':
            pushBackCurrent(current);
            tokens.push_back({tokenType::ENDL, ";"});
            break;
        default:
            current += ch;
           
        }
    }

    //later on work on cases where last token can be +or- -error handle
    pushBackCurrent(current);

}

void Lexer::pushBackCurrent(std::string& current){
    if(current.empty()) return;
    
    if(std::isdigit(current[0])){
        tokens.push_back({tokenType::NUM, current});
    }
    else{
            tokens.push_back({tokenType::ID, current});
    }
    current = "";
}

void Lexer::printVector(){
 for(const auto& token : tokens){

        std::cout
            << static_cast<int>(token.key)
            << " : "
            << token.value
            << std::endl;
    }

}

//improve :
//number checking 
//identifier checking
//whitespace handling
//invalid-token handling