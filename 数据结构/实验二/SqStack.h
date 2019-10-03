#pragma once
// ANSI C++标准库头文件
#include <cstring>					// 标准串操作
#include <iostream>					// 标准流操作
using namespace std;

#define DEFAULT_SIZE 100
#define LISTINCREMENT 10			//分配增量
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

// 顺序栈模板类
template<class ElemType>
class SqStack
{
protected:
	// 顺序栈的数据成员:
	int maxSize;									// 栈的最大容量 
	ElemType *top;									// 栈顶指针 
	ElemType *data;									// 元素存储空间
public:
	//  顺序栈的方法声明及重载编译系统默认方法声明:
	SqStack(int size = DEFAULT_SIZE) {
		maxSize = size;
		data = new ElemType[size];
		if (!data)
			exit(OVERFLOW);
		top = data;
	}				// 构造函数
	virtual ~SqStack() {
		if (data)
			delete[]data;
	}							// 析构函数
	int getLength() const {
		return maxSize;
	}						// 求栈的长度			 
	bool isEmpty() const {
		if (top == data)
			return true;
		else
			return false;
	}// 判断栈是否为空
	void clear() {
		maxSize = 0;
		top = data;
	}								// 将栈清空
	void traverse(void(*Visit)(const ElemType &)) const {
		if (top == data)
			exit(INFEASIBLE);
		for (int i = 0; i < maxSize; i++)
			Visit(data[i]);
	}	// 遍历栈
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
	}		    // 入栈
	ElemType getTop() const {
		if (top != data)
			return *(top - 1);
		else
			return ERROR;
	}		    // 取顶元素
	int pop() {
		if (top != data)
		{
			ElemType e = *--top;
			return OK;
		}
		else
			exit(INFEASIBLE);
	}					    // 出栈
	SqStack(const SqStack<ElemType> &s) {
		maxSize = s.maxSize;
		top = s.top;
		for (int i = 0; i < maxSize; i++)
			data[i] = s.data[i];
	}	// 复制构造函数
	SqStack<ElemType> &operator =(const SqStack<ElemType> &s) {
		maxSize = s.maxSize;
		top = s.top;
		for (int i = 0; i < maxSize; i++)
			data[i] = s.data[i];
		return *this;
	} // 赋值语句重载
};
