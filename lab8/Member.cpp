#include "Member.h"

Member Member::operator*(const Member& Second) {
		return Member(m_K * Second.m_K, m_Pow + Second.m_Pow);
}

Member Member::operator+(const Member& Second) {
		if(m_Pow != m_Pow) {
				cout << "NO KURVAAAA";
				return *this;
		}
		return Member(m_K + Second.m_K, m_Pow);

}

void Member::operator+=(const Member& Second) {
		if(m_Pow != m_Pow) {
				cout << "NO KURVAAAA";
				return;
		} else {
				m_K += Second.m_K;
				return;
		}

}

void Member::operator/=(long double D) {
		if(m_K == 0) {
				cout << "NO KURVAAAA";
				return;
		} else {
				m_K /= D;
				return;
		}

}

void Member::operator*=(long double D) {
		if(m_K == 0) {
				cout << "NO KURVAAAA";
				return;
		} else {
				m_K *= D;
				return;
		}

}

long double Member::operator()(long double D) {
		long double Ans = 1;
		for(int i = 0; i < m_Pow; i++) {
				Ans *= D;
		}
		Ans *= m_K;
		return Ans;
}

Member Member::operator-(const Member& Second) {
		if(m_Pow != m_Pow) {
				cout << "NO KURVAAAA";
				return *this;
		}
		return Member(m_K - Second.m_K, m_Pow);

}

bool Member::operator==(const Member& Second) {
		if(m_Pow == Second.m_Pow) return 1;
		return 0;
}

ostream& operator<<(ostream& out, const Member M) {
		if(M.m_K == 0) return out;
		if(M.m_K != 1) out << "(" << M.m_K << ")";
		if(M.m_K == 1 && M.m_Pow == 0) out << "1";

		if(M.m_Pow != 0) {

				out << "X^" << "" << M.m_Pow << " ";
		}
		return out;
}

long double Member::GetK() {
		return m_K;
}

bool Compare(Member First, Member Second) {
		if(First.m_Pow > Second.m_Pow) return 0;
		return 1;
}
