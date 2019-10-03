#pragma once

// ANSI C++��׼��ͷ�ļ�
#include <cstring>					// ��׼������
#include <iostream>					// ��׼������
using namespace std;

// �궨��
#define DEFAULT_SIZE 1000			// ȱʡԪ�ظ���
#define DEFAULT_INFINITY 1000000	// ȱʡ�����
#define LISTINCREMENT 10			//��������
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERLOW -2

// ˳���ģ��������� 
template <class ElemType>
class SqList
{
protected:
	// ˳�������ݳ�Ա
	int length;					// ˳���ĵ�ǰ���� 
	int maxLength;				// ˳�����������
	ElemType *data;			// Ԫ�ش洢�ռ���׵�ַ 

public:
	// ˳���ĺ�����Ա
	SqList(int size = DEFAULT_SIZE) {
		data = new ElemType[size];
		if (!data) {
			cout << "Error!" << endl;
			exit(OVERFLOW);
		}
		length = 0;
		maxLength = size;
	}	// ����һ���ձ� 
	SqList(ElemType v[], int n, int size = DEFAULT_SIZE) {
		data = new ElemType[size];
		if (!data) {
			cout << "Error!" << endl;
			exit(OVERFLOW);
		}
		for (int i = 0; i < n; i++)
			data[i] = v[i];
		length = n;
		maxLength = size;
	}	// ��������v�����ݹ���˳��� 
	virtual ~SqList() { 
		if (data != NULL)
		delete []data; 
	}	// ��������
	int GetLength() const { 
		return length;
	};		// ȡ˳�����			 
	bool IsEmpty() const {
		if (length == 0)
			return true;
		else
			return false;
	}	// �ж�˳����Ƿ�Ϊ��
	void Clear() {
		length = 0;
	}		// ��˳������(ʵ����ԭ����Ԫ�ػ������ڴ�ռ���ģ����ֱ��������ȥ���ʣ���Ȼ���԰�Ԫ�ض�ȡ������)
	void Traverse(void(*Visit)(const ElemType &)) const {
		for (int i = 0; i < length; i++)
			Visit(data[i]);
	}	// ����˳���
	void fun(const ElemType &) {
		cout <<GetElem << endl;
	}
	int LocateElem(const ElemType &e) const {
		for (int i = 0; i < length; i++)
		{
			if (data[i] == e)
			{
				return i + 1;
				break;
			}
			if (i == length)
				return 0;
		}

	}// Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��
	ElemType GetElem(int i) const {
		return data[i - 1];
	}	// ȡ˳����е�i��Ԫ�ص�ֵ	
	int SetElem(int i, const ElemType &e) {
		data[i - 1] = e;
		return OK;
	}	// �޸�˳����е�i��Ԫ�ص�ֵ
	int DeleteElem(int i, ElemType &e) {
		if (i<1 || i>length)
			return ERROR;
		ElemType *p = &data[i - 1];
		e = *p;
		ElemType *q = data + length - 1;
		for (++p; p <= q; p++)
			*(p - 1) = *p;
		length--;
		return OK;
	}  // ɾ��˳����е�i��Ԫ��		
	int InsertElem(int i, const ElemType &e) {
		if (i<1 || i>length + 1)
			return ERROR;
		if (length >= maxLength) {//��ǰ�������������ӷ���
			delete[]data;
			data = new ElemType[maxLength +LISTINCREMENT];
			if (!data)
				exit(OVERFLOW);
			maxLength += LISTINCREMENT;
		}
		ElemType *p = &data[length-1];
		ElemType *q = &data[i - 1];
		for (; p>=q ; p--)
		{
			*(p + 1) = *p;
		}
		*p = e;
		length++;
		return OK;
	} // ��˳����i��λ��ǰ����Ԫ��
	int InsertElem(const ElemType &e) {
		if (length >= maxLength) {
			data = new ElemType[maxLength + LISTINCREMENT];
			if (!data)
				exit(OVERFLOW);
			maxLength += LISTINCREMENT;
		}
		ElemType *p = &data[length-1];
		*p = e;
		length++;
		return OK;
	}       // ��˳����β����Ԫ��
	SqList(const SqList<ElemType> &sa) {
		length = sa.length;
		maxLength = sa.maxLength;
		data = new ElemType[DEFAULT_SIZE];
		for (int i = 0; i < length; i++)
			data[i] = sa.data[i];
	}   // ���ƹ��캯��
	SqList<ElemType> &operator =(const SqList<ElemType> &sa) {
		length = sa.length;
		maxLength = sa.maxLength;
		for (int i = 0; i < length; i++)
		{
			data[i] = sa.data[i];
		}
		return *this;
	}// ��ֵ�������
};
