#pragma once
#include <iostream>

typedef struct PhanSo
{
	int TuSo, MauSo;
}PS;

void Input(PhanSo&);

void Output(PhanSo);

PS add(PS, PS);

PS subtract(PS, PS);

PS multiply(PS, PS);

PS divide(PS, PS);