//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Header file for QObj.cpp
//
//

#ifndef QObj_hpp
#define QObj_hpp

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class QObj {

 private:
    int r;
    int c;
  char **M;
 public:
  QObj (int R, int C, char **MZ);
  ~QObj ();
  int getr();
  int getc();
  char ** getM();
};


#endif /* QObj_hpp */
