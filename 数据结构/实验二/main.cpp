#include "SqStack.h"

#include<string>

int judge(char ch)
{
	switch (ch)
	{
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	default:
		return 0;
	}
}
string BeSuffix(string str)
{
	SqStack<char> stack;
	string back = "";
	for (int i = 0; str[i]!='='; i++)
	{
		switch (str[i])
		{
		case '(':	
			stack.push('(');
			break;
		case ')':
			while (!stack.isEmpty() && stack.getTop() != '(')
			{
				back += stack.getTop();
				stack.pop();
			}
			stack.pop();
			break;
		default:
			if (str[i] >= '0' && str[i] <= '9')
			{
					back += str[i];
			}
			else if (stack.isEmpty() || stack.getTop() == '(' || (stack.getTop() != '(' && judge(str[i]) > judge(stack.getTop())))
			{
				stack.push(str[i]);
			}
			else
			{
				while (!stack.isEmpty() && judge(str[i]) <= judge(stack.getTop()))
				{
					back += stack.getTop();
					stack.pop();
				}
				stack.push(str[i]);
			}
			break;
		}
	}
	while (!stack.isEmpty())
	{
		back += stack.getTop();
		stack.pop();
	}
	return back;
}
int Result(string back)	
{
	int stackNum, num1, num2;
	SqStack<int> tempStack;	
	for (int i = 0; i < back.length(); i++)
	{
		string stackStr = "";			
		if (back[i] >= '0' && back[i] <= '9')
		{
			stackStr += back[i];
			stackNum = stoi(stackStr);//stringתint
			tempStack.push(stackNum);//ת������ջ
		}	
		else						  //������������ջ���Σ���num1��num2�ֱ���ʱ�洢
		{
			num1 = tempStack.getTop();
			tempStack.pop();
			num2 = tempStack.getTop();
			tempStack.pop();
		}
		switch (back[i])			//����������Ͷ�num1��num2������Ӧ����,��stackNum�洢������������ջ
		{
		case '+':
			stackNum = num2 + num1;
			tempStack.push(stackNum);
			break;
		case '-':
			stackNum = num2 - num1;
			tempStack.push(stackNum);
			break;
		case '*':
			stackNum = num2 * num1;
			tempStack.push(stackNum);
			break;
		case '/':
			stackNum = num2 / num1;
			tempStack.push(stackNum);
			break;
		}
	}
	return tempStack.getTop();
}

int main()
{
	string str;
	cin >> str;
	string back = BeSuffix(str);
	cout << back << endl;
	int r = Result(back);
	cout << r;
	cout << endl;
	system("pause");
	return 0;
}