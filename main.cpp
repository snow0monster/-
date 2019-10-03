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
		cout << "*****��ӭʹ��ѧ����Ϣ����ϵͳ*****" << endl;
		cout << "1.¼��ѧ����Ϣ  2.����ѧ������" << endl;
		cout << "3.�޸�ѧ����Ϣ  4.ɾ��ѧ����Ϣ" << endl;
		cout << "5.����ѧ����Ϣ  6.��ʾ����ѧ����Ϣ" << endl;
		cout << "7.ͳ��ѧ������  8.���ݼ�������" << endl;
		cout << "9.����ѧ������  10.���ѧ����Ϣ" << endl;
		cout << "0.�˳�" << endl;
		cout << "**********************************" << endl;
		cout << "��ѡ���ţ�";
		cin >> n;
		if (n < 0 || n>9)
			cout << "ѡ���������������:";
		else
			return n;
	}
}

int main()
{
	int n, maxSize;
	student stu;

	cout << "��������Ҫ�����Ĺ���ϵͳ��ѧ��������";
	cin >> maxSize;
	SqList<student> L(maxSize);

	while (1)
	{
		n = menu();
		switch (n)
		{
		case 1:															//¼��ѧ����Ϣ
		{
			char end;
			while (1)
			{
				cout << "����������ѧ����������ѧ�źͳɼ�" << endl;
				cin >> stu.name >> stu.num >> stu.grade;
				L.InsertElem(stu);
				cout << "�Ƿ����¼��:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}
		case 2:															//����ѧ����Ϣ
		{
			int i;
			cout << "������Ҫ�����λ��:";
			cin >> i;
			cout << "--������ѧ��������ѧ�źͼ���--" << endl;
			char end;
			while (1)
			{
				cin >> stu.name >> stu.num >> stu.grade;
				L.InsertElem(i, stu);
				cout << "�Ƿ��������:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}
		case 3:															//�޸�ѧ����Ϣ
		{
			int i;
			char end;
			while (1)
			{
				cout << "������Ҫ�޸ĵ�λ��:";
				cin >> i;
				if (i > L.GetLength() || i < 1)
				{
					cout << "����������������룡" << endl;
					system("pause");
					continue;
				}
				cout << "--�������޸ĺ��ѧ��������ѧ�źͼ���--" << endl;
				cin >> stu.name >> stu.num >> stu.grade;
				L.SetElem(i, stu);
				cout << "�Ƿ�����޸�:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}
		case 4:															//ɾ��ѧ����Ϣ
		{
			int i;
			char end;
			while (1)
			{
				cout << "������Ҫɾ��ѧ����Ϣ��λ��:";
				cin >> i;
				if (i > L.GetLength()||i<1)
				{
					cout << "����������������룡" << endl;
					system("pause");
					continue;
				}
				else
				{
					L.DeleteElem(i, stu);
					cout << "ɾ���ɹ�" << endl;
					cout << "�Ƿ����ɾ��:(y/n)";
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
		case 5:															//��ʾѧ����Ϣ
		{
			int i;
			char end;
			while (1)
			{
				cout << "������Ҫ���ҵ�ѧ����Ϣ������λ��:";
				cin >> i;
				if (i > L.GetLength() || i < 1)
				{
					cout << "����������������룡" << endl;
					system("pause");
					continue;
				}
				cout << L.GetElem(i).name << "��ѧ��Ϊ" << L.GetElem(i).num;
				cout << ",����Ϊ" << L.GetElem(i).grade << endl;
				cout << "�Ƿ��������:(y/n)";
				cin >> end;
				if (end == 'y')
					continue;
				if (end == 'n')
					break;
			}
			system("pause");
			break;
		}	
		case 6:															//��ʾ����ѧ����Ϣ
		{
			if (L.GetLength() == 0)
				cout << "��ǰϵͳ����Ϣ��" << endl;
			for (int i = 0; i < L.GetLength(); i++)
			{
				cout << L.GetElem(i).name << "��ѧ��Ϊ" << L.GetElem(i).num;
				cout << ",����Ϊ" << L.GetElem(i).grade << endl;
				
			}
			system("pause");
			break;
		}
		case 7:															//ͳ��ѧ������
		{
			cout << "ѧ������Ϊ" << L.GetLength() << endl;
			system("pause");
			break;
		}
		case 8:															//���ݼ�������
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
			cout << "���ݼ��������ѧ����Ϣ���£�" << endl;
			for (int i = 0; i < L.GetLength(); i++)
			{
				cout << L.GetElem(o[i]).name << "��ѧ��Ϊ" << L.GetElem(o[i]).num;
				cout << ",����Ϊ" << L.GetElem(o[i]).grade << endl;

			}
			system("pause");
			break;
		}
		case 9:															//���ݼ�������
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
			cout << "����ѧ�������ѧ����Ϣ���£�" << endl;
			for (int i = 0; i < L.GetLength(); i++)
			{
				cout << L.GetElem(o[i]).name << "��ѧ��Ϊ" << L.GetElem(o[i]).num;
				cout << ",����Ϊ" << L.GetElem(o[i]).grade << endl;

			}
			system("pause");
			break;
		}
		case 10:															//���ѧ����Ϣ
		{
			if (L.IsEmpty())
				cout << "ѧ����Ϣ�Ѿ�Ϊ�գ�" << endl;
			else
			{
				L.Clear();
				cout << "�����ѧ����Ϣ��" << endl;
			}
			system("pause");
			break;
		}
		case 0:															//�˳�
		{
			exit(0);
		}
		default:
			cout << "������󣬼����˳�" << endl;
			break;
			system("pause");
		}
	}

}