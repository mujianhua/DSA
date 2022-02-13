//
// Created by mujianhua on 2022/1/20.
//
#ifndef POSITION_H_
#define POSITION_H_

struct position {
    int row, col;

    operator int() const { return row; }
};

#endif

