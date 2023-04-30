#include "lab8.h"
#define LEN 10

long double Diferent(int i, int j, long double x[], long double y[]) {
		if(i == j) {
				return y[i];
		}

		long double Ans = ( Diferent(i, j + 1, x, y) - Diferent(i - 1, j, x, y) ) / ( x[i] - x[j] );

		return Ans;
}

void MakeTable(long double x[], long double y[]) {
		for(int i = 0; i < 85; i++) {
				cout << "-";
		}
		cout << endl;
		cout << "| x" << " | ";
		for(int i = 0; i < 10; i++) {
				cout.width(5);
				cout << x[i] << " | ";
		}
		cout << endl;
		for(int i = 0; i < 85; i++) {
				cout << "-";
		}
		cout << endl;
		cout << "| y" << " | ";

		for(int i = 0; i < 10; i++) {
				cout.width(5);
				cout << y[i] << " | ";
		}
		cout << endl;
		for(int i = 0; i < 85; i++) {
				cout << "-";
		}
		cout << endl;
}

Polinom Lagrange(long double x[], long double y[]) {

		Polinom pAnswer;
		long double dAnswer = 0, x0 = 0.153;
		pAnswer.Add(0, 0);
		for(int i = 0; i < LEN; i++) {
				Polinom pTop;
				pTop.Add(1, 0);
				long double dDown = 1, dTemp = 1;
				for(int j = 0; j < LEN; j++) {
						if(i != j) {
								//dTemp *= ( x0 - x[j] );
								Polinom Temp;
								Temp.Add(1, 1);
								long double t(-x[j]);
								Temp.Add(t, 0);
								pTop* Temp;
								dDown *= ( x[i] - x[j] );
						}
				}

				dAnswer += ( dTemp / dDown * y[i] );
				pTop* y[i];
				pAnswer = pAnswer + ( pTop / dDown );
		}
		pAnswer.SORT();
		return pAnswer;
}

Polinom Newton(long double x[], long double y[]) {
		Polinom pAnswerNewton;
		long double dAnswerNewton = 0;
		pAnswerNewton.Add(y[0], 0);
		for(int i = 1; i < LEN; i++) {
				Polinom pTop;
				pTop.Add(1, 0);
				long double dTemp = 1;
				for(int j = 0; j < i; j++) {
						Polinom Temp;
						Temp.Add(1, 1);
						long double t(-x[j]);
						Temp.Add(t, 0);
						pTop* Temp;
				}
				long double dDif = Diferent(i, 0, x, y);
				pTop* dDif;
				dAnswerNewton += dTemp * dDif;
				pAnswerNewton = pAnswerNewton + pTop;
		}
		return pAnswerNewton;
}
