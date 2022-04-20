#pragma once

#include <iostream>

struct Date
{
	int Day, Month, Year;
};

void Input(Date&);

void Output(Date);

Date NextDay(Date);

void Date_Program();