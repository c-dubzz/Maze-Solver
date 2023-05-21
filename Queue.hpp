//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Header file for Queue.cpp
//
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.hpp"
#include "QObj.hpp"
using namespace std;

class LLN;
class Queue {

 private:
  LLN * head, *tail;
 public:
  Queue ();
  ~Queue ();
  void ENQUEUE (QObj *obj);
  QObj * DEQUEUE ();
  bool EMPTY ();
};

#endif
