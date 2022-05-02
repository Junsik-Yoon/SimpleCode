#pragma once
#include <assert.h>
#include <iostream>
const int DEFAULT = 10;

template<typename T>
class CMyStack
{
private:
	int m_size;		//stack사이즈
	T* pDataArray;	//stack 데이터 담을 array
	int arrCapa;	//array의 capacity
public:
	CMyStack()
	{
		m_size = 0;				
		pDataArray = new T[DEFAULT];	
		arrCapa = 10;
	}
	~CMyStack() {}

	void Push(const T& data);
	void Pop();
	void Print();
	bool IsEmpty();
	bool IsFull();
};

template<typename T>
void CMyStack<T>::Push(const T& data)
{
	T* newArray = new T[arrCapa * 2];
	if (arrCapa == m_size)
	{
		for (unsigned int i = 0; i < m_size; ++i)
			newArray[i] = pDataArray[i];

		arrCapa *= 2;

		delete[] pDataArray;
		pDataArray = newArray;
	}
	else
	{
		delete[] newArray;
	}
	pDataArray[m_size] = data;
	++m_size;
}

template<typename T>
void CMyStack<T>::Pop()
{
	if (m_size == 0)
		assert(nullptr);
	--m_size;
}


template<typename T>
bool CMyStack<T>::IsEmpty()
{
	return 0 == m_size;
}

template<typename T>
inline bool CMyStack<T>::IsFull()
{
	return !IsEmpty();
}
template<typename T>
inline void CMyStack<T>::Print()
{
	for (int i = 0; i < m_size; ++i)
	{
		std::cout << pDataArray[i] << std::endl;
	}
}
