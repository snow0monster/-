#include "_sq_list.h"

struct student {
	char name[10];
	double num;
	float grade;
}STU;

int menu()
{
	int n;
	while (1)
	{
		system("cls");
		cout << "*****欢迎使用学生信息管理系统*****" << endl;
		cout << "1.录入学生信息  2.插入学生数据" << endl;
		cout << "3.修改学生信息  4.删除学生信息" << endl;
		cout << "5.查找学生信息  6.显示所有学生信息" << endl;
		cout << "7.统计学生人数  8.根据绩点排序" << endl;
		cout << "9.根据学号排序  10.清空学生信息" << endl;
		cout << "0.退出" << endl;
		cout << "**********************************" << endl;
		cout << "请选择编号：";
		cin >> n;
		if (n < 0 || n>9)
			cout << "选择错误，请重新输入:";
		else
			return n;
	}
}

int main()
{
	int n, maxSize;
	student stu;

	cout << "请输入需要创建的管理系统的学生人数：";
	cin >> maxSize;
	SqList<student> L(maxSize);

	while (1)
	{
		n = menu();
		switch (n)
		{
		case 1:															//录入学生信息
		{
			char end;
			while (1)
			{
				cout << "请依次输入学生的姓名、学号和成绩" << endl;
				cin >> stu.name >> stu.num >> stu.grade;
				L.InsertElem(stu);
				cout << "是否继续录入:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}
		case 2:															//插入学生信息
		{
			int i;
			cout << "请输入要插入的位置:";
			cin >> i;
			cout << "--请输入学生姓名、学号和绩点--" << endl;
			char end;
			while (1)
			{
				cin >> stu.name >> stu.num >> stu.grade;
				L.InsertElem(i, stu);
				cout << "是否继续插入:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}
		case 3:															//修改学生信息
		{
			int i;
			char end;
			while (1)
			{
				cout << "请输入要修改的位置:";
				cin >> i;
				if (i > L.GetLength() || i < 1)
				{
					cout << "输入错误，请重新输入！" << endl;
					system("pause");
					continue;
				}
				cout << "--请输入修改后的学生姓名、学号和绩点--" << endl;
				cin >> stu.name >> stu.num >> stu.grade;
				L.SetElem(i, stu);
				cout << "是否继续修改:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}
		case 4:															//删除学生信息
		{
			int i;
			char end;
			while (1)
			{
				cout << "请输入要删除学生信息的位置:";
				cin >> i;
				if (i > L.GetLength()||i<1)
				{
					cout << "输入错误，请重新输入！" << endl;
					system("pause");
					continue;
				}
				else
				{
					L.DeleteElem(i, stu);
					cout << "删除成功" << endl;
					cout << "是否继续删除:(y/n)";
					cin >> end;
					if (end == 'y')
						continue;
					if (end == 'n')
						break;
				}
			}
			system("pause");
			break;
		}
		case 5:															//显示学生信息
		{
			int i;
			char end;
			while (1)
			{
				cout << "请输入要查找的学生信息的所在位置:";
				cin >> i;
				if (i > L.GetLength() || i < 1)
				{
					cout << "输入错误，请重新输入！" << endl;
					system("pause");
					continue;
				}
				cout << L.GetElem(i).name << "的学号为" << L.GetElem(i).num;
				cout << ",绩点为" << L.GetElem(i).grade << endl;
				cout << "是否继续查找:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}	
		case 6:															//显示所有学生信息
		{
			if (L.GetLength() == 0)
				cout << "当前系统无信息！" << endl;
			for (int i = 0; i < L.GetLength(); i++)
			{
				cout << L.GetElem(i).name << "的学号为" << L.GetElem(i).num;
				cout << ",绩点为" << L.GetElem(i).grade << endl;
				
			}
			system("pause");
			break;
		}
		case 7:															//统计学生人数
		{
			cout << "学生人数为" << L.GetLength() << endl;
			system("pause");
			break;
		}
		case 8:															//根据绩点排序
		{
			float t[100];
			int o[100];
			for (int i = 0; i < L.GetLength(); i++)
			{
				t[i] = L.GetElem(i).grade;
				o[i] = i;
			}
			for (int i = 0; i < L.GetLength(); i++)
			{
				for (int j = 0; j < L.GetLength() - i-1; j++)
				{
					if (t[j]<t[j+1])
					{
						float tempT = t[j];
						t[j] = t[j + 1];
						t[j + 1] = tempT;
						int tempO = o[j];
						o[j] = o[j + 1];
						o[j + 1] = tempO;
					}
				}
			}
			cout << "根据绩点排序后，学生信息如下：" << endl;
			for (int i = 0; i < L.GetLength(); i++)
			{
				cout << L.GetElem(o[i]).name << "的学号为" << L.GetElem(o[i]).num;
				cout << ",绩点为" << L.GetElem(o[i]).grade << endl;

			}
			system("pause");
			break;
		}
		case 9:															//根据绩点排序
		{
			double t[100];
			int o[100];
			for (int i = 0; i < L.GetLength(); i++)
			{
				t[i] = L.GetElem(i).num;
				o[i] = i;
			}
			for (int i = 0; i < L.GetLength(); i++)
			{
				for (int j = 0; j < L.GetLength() - i - 1; j++)
				{
					if (t[j] > t[j + 1])
					{
						double tempT = t[j];
						t[j] = t[j + 1];
						t[j + 1] = tempT;
						int tempO = o[j];
						o[j] = o[j + 1];
						o[j + 1] = tempO;
					}
				}
			}
			cout << "根据学号排序后，学生信息如下：" << endl;
			for (int i = 0; i < L.GetLength(); i++)
			{
				cout << L.GetElem(o[i]).name << "的学号为" << L.GetElem(o[i]).num;
				cout << ",绩点为" << L.GetElem(o[i]).grade << endl;

			}
			system("pause");
			break;
		}
		case 10:															//清空学生信息
		{
			if (L.IsEmpty())
				cout << "学生信息已经为空！" << endl;
			else
			{
				L.Clear();
				cout << "已清空学生信息！" << endl;
			}
			system("pause");
			break;
		}
		case 0:															//退出
		{
			exit(0);
		}
		default:
			cout << "输入错误，即将退出" << endl;
			break;
			system("pause");
		}
	}

}