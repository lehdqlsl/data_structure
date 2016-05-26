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
	void valid(int count); //����ó���� �ϱ� ���� �Լ� (����� �Լ� X)
	int Count;	//����Ʈ�� ũ�⸦ ������ ����
	Node* Head = new Node; // Head ���

public:
	List(); //������
	/*
	List �Լ� ���
	*/
	T get(int index);	//�ش� index ������ ���
	void add(T Data); //�� �տ� ���ο� ��� �߰� 
	void add(int Count, T Data); //�ش� index�� ���ο� ��� �߰�
	int size();	// List�� ���̸� ������
	void set(int Index, T Data);	//������ �� ����
	void remove(int Index); //�ش� index ����
	bool isEmpty();	//��ü�� ����ִ��� Ȯ��




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
		throw "Error : ��ȿ���� ���� index �Դϴ�.";
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