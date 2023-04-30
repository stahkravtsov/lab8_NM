#include <iostream>
#include <algorithm>
#include "Polinom.h"
#include "Member.h"
#include "lab8.h"

using namespace std;
#define LEN 10

int main() {

		long double x[] = { 0.15, .16, .17, .18, .19, .20, .21,.22,.23,.24 };
		long double y[] = { 4.48, 4.95, 5.47, 5.99, 6.05, 6.68, 6.909, 7.38, 8.166, 9.025 };

		//long double x[] = { 1.340, 1.345, 1.350, 1.360, 1.365, 1.370, 1.375, 1.380, 1.385, 1.390 };
		//long double y[] = { 4.26, 4.35, 4.46, 4.56, 4.67, 4.79, 4.91, 5.01, 5.18, 5.31 };

		//long double x[] = { 1, 2, 3 };
		//long double y[] = { 10, 15, 12 };
		MakeTable(x, y);
		Polinom pAnswer = Lagrange(x, y);
		long double dAnswer = 0, x0 = 0.153;

		cout << "Lagrange`s Polinom" << endl <<"P(X) = " << pAnswer << endl;
		cout << "P(" << x0 << ") = " << pAnswer(x0) << endl << endl;

		
		Polinom pAnswerNewton = Newton(x, y);
		cout << "Newton`s Polinom:" << endl << "P(X) = " << pAnswerNewton << endl;
		cout << "P(" << x0 << ") = " << pAnswerNewton(x0) << endl << endl;
		return 0;
}
