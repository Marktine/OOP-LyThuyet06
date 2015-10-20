#include "TArray.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

template class CTArray<int>;
template class CTArray<short>;
template class CTArray<long>;
template class CTArray<float>;
template class CTArray<double>;
template class CTArray<string>;
template class CTArray<char>;

template<class T>
CTArray<T>::CTArray()
{
	_length = 0;
	m_Array = new T[_length];
	for (int i = 0; i < _length; i++)
	{
		m_Array[i] = T();
	}
}

template<class T>
CTArray<T>::CTArray(const CTArray<T> &a)
{
	_length = a._length;
	m_Array = new T[_length];
	for (int i = 0; i < _length; i++)
	{
		m_Array[i] = a.m_Array[i];
	}
}

template<class T>
CTArray<T>::CTArray(T *Array, int Length)
{
	_length = Length;
	m_Array = new T[_length];
	for (int i = 0; i < _length; i++)
	{
		m_Array[i] = Array[i];
	}
}

template<typename T>
void CTArray<T>::InputArray()
{
	srand(time(NULL));
	cout << "Nhap vao so phan tu cua mang: ";
	cin >> _length;
	m_Array = new T[_length];
	for (int i = 0; i < _length; i++)
	{
		m_Array[i] = rand();
	}
}

template<typename T>
void CTArray<T>::OutputArray()
{
	for (int i = 0; i < this->_length; i++)
	{
		cout << "a[" << i << "]: " << this->m_Array[i] << endl;
	}
}

template<class T>
CTArray<T> CTArray<T>::Remove()
{
	for (int i = 0; i < this->_length; i++)
	{
		for (int j = i + 1; j < this->_length; j++)
		{
			if (this->m_Array[i] == this->m_Array[j])
			{
				int index = j;
				for (int k = index + 1; k < this->_length; k++)
				{
					this->m_Array[k - 1] = this->m_Array[k];
				}
				this->_length -= 1;
				i--;
			}
		}
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::Remove(int n)
{
	for (int i = n; i < this->_length - 1; i++)
	{
		this->m_Array[i] = this->m_Array[i + 1];
	}
	this->_length--;
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::Remove(int k, int n)
{
	for (int i = 0; i < n; i++)
	{
		this->Remove(k);
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::Replace(T old, T New)
{
	for (int i = 0; i < this->_length; i++)
	{
		if (this->m_Array[i] == old)
		{
			this->m_Array[i] = New;
		}
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::AddHead(T k)
{
	CTArray temp(*this);
	this->m_Array = new T[this->_length + 1];
	this->_length++;
	this->m_Array[0] = k;
	for (int i = 1; i < this->_length; i++)
	{
		this->m_Array[i] = temp.m_Array[i - 1];
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::AddTail(T k)
{
	CTArray temp(*this);
	this->m_Array = new T[this->_length + 1];
	this->m_Array[_length++] = k;
	for (int i = 0; i < this->_length - 1;i++)
	{
		this->m_Array[i] = temp.m_Array[i];
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::Insert(T k, int n)
{
	if (n == 0)
	{
		this->AddHead(k);
		return *this;
	}
	if(n == this->_length)
	{
		this->AddTail(k);
		return *this;
	}
	CTArray temp(*this);
	this->m_Array = new T[this->_length + 1];
	this->_length += 1;
	for (int i = 0; i < this->_length; i++)
	{
		this->m_Array[i] = temp.m_Array[i];
	}
	for (int i = n; i <= this->_length; i++)
	{
		this->m_Array[i] = temp.m_Array[i - 1];
	}
	this->m_Array[n] = k;
	return *this;
}

template<class T>
T CTArray<T>::Max()
{
	T max = this->m_Array[0];
	for (int i = 0; i < this->_length; i++)
	{
		if (max < this->m_Array[i])
		{
			max = this->m_Array[i];
		}
	}
	return max;
}

template<class T>
T CTArray<T>::Min()
{
	T min = this->m_Array[0];
	for (int i = 0; i < this->_length; i++)
	{
		if (min > this->m_Array[i])
		{
			min = this->m_Array[i];
		}
	}
	return min;
}

template<class T>
CTArray<T> CTArray<T>::Ascending()
{
	for (int j = 1; j < this->_length; j++)
	{
		T key = this->m_Array[j];
		int i = j - 1;
		while (i >= 0 && this->m_Array[i] > key)
		{
			this->m_Array[i + 1] = this->m_Array[i];
			i--;
		}
		this->m_Array[i + 1] = key;
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::Descending()
{
	for (int j = 1; j < this->_length; j++)
	{
		T key = this->m_Array[j];
		int i = j - 1;
		while (i >= 0 && this->m_Array[i] < key)
		{
			this->m_Array[i + 1] = this->m_Array[i];
			i--;
		}
		this->m_Array[i + 1] = key;
	}
	return *this;
}

template<class T>
bool CTArray<T>::IsSymmetry()
{
	int i = 0;
	int j = this->_length - 1;
	while (i <= j)
	{
		if (this->m_Array[i] != this->m_Array[j])
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

template<class T>
CTArray<T> CTArray<T>::MoveForward()
{
	T tmp = this->m_Array[0];
	for (int i = 0; i < this->_length - 1; i++) this->m_Array[i] = this->m_Array[i + 1];
	this->m_Array[_length - 1] = tmp;
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::MoveForward(int n)
{
	for (int i = n; i >= 0; i--)
	{
		this->MoveForward();
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::MoveBehind()
{
	T tmp = this->_m_Array[this->_length - 1];
	for (int i = this->_length - 1; i >= 0; i--)
	{
		this->_m_Array[i] = this->_m_Array[i - 1];
	}
	this->_m_Array[0] = tmp;
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::MoveBehind(int n)
{
	for (int i = 0; i < k; i++)
	{
		this->MoveBehind();
	}
	return *this;
}

template<class T>
CTArray<T> CTArray<T>::Invert()
{
	for (int i = 0; i < this->_length / 2; i++)
	{
		T temp = this->_m_Array[i];
		this->_m_Array[i] = this->_m_Array[this->_length - i - 1];
		this->_m_Array[this->_length - i - 1] = temp;
	}
	return *this;
}

template<class T>
int CTArray<T>::Appearance(T k)
{
	int count = 0;
	for (int i = 0; i < this->_length; i++)
	{
		if (this->_m_Array[i] == k)
		{
			count++;
		}
	}
	return count;
}

template<class T>
CTArray<T>::~CTArray()
{
	delete[] m_Array;
}
