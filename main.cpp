//
//  AUTHOR: Cole Walgren
//  TITLE: Program 3
//  DESCRIPTION: Returns the shortest path from the start (top left corner)
//  to the finish (bottom right corner) of a maze entered by the user
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include "PG3.h"
#include "Queue.hpp"

using namespace std;

int w, h;
char **Maze;
QObj* coord;
Queue *Q;

int main(int argc, const char * argv[]) {
    
    //Ask user for dimensions
    cout << "Enter width of maze: "<<endl;
    cin >> h;
    cout << "Enter height: "<<endl;
    cin >> w;
    
    //create Maze board
    Maze = new char*[w];
    for(int i = 0; i < w; i++){
        Maze[i] = new char[h];
    }
    
    // user creates maze
    cout << "Create a maze below using the '*' and ' ' characters: " << endl;
    GetMaze(w, h);

    Solve();
    PrintMaze2(Maze);
    DisposeMaze();
    
    cout<<endl;

    return 0;
}

void GetMaze (int r, int c) {
    
    // create r x c maze that the user enters
    
    h = r;
    w = c;

    cin.ignore();
    char** M = new char * [r];
    string line;
    for(int i = 0; i < r; i++){
        M[i] = new char[c];
        getline(cin, line);
        for(int j = 0; j < c; j++){
            M[i][j] = line[j];
        }
    }
    Maze = M;
}

void DisposeMaze () {
    
    // memory deallocation

 for (int i=0; i < h; i++)
  delete[] Maze[i];
 delete[] Maze;
}

void PrintMaze2 (char **M) {
    
    // prints out maze "M"

        cout << "PATH FOUND: " << endl;
            for(int i = 0; i < h; i++){
                for(int k = 0; k < w; k++){
                    cout << M[i][k];
                }
                cout << endl;
            }
}

int height () {
 return h;
}

int width () {
 return w;
}

void Solve () {
    
        // Determines each path X is able to make in the maze and compares to determine which is the shortest one.
        // After each step, the maze is added to the queue to determine next route and then the memory is deallocated
    
        int r = 0;
        int c = 0;
        Maze[r][c] = 'X';
        Q = new Queue();
        Q->ENQUEUE(new QObj(r, c, Maze));
        
        while (!Q->EMPTY()) {
            QObj* currentM = Q->DEQUEUE();
            r = currentM->getr();
            c = currentM->getc();
            Maze = currentM->getM();
            if (r + 1 == h && c + 1 == w) {
                return;
            }
            if (r != 0) {
                if (Maze[r - 1][c] == ' ') {
                    char** newMaze = new char* [h];
                    for (int i = 0; i < h; i++) {
                        newMaze[i] = new char[w];
                        for (int j = 0; j < w; j++) {
                            newMaze[i][j] = Maze[i][j];
                        }
                    }
                    newMaze[r - 1][c] = 'X';
                    Q->ENQUEUE(new QObj(r - 1, c, newMaze));
                    delete[] newMaze;
                }
            }
            if (r != h - 1) {
                if (Maze[r + 1][c] == ' ') {
                    char** newMaze = new char*[h];
                    for (int i = 0; i < h; i++) {
                        newMaze[i] = new char[w];
                        for (int j = 0; j < w; j++) {
                            newMaze[i][j] = Maze[i][j];
                        }
                    }
                    newMaze[r + 1][c] = 'X';
                    Q->ENQUEUE(new QObj(r + 1, c, newMaze));
                    delete[] newMaze;
                }
            }
            if (c != 0) {
                if (Maze[r][c - 1] == ' ') {
                    char** newMaze = new char*[h];
                    for (int i = 0; i < h; i++) {
                        newMaze[i] = new char[w];
                        for (int j = 0; j < w; j++) {
                            newMaze[i][j] = Maze[i][j];
                        }
                    }
                    newMaze[r][c - 1] = 'X';
                    Q->ENQUEUE(new QObj(r, c - 1, newMaze));
                    delete[] newMaze;
                }
            }
            if (c != w - 1) {
                if (Maze[r][c + 1] == ' ') {
                    char** newMaze = new char* [h];
                    for (int i = 0; i < h; i++) {
                        newMaze[i] = new char[w];
                        for (int j = 0; j < w; j++) {
                            newMaze[i][j] = Maze[i][j];
                        }
                    }
                    newMaze[r][c + 1] = 'X';
                    Q->ENQUEUE(new QObj(r, c + 1, newMaze));
                    delete[] newMaze;
                }
            }
            delete currentM;
        }
        delete Q;
        DisposeMaze();
    }
