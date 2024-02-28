#include "Deque.h"

Deque::Deque(Deque const& qu) :n(qu.n), b(qu.b), e(qu.e) 
{
	q = new float[n];
	for (int i = b; i != e; i = (i + 1) % n)
		q[i] = qu.q[i];
}
Deque::Deque(std::initializer_list<int> iList)
{
	n = 2 * iList.size() - 1;
	q = new float[n];
	b = e = 0;
	for (int x : iList) { 
		PushBack(x); 
	}
}

Deque& Deque::operator = (Deque const& aQu)  
{
	if (this != &aQu)
	{
		Deque t(aQu);
		Swap(t);
	}
	return *this;
}

std::ostream& operator << (std::ostream& os, Deque const& aQu)
{
	std::string delim = "";
	os << '[';
	for (int i = aQu.b; i != aQu.e; i = (i + 1) % aQu.n)
	{
		os << delim.c_str() << aQu.q[i];
		delim = ",";
	}
	os << ']';
	return os;
}



