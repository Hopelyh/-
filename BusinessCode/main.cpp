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
	cout << "			请输入用户名：" << endl;
	cin >> strUserName;
	cout << "			请输入密码:" << endl;
	cin >> strUserPwd;

	Mysql mysql;
	mysql.ConnectMysql();

	user = mysql.QueryUserInfo(strUserName, strUserPwd);

	while (user.UserId == -1)
	{
		cout << "你输入的账号或密码错误，请重新输入！" << endl;
		system("cls");
		cin.get();
		cin.get();
		cout << "			请输入用户名：" << endl;
		cin >> strUserName;
		cout << "			请输入密码:" << endl;
		cin >> strUserPwd;
		user = mysql.QueryUserInfo(strUserName, strUserPwd);
	}
	string prodname="";
	Manage manage;
	int command = -1;
	system("cls");
	manage.ShowMenu();
	cout << "请输入命令：" << endl;
	cin >> command;
	switch (command)
	{
	case 1:
		cout << "请输入商品名：" << endl;
		cin >> prodname;
		manage.QueryProd(prodname);
		break;
	default:
		break;
	}
	return 0;
} 
