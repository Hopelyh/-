#include"Prod.h"


Prod::Prod(void)
{

}


Prod::Prod(string Prodid, int Vendid, string Prodname, double price, string desc)
{
	prodid = Prodid;
	vendid = Vendid;
	prodname = Prodname;
	prodprice = price;
	proddesc = desc;
}

Prod::~Prod()
{

}

void Prod::Setid(string id)
{
	prodid = id;
}

void Prod::SetVendid(int vendid)
{
	vendid = vendid;
}

void Prod::Setname(string name)
{
	prodname = name;
}

void Prod::Setprice(int price)
{
	prodprice = price;
}

void Prod::Setdesc(string desc)
{
	proddesc = desc;
}

string Prod::Getid()
{
	return prodid;
}

int Prod::Getvendid()
{
	return vendid;
}

string Prod::Getname()
{
	return prodname;
}

int Prod::Getprice()
{
	return prodprice;
}

string Prod::Getdesc()
{
	return proddesc;
}
