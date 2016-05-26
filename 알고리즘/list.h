#pragma once
#include <iostream>

using namespace std;
template <class T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* nextNode;
	};
	void valid(int count); //예외처리를 하기 위한 함수 (사용자 함수 X)
	int Count;	//리스트의 크기를 저장할 변수
	Node* Head = new Node; // Head 노드

public:
	List(); //생성자
	/*
	List 함수 목록
	*/
	T get(int index);	//해당 index 데이터 출력
	void add(T Data); //맨 앞에 새로운 노드 추가 
	void add(int Count, T Data); //해당 index에 새로운 노드 추가
	int size();	// List의 길이를 리턴함
	void set(int Index, T Data);	//데이터 값 변경
	void remove(int Index); //해당 index 삭제
	bool isEmpty();	//객체가 비어있는지 확인




};


template <class T>
List<T>::List()
{
	Head->nextNode = NULL;
	List::Count = 0;
}

template <class T>
T List<T>::get(int index)
{
	try
	{
		valid(index);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return NULL;
	}

	Node* temp = Head;;
	for (int i = 0; i <= index; i++){
		temp = temp->nextNode;
	}
	return temp->data;
}

template <class T>
void List<T>::valid(int count)
{
	if (count > List::Count)
	{
		throw "Error : 유효하지 않은 index 입니다.";
	}
}

template <class T>
int List<T>::size()
{
	return List::Count;
}

template <class T>
void List<T>::add(T Data)
{
	Node* NewNode = new Node;
	NewNode->data = Data;
	NewNode->nextNode = NULL;

	if (Head->nextNode == NULL)
	{
		Head->nextNode = NewNode;
	}
	else
	{
		Node* temp = Head;
		while (temp->nextNode != NULL)
		{
			temp = temp->nextNode;
		}
		temp->nextNode = NewNode;
	}

	List::Count++;
}

template <class T>
void List<T>::add(int index, T Data)
{
	try
	{
		valid(index);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return;
	}

	Node* NewNode = new Node;
	NewNode->data = Data;
	NewNode->nextNode = NULL;

	if (Head->nextNode == NULL)
	{
		Head->nextNode = NewNode;
	}
	else
	{
		Node* temp = Head;
		for (int i = 0; i < Count; i++)
		{
			temp = temp->nextNode;
		}
		NewNode->nextNode = temp->nextNode;
		temp->nextNode = NewNode;
	}

	List::Count++;
}

template <class T>
void List<T>::set(int index, T Data)
{
	try
	{
		valid(index);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return;
	}

	Node* temp = Head;
	for (int i = 0; i <= index; i++)
	{
		temp = temp->nextNode;
	}

	temp->data = Data;
}

template <class T>
void List<T>::remove(int index)
{
	try
	{
		valid(index);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
		return;
	}

	Node* temp = Head;
	Node* remove = Head;

	for (int i = 0; i < index; i++)
	{
		temp = temp->nextNode;
		remove = remove->nextNode;
	}
	remove = remove->nextNode;

	temp->nextNode = remove->nextNode;
	remove->nextNode = NULL;
	delete remove;
	List::Count--;
}

template <class T>
bool List<T>::isEmpty()
{
	Node* head = Head;
	if (head->nextNode == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}