#pragma once
#include<iostream>
#include"User.h"
#include"Mysql.h"
#include"prod.h"
#include<iomanip>
#include<vector>
#include<Windows.h>
#include<string>

using namespace std;

class Manage {
public:
	Manage();
	~Manage();
	void ShowMenu();
	bool QueryProd(string prodname);
	Mysql new_mysql;
public:
};