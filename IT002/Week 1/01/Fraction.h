#pragma once

#include <iostream>

typedef struct PhanSo
{
	int TuSo, MauSo;
}PS;

void Input(PhanSo&);

void Input(PhanSo&, PhanSo&);

void Output(PhanSo);

void reduceFrac(PhanSo&);

PhanSo MAX(PhanSo, PhanSo);

PS add(PS, PS);

PS subtract(PS, PS);

PS multiply(PS, PS);

PS divide(PS, PS);

void Fraction_Program();