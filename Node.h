#pragma once
#include <string>

struct Node{
    std::string value;
    Node* left;
    Node* right;

    Node(const std::string& _value, Node* _left, Node* _right);
};
//Later upgrade to key value pairs