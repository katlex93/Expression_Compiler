#include <iostream>
#include <string>
#include <queue>
#include <vector>


  void handleToken(std::string& current, std::queue<std::string>& tokens, char character){
            std::string ch (1, character);
            if(current != ""){
                    tokens.push(current);
                    current= "";
                }
            
            tokens.push(ch);
            
    };

int main(){
    std::string testinput = "int x= 5; int y = 2 + x";

    std::string current = ""; //to build string
    std::queue<std::string> tokens; //store strings

    //Scan the input and divide into strings
        for(auto &ch : testinput){
        switch(ch){

            case ' ':
            if(current == "") break;
            tokens.push(current);
            current= "";
            break;

            case '+':   
            case '-':
            case '*':
            case '/':
            case '=':
            case ';':
            case ')':
            case '(':
                handleToken(current, tokens, ch);
                break;
            default:
            current += ch;
        }
    };
    //Handle last token in case if finished without ;
    if(current != ""){
        tokens.push(current);
    }



    // //Test output
    // while(!tokens.empty()){
    //     std::cout << tokens.front() << "\n";
    //     tokens.pop();
    // }

    //Types of data
    /**
     * identifier
     * type - int, float
     * number
     * operand (aithmetic)
     * end line
     * assign
     */
    enum tokeType {
        ID,
        TYPE,
        NUM,
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        ASSIGN,
        ENDL
    };

   struct tokensStruct{
        tokeType key;
        std::string value;
   };

   std::vector<tokensStruct>tokensVector;
     
    //To vector as key value pairs
    while(!tokens.empty()){
        if(tokens.front() == "+"){
            tokensVector.push_back({PLUS, "+"});
        }
        else  if(tokens.front() == "-"){
            tokensVector.push_back({MINUS, "-"});
        }
        else  if(tokens.front() == "*"){
            tokensVector.push_back({MULTIPLY, "*"});
        }
        else  if(tokens.front() == "/"){
            tokensVector.push_back({DIVIDE, "/"});
        }
        else  if(tokens.front() == "="){
            tokensVector.push_back({ASSIGN, "="});
        }
         else  if(tokens.front() == ";"){
            tokensVector.push_back({ENDL, ";"});
        }
        else  if(std::isdigit(tokens.front()[0])){
            tokensVector.push_back({NUM, tokens.front()});
        }
        else  {
            tokensVector.push_back({ID, tokens.front()});
        }
        tokens.pop();
    }



for (auto  i : tokensVector) {

    std::cout<< "<"<< i.key << " " << i.value << ">" << "\n";
}

    
}