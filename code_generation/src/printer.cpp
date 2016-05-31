#include "ast.h"

using namespace AST;


/* Print methods */
void Integer::printTree(){
    std::cout << value;
    return;
}

void BinOp::printTree(){
    left->printTree();
    switch(op){
        case plus: std::cout << " + "; break;
        case times: std::cout << " * "; break;
        default:
        case assign: std::cout << " = "; break;
    }
    right->printTree();
    return;
}

void Variable::printTree(){
    std::cout << id;
}

void Block::printTree(){
    for (Node* line: lines) {
        line->printTree();
        std::cout << std::endl;
    }
}

///* Compute methods */
//int Integer::computeTree(){
//    return value;
//}
//
//int BinOp::computeTree(){
//    int value, lvalue, rvalue;
//    lvalue = left->computeTree();
//    rvalue = right->computeTree();
//    switch(op){
//        case plus: value = lvalue + rvalue; break;
//        case times: value = lvalue * rvalue; break;
//        //case assign:
//        //    //assignments require data from the symbol table
//        //    Variable* leftvar = dynamic_cast<Variable*>(left);
//        //    symtab.entryList[leftvar->id].value = rvalue;
//        //    value = rvalue;
//    }
//    return value;
//}
//
//int Block::computeTree(){
//    int value;
//    for (Node* line: lines) {
//        value = line->computeTree();
//         std::cout << "Computed " << value << std::endl;
//    }
//    return 0;
//}

//int Variable::computeTree(){
//    //the value of a variable is currently stored in the symbol table
//    return symtab.entryList[id].value;
//}


