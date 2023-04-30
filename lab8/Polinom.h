#ifndef POLINOM_H
#define POLINOM_H
#include "Member.h"

#define SIZE 500

class Polinom {
		Member m_Memb[SIZE];
		int m_Count;
public:
		Polinom(): m_Count(0) {}
		void Add(Member Mem);
		void Add(long double K, int Pow);
		Polinom operator*(const Polinom& Second);
		Polinom operator+(const Polinom& Second);
		Polinom operator/(long double D);
		Polinom operator*(long double D);
		long double operator()(long double D);
		friend ostream& operator<<(ostream& out, const Polinom P);
		void CutDown();
		void SORT();

};


#endif // !POLINOM_H
