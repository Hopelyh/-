#include<stdio.h>
#include<iostream>
#include<winsock.h>
#include<Windows.h>

#include"prod.h"
#include"Mysql.h"
#include"manage.h"
#include"User.h"

using namespace std;


int main()
{
	string strUserName = "";
	string strUserPwd = "";

	User user;
	cout << "			�������û�����" << endl;
	cin >> strUserName;
	cout << "			����������:" << endl;
	cin >> strUserPwd;

	Mysql mysql;
	mysql.ConnectMysql();

	user = mysql.QueryUserInfo(strUserName, strUserPwd);

	while (user.UserId == -1)
	{
		cout << "��������˺Ż�����������������룡" << endl;
		system("cls");
		cin.get();
		cin.get();
		cout << "			�������û�����" << endl;
		cin >> strUserName;
		cout << "			����������:" << endl;
		cin >> strUserPwd;
		user = mysql.QueryUserInfo(strUserName, strUserPwd);
	}
	string prodname="";
	Manage manage;
	int command = -1;
	system("cls");
	manage.ShowMenu();
	cout << "���������" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		cout << "��������Ʒ����" << endl;
		cin >> prodname;
		manage.QueryProd(prodname);
		break;
	default:
		break;
	}
	return 0;
} 
