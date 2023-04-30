#include "Polinom.h"
#include <algorithm>

void Polinom::Add(Member Mem) {
		m_Memb[m_Count] = Mem;
		m_Count++;
		return;
}

void Polinom::Add(long double K, int Pow) {
		Member Mem(K, Pow);
		m_Memb[m_Count] = Mem;
		m_Count++;
		return;
}

Polinom Polinom::operator*(const Polinom& Second) {
		Polinom NewP;
		for(int i = 0; i < m_Count; i++) {
				for(int j = 0; j < Second.m_Count; j++) {
						NewP.Add(m_Memb[i] * Second.m_Memb[j]);
				}
		}
		for(int i = 0; i < NewP.m_Count; i++) {
				for(int j = i + 1; j < NewP.m_Count; j++) {
						if(NewP.m_Memb[i] == NewP.m_Memb[j]) {
								NewP.m_Memb[i] += NewP.m_Memb[j];
								NewP.m_Memb[j] = Member(0, 0);
						}
				}
		}
		Polinom SecondNewP;
		for(int i = 0; i < NewP.m_Count; i++) {
				if(NewP.m_Memb[i].GetK() != 0) SecondNewP.Add(NewP.m_Memb[i]);
		}
		NewP.CutDown();
		*this = NewP;
		return NewP;
}

void Polinom::CutDown() {

		for(int i = 0; i < m_Count; i++) {
				for(int j = i + 1; j < m_Count; j++) {
						if(m_Memb[i] == m_Memb[j]) {
								m_Memb[i] += m_Memb[j];
								m_Memb[j] = Member(0, 0);
						}
				}
		}
		Polinom NewP;
		for(int i = 0; i < m_Count; i++) {
				if(m_Memb[i].GetK() != 0) NewP.Add(m_Memb[i]);
		}
		*this = NewP;
}


Polinom Polinom::operator+(const Polinom& Second) {
		Polinom NewP;
		for(int i = 0; i < m_Count; i++) {
				NewP.Add(m_Memb[i]);
		}
		for(int i = 0; i < Second.m_Count; i++) {
				NewP.Add(Second.m_Memb[i]);
		}
		NewP.CutDown();
		return NewP;
}

Polinom Polinom::operator/(long double D) {

		for(int i = 0; i < m_Count; i++) {
				m_Memb[i] /= D;
		}
		return *this;
}

Polinom Polinom::operator*(long double D) {

		for(int i = 0; i < m_Count; i++) {
				m_Memb[i] *= D;
		}
		return *this;
}

long double Polinom::operator()(long double D) {
		long double Ans = 0;
		for(int i = 0; i < m_Count; i++) {

				Ans += (m_Memb[i])(D);
			//	cout<<i<<")   "<< Ans << "  +=  " << ( m_Memb[i] )( D ) << endl;
		}
		return Ans;
}


ostream& operator<<(ostream& out, const Polinom P) {

		for(int i = 0; i < P.m_Count - 1; i++) {
				out << P.m_Memb[i] << " + ";
		}
		out << P.m_Memb[P.m_Count - 1] << endl;
		return out;
}

void Polinom::SORT() {
		sort(m_Memb, m_Memb + m_Count, Compare);

}
