//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Handles all methods relating to the LLN's
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.hpp"
#include "LLN.hpp"
using namespace std;

LLN::LLN (QObj *obj) {
    
    // Each node has a "next" of type LLN and "info" of type QObj

 info = obj;
 next = nullptr;
}

LLN::~LLN () {
    
    // destructor method

 delete info;
 delete next;
}

QObj * LLN::getinfo () {
    
    // returns info, of type QObj

 return info;
}

void LLN::setinfo (QObj * obj) {
    
    //sets the info of a LLN to "obj"

 info = obj;
}

LLN * LLN::getnext () {
    
    //returns next node

 return next;
}

void LLN::setnext (LLN * n) {
    
    //sets next node as "n"

 next = n;
}
