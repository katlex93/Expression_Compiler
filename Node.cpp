#include "Node.h"

Node::Node(const std::string& _value, Node* _left, Node* _right)
    :value(_value),
    left(_left),
    right(_right)
{
}
