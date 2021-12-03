#pragma once
#include<iostream>
#include<string>
using namespace std;

class User
{
public:
	User();
	~User();

public:
	int UserId;
	string UserName;
	string UserPawd;
};