#pragma once
#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<stdlib.h>
//�ؼ�MySQL��ͷ�ļ�
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
	string username;		//�û���
	string passwd;			//����
	string localname;		//������
	string dataname;		//���ݿ���
	int port;				//�˿���

	MYSQL mysql;			//mysql����
	MYSQL_RES* result;		//����ṹ�������е�һ����ѯ�����
	MYSQL_FIELD* fd;		//�ֶ�������
	MYSQL_ROW sqlrow;		//һ�������ݵ����Ͱ�ȫ�ı�ʾ����ʾ�����е���

	bool isOpen;			
};

