#pragma once

// ANSI C++标准库头文件
#include <cstring>					// 标准串操作
#include <iostream>					// 标准流操作
using namespace std;

// 宏定义
#define DEFAULT_SIZE 1000			// 缺省元素个数
#define DEFAULT_INFINITY 1000000	// 缺省无穷大
#define LISTINCREMENT 10			//分配增量
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERLOW -2

// 顺序表模板类的申明 
template <class ElemType>
class SqList
{
protected:
	// 顺序表的数据成员
	int length;					// 顺序表的当前长度 
	int maxLength;				// 顺序表的最大容量
	ElemType *data;			// 元素存储空间的首地址 

public:
	// 顺序表的函数成员
	SqList(int size = DEFAULT_SIZE) {
		data = new ElemType[size];
		if (!data) {
			cout << "Error!" << endl;
			exit(OVERFLOW);
		}
		length = 0;
		maxLength = size;
	}	// 构造一个空表 
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
	}	// 根据数组v的内容构造顺序表 
	virtual ~SqList() { 
		if (data != NULL)
		delete []data; 
	}	// 析构函数
	int GetLength() const { 
		return length;
	};		// 取顺序表长度			 
	bool IsEmpty() const {
		if (length == 0)
			return true;
		else
			return false;
	}	// 判断顺序表是否为空
	void Clear() {
		length = 0;
	}		// 将顺序表清空(实质上原来的元素还是在内存空间里的，如果直接用索引去访问，任然可以把元素读取出来的)
	void Traverse(void(*Visit)(const ElemType &)) const {
		for (int i = 0; i < length; i++)
			Visit(data[i]);
	}	// 遍历顺序表
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

	}// 元素定位，求指定元素在顺序表中的位置
	ElemType GetElem(int i) const {
		return data[i - 1];
	}	// 取顺序表中第i个元素的值	
	int SetElem(int i, const ElemType &e) {
		data[i - 1] = e;
		return OK;
	}	// 修改顺序表中第i个元素的值
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
	}  // 删除顺序表中第i个元素		
	int InsertElem(int i, const ElemType &e) {
		if (i<1 || i>length + 1)
			return ERROR;
		if (length >= maxLength) {//当前分配已满，增加分配
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
	} // 在顺序表第i个位置前插入元素
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
	}       // 在顺序表表尾插入元素
	SqList(const SqList<ElemType> &sa) {
		length = sa.length;
		maxLength = sa.maxLength;
		data = new ElemType[DEFAULT_SIZE];
		for (int i = 0; i < length; i++)
			data[i] = sa.data[i];
	}   // 复制构造函数
	SqList<ElemType> &operator =(const SqList<ElemType> &sa) {
		length = sa.length;
		maxLength = sa.maxLength;
		for (int i = 0; i < length; i++)
		{
			data[i] = sa.data[i];
		}
		return *this;
	}// 赋值语句重载
};
