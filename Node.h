#pragma once
#include <string>
#include "Lexer.h"

struct Node{
    Lexer::tokenType key;
    std::string value;

    Node* left;
    Node* right;
    Node* next;

    Node(Lexer::tokenType _key, const std::string& _value, Node* _left, Node* _right );
};
//Later upgrade to key value pairs