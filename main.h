//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Header file for PG3.cpp
//

#ifndef PG3_h
#define PG3_h

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]);
void GetMaze (int r, int c);
void DisposeMaze ();
void PrintMaze2 (char **M);
int height ();
int width ();
void Solve ();

#endif /* PG3_h */
