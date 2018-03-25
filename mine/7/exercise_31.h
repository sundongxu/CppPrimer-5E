#ifndef EXERCISE_31_H
#define EXERCISE_31_H

class X
{
    Y *y = nullptr; // 指针成员最好被初始化为0或nullptr或NULL(stddef.h)
};

class Y
{
    X x;
};

#endif