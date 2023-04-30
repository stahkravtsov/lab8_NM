#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
using namespace std;

class Member {
		long double m_K;
		int m_Pow;
public:
		Member(): m_K(0.), m_Pow(0) {}
		Member(long double K, int Pow): m_K(K), m_Pow(Pow) {}
		Member operator*(const Member& Second);
		Member operator+(const Member& Second);
		void operator+=(const Member& Second);
		void operator/=(long double D);
		void operator*=(long double D);
		long double operator()(long double D);
		Member operator-(const Member& Second);
		bool operator==(const Member& Second);
		friend ostream& operator<<(ostream& out, const Member M);
		friend bool Compare(Member First, Member Second);

		long double GetK();
};

		bool Compare(Member First, Member Second);


#endif // !MEMBER_H
