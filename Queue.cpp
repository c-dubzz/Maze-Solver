//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Handles all methods relating to the Queue 
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "Queue.hpp"
#include "LLN.hpp"
#include "QObj.hpp"
using namespace std;

Queue::Queue () {
    
    // Each Queue has a head

 head = nullptr;
}

Queue::~Queue () {

    //destructor method
    
 delete head;
}

void Queue::ENQUEUE (QObj *obj) {
    
    // Enqueues "obj" into the Queue

 if (!head) head = tail = new LLN (obj);
 else {
  tail->setnext (new LLN (obj));
  tail = tail->getnext();
 }
}

QObj * Queue::DEQUEUE () {
    
    // Dequeues an item from the Queue

 if (!head) return nullptr;
 QObj * obj = head->getinfo ();
 LLN *t = head;
 head = head->getnext();
 t->setnext (nullptr);
 t->setinfo (nullptr);
 delete t;
 return obj;
}

bool Queue::EMPTY () {
    
    //returns true if the Queue is empty

 return !head;
}
