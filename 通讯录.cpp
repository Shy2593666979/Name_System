#include<iostream>
#include<string>
#define Max 100
using  namespace std;
class book_system
{
public:
	string name;
	string sex;
	int number;    //��������Ϊ�õ�int���ͣ����Ե绰����ֻ����ǰ9λ���ɡ�
	string adress;
};
class Book_System
{
public:
	book_system store[Max];
	int _n;
};
void AddContact(Book_System* book)
{
	string name1;
	string sex1;
	int number1;
	string adress1;
	cout << "��������ϵ�˵�����" << endl;
	cin >> name1;
	book->store[book->_n].name = name1;
	cout << "��������ϵ�˵��Ա�" << endl;
	cin >> sex1;
	book->store[book->_n].sex = sex1;
	cout << "��������ϵ�˵��ֻ�����" << endl;
	cin >> number1;
	book->store[book->_n].number = number1;
	cout << "��������ϵ�˵ĵ�ַ" << endl;
	cin >> adress1;
	cout << "       ������!            " << endl;
	book->store[book->_n].adress = adress1;
	book->_n = book->_n + 1;
}
void FindContact(Book_System* book)
{
	string name1;
	string sex1;
	int number1;
	string adress1;
	int pos;
	cout << "        ��ѡ��        " << endl;
	cout << "��Ҫͨ��ʲô������ϵ��" << endl;
	cout << "ͨ����������    ѡ�� 1" << endl;
	cout << "ͨ���绰����    ѡ�� 2" << endl;
	cin >> pos;
	if (pos == 1)
	{
		int pick = -1;
		cout << "��������ϵ������" << endl;
		cin >> name1;
		for (int i = 0;i < book->_n;i++)
		{
			if (book->store[i].name == name1)
			{
				pick = i;
			}
		}
		if (pick == -1)
		{
			cout << "δ�鵽����ϵ��" << endl;
		}
		else {
			cout << "����ϵ������" << book->store[pick].name;
			cout << "����ϵ���Ա�Ϊ" << book->store[pick].sex;
			cout << "����ϵ�˵绰��Ϊ" << book->store[pick].number;
			cout << "����ϵ�˵�ַΪ" << book->store[pick].adress;
		}
	}
	if (pos == 2)
	{
		int pick2 = -1;
		cout << "��������ϵ���ֻ���" << endl;
		cin >> number1;
		for (int i = 0;i < book->_n;i++)
		{
			if (book->store[i].number == number1)
			{
				pick2 = i;
			}
		}
		if (pick2 == -1)
		{
			cout << "δ�鵽����ϵ��" << endl;
		}
		else {
			cout << "����ϵ������" << book->store[pick2].name;
			cout << "����ϵ���Ա�Ϊ" << book->store[pick2].sex;
			cout << "����ϵ�˵绰��Ϊ" << book->store[pick2].number;
			cout << "����ϵ�˵�ַΪ" << book->store[pick2].adress;
		}
	}
}
void ChangeContact(Book_System* book)
{

	string name1;
	string sex1;
	int number1;
	string adress1;
	cout << "��ӭ�����޸���ϵ�˽���" << endl;
	int pick = -1;
	int res = -1;
	cout << "��������ϵ������" << endl;
	cin >> name1;
	for (int i = 0;i < book->_n;i++)
	{
		if (book->store[i].name == name1)
		{
			pick = i;
		}
	}
	if (pick == -1)
	{
		cout << "δ�鵽����ϵ��" << endl;
	}
	else {
		while (1) {
			cout << "�޸���ϵ�˵�����    1" << endl;
			cout << "�޸���ϵ�˵��Ա�    2" << endl;
			cout << "�޸���ϵ�˵ĵ绰    3" << endl;
			cout << "�޸���ϵ�˵ĵ�ַ    4" << endl;
			cout << "   �˳�����        -1" << endl;
			cin >> res;
			if (res == 1)
			{
				cout << "�����ĳɣ�" << endl;
				cin >> name1;
				book->store[pick].name = name1;
			}
			if (res == 2)
			{
				cout << "�Ա�ĳɣ�" << endl;
				cin >> sex1;
				book->store[pick].sex = sex1;
			}
			if (res == 3)
			{
				cout << "�绰�ĳɣ�" << endl;
				cin >> number1;
				book->store[pick].number = number1;
			}
			if (res == 4)
			{
				cout << "��ַ�ĳɣ�" << endl;
				cin >> adress1;
				book->store[pick].adress = adress1;
			}
			if (res == -1)
			{
				cout << "����޸ģ��ȴ��˳���" << endl;
				break;
			}
		}
	}
}
void DeleteContact(Book_System* book)
{
	string name1;
	string sex1;
	int number1;
	string adress1;
	cout << "��ӭ����ɾ�����棡" << endl;
	cout << "��Ҫɾ����ϵ�˵�����" << endl;
	int pick = -1;
	cin >> name1;
	for (int i = 0;i < book->_n;i++)
	{
		if (book->store[i].name == name1)
		{
			pick = i;
		}
	}
	if (pick == -1)
	{
		cout << "δ�鵽����ϵ��" << endl;
	}
	else {
		for (int i = pick;i < book->_n;i++)
		{
			book->store[i] = book->store[i + 1];
		}
	}
	cout << "ɾ���ɹ�" << endl;
	book->_n = book->_n - 1;
}
void ShowContact(Book_System* book)
{
	for (int i = 0;i < book->_n;i++)
	{
		cout << "��ϵ������Ϊ" << book->store[i].name;
		cout << "��ϵ���Ա�Ϊ" << book->store[i].sex;
		cout << "��ϵ�˵绰Ϊ" << book->store[i].number;
		cout << "��ϵ�˵�ַΪ" << book->store[i].adress;
		cout << endl;
	}
}
void showMenu()
{
	cout << "  ��ӭ����ͨѶ¼ϵͳ���� ��  " << endl;
	cout << "   �����ϵ��  ������������ 1 " << endl;
	cout << "   ������ϵ��  ������������ 2 " << endl;
	cout << "   �޸���ϵ��  ������������ 3 " << endl;
	cout << "   ɾ����ϵ��  ������������ 4 " << endl;
	cout << "   ��ʾ��ϵ��  ������������ 5 " << endl;
	cout << "   �˳�����    ������������ 0 " << endl;
}
int main()
{
	showMenu();
	Book_System target;
	target._n = 0;  //��ʼ����ϵ��
	while (1)
	{
		int select;
		cin >> select;
		if (select == 0)
		{
			cout << "�˳��ɹ�" << endl;
			break;
		}
		if (select == 1)
		{
			AddContact(&target);
		}
		if (select == 2)
		{
			FindContact(&target);
		}
		if (select == 3)
		{
			ChangeContact(&target);
		}
		if (select == 4)
		{
			DeleteContact(&target);
		}
		if (select == 5)
		{
			ShowContact(&target);
		}
	}
	return 0;
}