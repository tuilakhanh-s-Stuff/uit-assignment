#pragma once

#include <iostream>

struct Student
{
    char HoTen[100];
    int Toan, Van;
    float DTB;
};

void Input(Student&);

void Output(Student);