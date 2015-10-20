#ifndef _T_ARRAY_
#define _T_ARRAY_

template<class T>
class CTArray
{
private:

	T *m_Array;
	int _length;
public:
	CTArray();
	CTArray(const CTArray &a);
	CTArray(T *Array, int Length);
	void InputArray();
	void OutputArray();
	CTArray Remove();
	CTArray Remove(int);
	CTArray Remove(int, int);
	CTArray Replace(T, T);
	CTArray AddHead(T);
	CTArray AddTail(T);
	CTArray Insert(T, int);
	T Max();
	T Min();
	CTArray Ascending();
	CTArray Descending();
	bool IsSymmetry();
	CTArray MoveForward();
	CTArray MoveForward(int n);
	CTArray MoveBehind();
	CTArray MoveBehind(int n);
	CTArray Invert();
	int Appearance(T k);
	~CTArray();
};
#endif
