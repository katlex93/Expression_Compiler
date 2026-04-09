#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <string>

 struct Node {
    std::string value; //change this late to appropriate
    //pointer to children
    Node* left;
    Node* right;

    //constructor
    Node(std::string _value, Node* _left, Node* _right){
        value = _value;
        left = _left;
        right = _right;
    }
 };

void printTree(Node* node, int depth = 0) {
    if (node == nullptr)
        return;

    for (int i = 0; i < depth; i++)
        std::cout << "  " ;

    std::cout << node->value << std::endl;

    printTree(node->left, depth + 1);
    printTree(node->right, depth + 1);
};


class Parser{
    private:
    std::vector<std::string> tokens;
    int position;
    std::string nextToken;


    public:
    Parser(std::vector<std::string>& _tokens){
        tokens = _tokens;
        position = 0;
        nextToken =tokens[position];
    };
    

    void scanToken(){
        position++;
        if(position < tokens.size()){
            nextToken = tokens[position];
        }
    };

    Node* parseE(){
        Node* a = parseT();

        while(true){
            if(nextToken == "+"){
            scanToken();
            Node* b = parseT();
            a = new Node("+", a, b);
        }
        else if(nextToken == "-"){
            scanToken();
            Node* b = parseT();
            a = new Node("-", a, b);
        }
        else{
            return a;
        }}
    };

    Node* parseT(){
        Node* a = parseF();

        while(true){
            if(nextToken == "*"){
            scanToken();
            Node* b = parseF();
            a = new Node("*", a, b);
        }
        else if(nextToken == "/"){
            scanToken();
            Node* b = parseF();
            a = new Node("/", a, b);
        }else {
            return a;
        }}
    };
    Node* parseF(){ //have a look t that video later
        Node* node = new Node(nextToken, nullptr, nullptr);
        scanToken();
        return node;
    };

};






int main(){
    
 std::vector<std::string> test = {"5", "+", "2", "*", "3", ";"};

 Parser parser(test);
 Node* root = parser.parseE();

 printTree(root);

    
}