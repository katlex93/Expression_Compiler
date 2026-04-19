#include "Node.h"

Node::Node(Lexer::tokenType _key, const std::string& _value, Node* _left, Node* _right)
    : key (_key),
    value(_value),
    left(_left),
    right(_right),
    next(nullptr)
{
}
