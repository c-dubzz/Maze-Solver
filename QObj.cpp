//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Handles all methods relating to the QObj
//

#include <iostream>
#include <string>
#include <cstdlib>
#include "QObj.hpp"
#include "PG3.h"
using namespace std;

QObj::QObj (int R, int C, char **MZ) {
    
    // Creates a R x C maze

 r = R;
 c = C;
 M = new char*[height()];
 for (int i=0; i < height(); i++) {
  M[i] = new char[width()];
  for (int j=0; j < width(); j++)
   M[i][j] = MZ[i][j];
 }
}

QObj::~QObj() {
    
    //destructor method

 for (int i=0; i < height(); i++)
  delete M[i];
 delete M;
}

int QObj::getr () {
    

 return r;
}

int QObj::getc () {

 return c;
}

char ** QObj::getM () {

 return M;
}
