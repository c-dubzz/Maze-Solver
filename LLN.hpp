//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Header file for LLN.cpp
//
//

#ifndef LLN_hpp
#define LLN_hpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.hpp"
using namespace std;

class QObj;
class LLN {

 private:
  QObj * info;
  LLN * next;
 public:
  LLN (QObj * obj);
  ~LLN ();
  LLN * getnext ();
  QObj * getinfo ();
  void setnext (LLN *n);
  void setinfo (QObj * obj);
};

#endif /* LLN_hpp */
