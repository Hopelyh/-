#include"manage.h"

Manage::Manage()
{

}

Manage::~Manage()
{

}

void Manage::ShowMenu()
{
	system("cls");					//清屏
	cout << "========================欢迎使用商云管理系统========================" << endl;
	cout << "========================1.查询商品信息-----========================" << endl;
	cout << "========================2.查询供应商信息---========================" << endl;
	cout << "========================3.跟踪订单--------=========================" << endl;
	cout << "========================4.查询买家信息-----========================" << endl;
	cout << "========================5.查看盈亏---------========================" << endl;
	cout << "========================6.新增用户---------========================" << endl;
	cout << "Please enter your choice:" << endl;
}

bool Manage::QueryProd(string prodname)
{
	vector<Prod> prods;
	if (!new_mysql.isOpen)
	{
		new_mysql.ConnectMysql();
	}
	new_mysql.SelectProdName(prodname, prods);
	vector<Prod>::iterator vecIter;
	cout << "产品ID		供应商ID			商品名		价格			商品简介" << endl;
	//                                                                                  
	for (vecIter = prods.begin(); vecIter != prods.end(); vecIter++)
	{
		cout << setiosflags(ios::left) << vecIter->Getid() << setw(18) << vecIter->Getvendid() << setw(32) << vecIter->Getname() << setw(42) << vecIter->Getprice() << setw(58) << vecIter->Getdesc() << endl;
	}
	cin.get();
	cin.get();
	return true;
}