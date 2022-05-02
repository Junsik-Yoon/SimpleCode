#pragma once
#include <iostream>
#include <assert.h>

using namespace std;

template<typename T>
struct Node
{
	T		m_data;
	Node*	pNext;
	Node*	pPrev;

	Node()
	{
		pPrev = nullptr;
		pNext = nullptr;
	}
	Node(T m_data, Node* pPrev, Node* pNext)
	{
		this->m_data = m_data;
		this->pPrev = pPrev;
		this->pNext = pNext;
	}
	~Node() {}
};

template<typename T>
class CMyList
{
	Node<T>* pHeadNode;
	Node<T>* pTailNode;
	unsigned int m_size;

public:
	CMyList()
	{
		pHeadNode = nullptr;
		pTailNode = nullptr;
		m_size = 0;
	}
	~CMyList() {}
	
	void Insert(unsigned int index, const T& data);
	void AddLast(const T& data);
	void AddFirst(const T& data);
	void RemoveLast();
	void RemoveFirst();
	void PrintAll();
};

template<typename T>
inline void CMyList<T>::Insert(unsigned int index, const T& data)
{
	if (m_size < index)
	{
		assert(nullptr);
	}
	Node<T>* curNode;
	curNode = pHeadNode;
	for (int i = 0; i < index; ++i)
	{
		curNode = curNode->pNext;
	}
	Node<T>* prevNode = curNode;
	Node<T>* nextNode = curNode->pNext;
	Node<T>* newNode = new Node<T>(data, prevNode, nextNode);
	prevNode->pNext = newNode;
	nextNode->pPrev = newNode;
	++m_size;
}

template<typename T>
inline void CMyList<T>::AddLast(const T& data)
{
	if (m_size == 0)
	{
		Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
		pHeadNode = newNode;
		pTailNode = newNode;
		++m_size;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data, pTailNode, nullptr);

		pTailNode->pNext = newNode;
		pTailNode = newNode;
		++m_size;
	}
}

template<typename T>
inline void CMyList<T>::AddFirst(const T& data)
{
	if (m_size == 0)
	{
		Node<T>* newNode = new Node<T>(data, nullptr, nullptr);
		pHeadNode = newNode;
		pTailNode = newNode;
		++m_size;
	}
	else
	{
		Node<T>* newNode = new Node<T>(data, nullptr, pHeadNode);

		pHeadNode->pPrev = newNode;
		pHeadNode = newNode;
		++m_size;
	}
}

template<typename T>
inline void CMyList<T>::RemoveLast()
{
	assert(m_size > 0);
	if (m_size > 1)
	{
		Node<T>* tempNode = new Node<T>();
		tempNode = pTailNode;
		pTailNode = pTailNode->pPrev;
		pTailNode->pNext = nullptr;
		delete tempNode;
		--m_size;
	}
	else if (m_size == 1)
	{
		pTailNode = nullptr;
		pHeadNode = nullptr;
		m_size = 0;
	}
}

template<typename T>
inline void CMyList<T>::RemoveFirst()
{
	assert(m_size > 0);
	if (m_size > 1)
	{
		Node<T>* temp;
		temp = pHeadNode;
		pHeadNode = pHeadNode->pNext;
		pHeadNode->pPrev = nullptr;
		delete temp;
		--m_size;
	}
	else if (m_size == 1)
	{
		pTailNode = nullptr;
		pHeadNode = nullptr;
		m_size = 0;
	}
}

template<typename T>
inline void CMyList<T>::PrintAll()
{
	Node<T>* temp;
	temp = pHeadNode;
	for (int i = 0; i < m_size; i++)
	{
		cout << temp->m_data << endl;
		temp = temp->pNext;
	}
	delete temp;
}

