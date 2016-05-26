#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Stack{
private:
	class Node
	{
	public:
		T data;
		Node* ButtomNode;
	};
	Node* StackPointer;
	Node* BasePointer;
	int Count;

public:
	Stack(); //������
	/*
	Stack �Լ� ���
	*/
	string errorHandler(string msg);
	void Push(T Data); //�� �տ� ���ο� ��� �߰� 
	int size();	// Stack�� ũ�⸦ ������
	T Pop();	// Top�� �ִ� �����͸� �����鼭 ����
	T Peek();	// Top�� �ִ� ������ ��������
	bool isEmpty();	//���� ��ü�� ����ִ��� Ȯ��
};

template <class T>
Stack<T>::Stack()
{
	StackPointer = new Node;
	BasePointer = new Node;
	StackPointer = NULL;
	BasePointer = NULL;
	Count = 0;
}


template <class T>
void Stack<T>::Push(T Data){
	Node* NewStack = new Node;
	NewStack->data = Data;

	if (StackPointer == NULL || BasePointer == NULL){
		NewStack->ButtomNode = NULL;
		BasePointer = NewStack;
	}
	else{
		NewStack->ButtomNode = StackPointer;
	}
	StackPointer = NewStack;
	Count++;
}


template <class T>
bool Stack<T>::isEmpty(){
	if (StackPointer == NULL){
		return true;
	}
	else{
		return false;
	}
}

template <class T>
int Stack<T>::size(){
	return Stack::Count;
}

template <class T>
T Stack<T>::Pop(){
	Node* pop;
	T data;
	try{
		if (StackPointer == NULL || BasePointer == NULL){
			throw "Error : Empty Stack";
		}
		else{
			pop = StackPointer;
			data = pop->data;
			if (StackPointer == BasePointer || StackPointer->ButtomNode == NULL){
				StackPointer = NULL;
				BasePointer = NULL;
				delete pop;
				return data;
			}
			else{
				StackPointer = StackPointer->ButtomNode;
				delete pop;
				return data;
			}
		}
	}
	catch (const char* msg){
		cout << msg << endl;
		cout << "���α׷��� �����Ǿ����ϴ�." << endl;
		exit(0);
	}

}

template <class T>
T Stack<T>::Peek(){
	if (StackPointer == NULL || BasePointer == NULL){
		cout << "Error : Empty Stack" << endl;
		cout << "���α׷��� �����Ǿ����ϴ�." << endl;
		exit(0);
	}
	else{
		return StackPointer->data;
	}

}