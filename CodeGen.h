#pragma once
#include "Node.h"
#include <fstream>

class CodeGen{
    public:
    CodeGen(Node* _root);
    void genProgramm();

    private:
    Node* root;
    std::ofstream output;
    void genStatement(Node* node);
    void genExpression(Node* node);
};