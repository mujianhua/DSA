//
// Created by mujianhua on 2022/1/20.
//
#include <iostream>
#include "arrayStack.h"
#include "position.h"
#include "make2dArray.h"

int **maze, size;
arrayStack<position> *path;

void inputMaze() {
    std::cout << "Enter maze size" << '\n';
    std::cin >> size;
    make2dArray(maze, size + 2, size + 2);
    for (int i = 1; i <= size; i++)
        for (int j = 1; j <= size; j++)
            std::cin >> maze[i][j];
}

bool findPath() {
    path = new arrayStack<position>;
    position offset[4];
    offset[0].row = 0;
    offset[0].col = 1;//right
    offset[1].row = 1;
    offset[1].col = 0;// down
    offset[2].row = 0;
    offset[2].col = -1;// left
    offset[3].row = -1;
    offset[3].col = 0;// up

    for (int i = 0; i <= size + 1; i++) {
        maze[0][i] = maze[size + 1][i] = 1;
        maze[i][0] = maze[i][size + 1] = 1;
    }

    position here;
    here.row = 1;
    here.col = 1;
    maze[1][1] = 1;
    int option = 0;
    int lastOption = 3;

    while (here.row != size || here.col != size) {
        int r, c;
        while (option <= lastOption) {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0)
                break;
            option++;
        }
        if (option <= lastOption) {
            path->push(here);
            here.row = r;
            here.col = c;
            maze[r][c] = 1;
            option = 0;
        } else {
            if (path->empty())
                return false;
            position next = path->top();
            path->pop();
            if (next.row == here.row)
                option = 2 + next.col - here.col;
            else
                option = 3 + next.row - here.row;
            here = next;
        }
    }
    return true;
}

void outputPath() {
    std::cout << "The path is" << '\n';
    position here;
    while (!path->empty()) {
        here = path->top();
        path->pop();
        std::cout << here.row << ' ' << here.col << '\n';
    }
}
