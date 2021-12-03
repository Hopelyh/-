#pragma once
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<stdlib.h>
//关键MySQL的头文件
#include<Windows.h>
#include<mysql.h>
#include<winsock.h>
#include"prod.h"
#include"User.h"
using namespace std;

class Mysql
{
public:
	Mysql();
	~Mysql();

	bool ConnectMysql();
	bool CloseMysql();

	bool SelectProdName(string name,vector<Prod> &prods);
	User QueryUserInfo(string strName,string strPswd);

public:
	string username;		//用户名
	string passwd;			//密码
	string localname;		//主机名
	string dataname;		//数据库名
	int port;				//端口名

	MYSQL mysql;			//mysql连接
	MYSQL_RES* result;		//这个结构代表返回行的一个查询结果集
	MYSQL_FIELD* fd;		//字段列数组
	MYSQL_ROW sqlrow;		//一个行数据的类型安全的表示，表示数据行的列

	bool isOpen;			
};

