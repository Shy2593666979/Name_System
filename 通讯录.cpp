#include<iostream>
#include<string>
#define Max 100
using  namespace std;
class book_system
{
public:
	string name;
	string sex;
	int number;    //声明：因为用的int类型，所以电话号码只输入前9位即可。
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
	cout << "请输入联系人的姓名" << endl;
	cin >> name1;
	book->store[book->_n].name = name1;
	cout << "请输入联系人的性别" << endl;
	cin >> sex1;
	book->store[book->_n].sex = sex1;
	cout << "请输入联系人的手机号码" << endl;
	cin >> number1;
	book->store[book->_n].number = number1;
	cout << "请输入联系人的地址" << endl;
	cin >> adress1;
	cout << "       添加完成!            " << endl;
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
	cout << "        请选择        " << endl;
	cout << "想要通过什么查找联系人" << endl;
	cout << "通过姓名查找    选择 1" << endl;
	cout << "通过电话查找    选择 2" << endl;
	cin >> pos;
	if (pos == 1)
	{
		int pick = -1;
		cout << "请输入联系人姓名" << endl;
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
			cout << "未查到此联系人" << endl;
		}
		else {
			cout << "该联系人姓名" << book->store[pick].name;
			cout << "该联系人性别为" << book->store[pick].sex;
			cout << "该联系人电话号为" << book->store[pick].number;
			cout << "该联系人地址为" << book->store[pick].adress;
		}
	}
	if (pos == 2)
	{
		int pick2 = -1;
		cout << "请输入联系人手机号" << endl;
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
			cout << "未查到此联系人" << endl;
		}
		else {
			cout << "该联系人姓名" << book->store[pick2].name;
			cout << "该联系人性别为" << book->store[pick2].sex;
			cout << "该联系人电话号为" << book->store[pick2].number;
			cout << "该联系人地址为" << book->store[pick2].adress;
		}
	}
}
void ChangeContact(Book_System* book)
{

	string name1;
	string sex1;
	int number1;
	string adress1;
	cout << "欢迎来到修改联系人界面" << endl;
	int pick = -1;
	int res = -1;
	cout << "请输入联系人姓名" << endl;
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
		cout << "未查到此联系人" << endl;
	}
	else {
		while (1) {
			cout << "修改联系人的姓名    1" << endl;
			cout << "修改联系人的性别    2" << endl;
			cout << "修改联系人的电话    3" << endl;
			cout << "修改联系人的地址    4" << endl;
			cout << "   退出功能        -1" << endl;
			cin >> res;
			if (res == 1)
			{
				cout << "姓名改成：" << endl;
				cin >> name1;
				book->store[pick].name = name1;
			}
			if (res == 2)
			{
				cout << "性别改成：" << endl;
				cin >> sex1;
				book->store[pick].sex = sex1;
			}
			if (res == 3)
			{
				cout << "电话改成：" << endl;
				cin >> number1;
				book->store[pick].number = number1;
			}
			if (res == 4)
			{
				cout << "地址改成：" << endl;
				cin >> adress1;
				book->store[pick].adress = adress1;
			}
			if (res == -1)
			{
				cout << "完成修改，等待退出！" << endl;
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
	cout << "欢迎进入删除界面！" << endl;
	cout << "想要删除联系人的姓名" << endl;
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
		cout << "未查到此联系人" << endl;
	}
	else {
		for (int i = pick;i < book->_n;i++)
		{
			book->store[i] = book->store[i + 1];
		}
	}
	cout << "删除成功" << endl;
	book->_n = book->_n - 1;
}
void ShowContact(Book_System* book)
{
	for (int i = 0;i < book->_n;i++)
	{
		cout << "联系人姓名为" << book->store[i].name;
		cout << "联系人性别为" << book->store[i].sex;
		cout << "联系人电话为" << book->store[i].number;
		cout << "联系人地址为" << book->store[i].adress;
		cout << endl;
	}
}
void showMenu()
{
	cout << "  ●欢迎来到通讯录系统界面 ●  " << endl;
	cout << "   添加联系人  ······ 1 " << endl;
	cout << "   查找联系人  ······ 2 " << endl;
	cout << "   修改联系人  ······ 3 " << endl;
	cout << "   删除联系人  ······ 4 " << endl;
	cout << "   显示联系人  ······ 5 " << endl;
	cout << "   退出功能    ······ 0 " << endl;
}
int main()
{
	showMenu();
	Book_System target;
	target._n = 0;  //初始化联系人
	while (1)
	{
		int select;
		cin >> select;
		if (select == 0)
		{
			cout << "退出成功" << endl;
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