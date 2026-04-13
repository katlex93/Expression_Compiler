#include "Lexer.h"
#include <iostream>
#include <cctype>


//constract
Lexer::Lexer(std::string _input)
    :input(_input)
{
   

}

void Lexer::runLexer(){
    tokens.clear();
    std::string current = ""; //to build string
    if(input.empty()){
        std::cerr << "Error: Empty input.\n";
        return;
    };

    for(auto &ch : input){
        if(std::isspace(ch)){
            pushBackCurrent(current);
            continue;
        }
        switch(ch){
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
        case '(':
            pushBackCurrent(current);
            tokens.push_back({tokenType::LPARENTHESIS, "("});
            break;
        case ')':
            pushBackCurrent(current);
            tokens.push_back({tokenType::RPARENTHESIS, ")"});
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

    if(current == "print"){
        tokens.push_back({tokenType::PRINT, current});
    }
    else if(isNum(current)){
        tokens.push_back({tokenType::NUM, current});
    }
    else if(isId(current)){
            tokens.push_back({tokenType::ID, current});
    }
    else{
        std::cerr<<"Error: Invalid token: "
                 << current
                 << "\n";
    }
    current = "";
}

 bool Lexer::isNum(const std::string& string){
    for(auto& c: string){
        if(!std::isdigit(c)){
            return false;
        }
    }
    return true;
 }

 bool Lexer::isId(const std::string& string){
    //check if first digit A-Z || a-z
    if(!std::isalpha(string[0])){  
        return false;
    };

    //ID can't constis of symbols
    //only A-Z, a-z, 0-9.
    for(auto& c: string){
        if(!std::isalnum(c) && c != '_'){
            return false;
        }
    }
    return true;
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
//empty input ✅
//number checking ✅
//identifier checking✅
//whitespace handling ✅
//invalid-token handling✅ 
//handle ( )✅