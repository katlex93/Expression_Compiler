#pragma once

#include <string>
#include <vector>

class Lexer{
    public:
    Lexer(std::string input);
   

    //enum types of tokens
    enum class tokenType {
        ID,
        NUM,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        ASSIGN,
        LPARENTHESIS,
        RPARENTHESIS,
        PRINT,
        ENDL
    };
    //strutc of token
     struct tokensStructure{
        tokenType key;
        std::string value;
   };
    //vector
    std::vector<tokensStructure>tokens;
    void runLexer(); //tokenize

    //debug- print vector
    void printVector();


    private:
    std::string input;
    //helper functions
    void pushBackCurrent(std::string& current);
    bool isNum(const std::string& string);
    bool isId(const std::string& string);
    
};