
#include<iostream>
#include<vector>
#include<string>
#include "CMyStack.h"
#include "CMyList.h"
#include <list>
using namespace std;

long Fibonacci(int index)
{
	if (index == 1)
		return 1;
	else if (index == 2)
		return 1;

	return Fibonacci(index - 2) + Fibonacci(index - 1);
}

void HanoiTower(int n,  string start, string destination, string other)
{
	if (n == 1)
	{
		cout << endl << n;
		cout << "를(을)" + start + "->" + destination + "이동";
		return;
	}
		
	HanoiTower(n - 1, start, other, destination);
	cout << endl << n;
	cout << "를(을)" + start + "->" + destination + "이동";
	HanoiTower(n - 1, start, destination, other);
	
}


int main()
{
	cout<<Fibonacci(10);
	HanoiTower(4, "Start", "Destination", "Other");
	CMyStack<int> myStack;
	for (int i = 0; i < 10; ++i)
	{
		myStack.Push(i);
	}
	myStack.Pop();
	cout << myStack.IsEmpty() << endl;
	cout << myStack.IsFull() << endl;
	myStack.Print();

	cout << "ListList" << endl << endl;
	CMyList<int> myList;
	
	//for (int i = 0; i < 5; ++i)
	//{
	//	myList.AddFirst(i);
	//	myList.AddLast(i + 10);
	//}
	for (int i = 0; i < 4; ++i)
	{
		myList.AddLast(i);
	}
	myList.Insert(2, 9);
	/*myList.RemoveFirst();
	myList.RemoveLast();*/
	myList.PrintAll();	
}
