#pragma once
// ANSI C++��׼��ͷ�ļ�
#include <cstring>					// ��׼������
#include <iostream>					// ��׼������
using namespace std;

#define DEFAULT_SIZE 100
#define LISTINCREMENT 10			//��������
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// ˳��ջģ����
template<class ElemType>
class SqStack
{
protected:
	// ˳��ջ�����ݳ�Ա:
	int maxSize;									// ջ��������� 
	ElemType *top;									// ջ��ָ�� 
	ElemType *data;									// Ԫ�ش洢�ռ�
public:
	//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	SqStack(int size = DEFAULT_SIZE) {
		maxSize = size;
		data = new ElemType[size];
		if (!data)
			exit(OVERFLOW);
		top = data;
	}				// ���캯��
	virtual ~SqStack() {
		if (data)
			delete[]data;
	}							// ��������
	int getLength() const {
		return maxSize;
	}						// ��ջ�ĳ���			 
	bool isEmpty() const {
		if (top == data)
			return true;
		else
			return false;
	}// �ж�ջ�Ƿ�Ϊ��
	void clear() {
		maxSize = 0;
		top = data;
	}								// ��ջ���
	void traverse(void(*Visit)(const ElemType &)) const {
		if (top == data)
			exit(INFEASIBLE);
		for (int i = 0; i < maxSize; i++)
			Visit(data[i]);
	}	// ����ջ
	void fun(const ElemType &a) {
		cout << a;
	}
	int push(const ElemType e) {
		if (top - data >= maxSize) {
			maxSize = DEFAULT_SIZE + LISTINCREMENT;
			delete[]data;
			data = new ElemType[maxSize];
			if (!data)
				exit(OVERFLOW);
		}
		*top++ = e;
		return OK;
	}		    // ��ջ
	ElemType getTop() const {
		if (top != data)
			return *(top - 1);
		else
			return ERROR;
	}		    // ȡ��Ԫ��
	int pop() {
		if (top != data)
		{
			ElemType e = *--top;
			return OK;
		}
		else
			exit(INFEASIBLE);
	}					    // ��ջ
	SqStack(const SqStack<ElemType> &s) {
		maxSize = s.maxSize;
		top = s.top;
		for (int i = 0; i < maxSize; i++)
			data[i] = s.data[i];
	}	// ���ƹ��캯��
	SqStack<ElemType> &operator =(const SqStack<ElemType> &s) {
		maxSize = s.maxSize;
		top = s.top;
		for (int i = 0; i < maxSize; i++)
			data[i] = s.data[i];
		return *this;
	} // ��ֵ�������
};
