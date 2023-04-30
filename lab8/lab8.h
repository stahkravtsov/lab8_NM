#ifndef LAB8_H
#define LAB8_H
#include "Polinom.h"

long double Diferent(int i, int j, long double x[], long double y[]);

void MakeTable(long double x[], long double y[]);

Polinom Lagrange(long double x[], long double y[]);

Polinom Newton(long double x[], long double y[]);

#endif // !LAB8_H
