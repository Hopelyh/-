#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Prod
{
public:
	Prod();
	Prod(string Prodid, int Vendid,string Prodname,double price,string desc);
	~Prod();

	void Setid(string id);
	void SetVendid(int vendid);
	void Setname(string name);
	void Setprice(int price);
	void Setdesc(string desc);

	string Getid();
	int Getvendid();
	string Getname();
	int Getprice();
	string Getdesc();

public:
	string prodid;
	int vendid;
	string prodname;
	double prodprice;
	string proddesc;
};