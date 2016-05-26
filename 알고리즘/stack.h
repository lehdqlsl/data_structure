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
	Stack(); //생성자
	/*
	Stack 함수 목록
	*/
	string errorHandler(string msg);
	void Push(T Data); //맨 앞에 새로운 노드 추가 
	int size();	// Stack의 크기를 리턴함
	T Pop();	// Top에 있는 데이터를 꺼내면서 삭제
	T Peek();	// Top에 있는 데이터 가져오기
	bool isEmpty();	//스택 객체가 비어있는지 확인
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
		cout << "프로그램이 중지되었습니다." << endl;
		exit(0);
	}

}

template <class T>
T Stack<T>::Peek(){
	if (StackPointer == NULL || BasePointer == NULL){
		cout << "Error : Empty Stack" << endl;
		cout << "프로그램이 중지되었습니다." << endl;
		exit(0);
	}
	else{
		return StackPointer->data;
	}

}