#include"manage.h"

Manage::Manage()
{

}

Manage::~Manage()
{

}

void Manage::ShowMenu()
{
	system("cls");					//����
	cout << "========================��ӭʹ�����ƹ���ϵͳ========================" << endl;
	cout << "========================1.��ѯ��Ʒ��Ϣ-----========================" << endl;
	cout << "========================2.��ѯ��Ӧ����Ϣ---========================" << endl;
	cout << "========================3.���ٶ���--------=========================" << endl;
	cout << "========================4.��ѯ�����Ϣ-----========================" << endl;
	cout << "========================5.�鿴ӯ��---------========================" << endl;
	cout << "========================6.�����û�---------========================" << endl;
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
	cout << "��ƷID		��Ӧ��ID			��Ʒ��		�۸�			��Ʒ���" << endl;
	//                                                                                  
	for (vecIter = prods.begin(); vecIter != prods.end(); vecIter++)
	{
		cout << setiosflags(ios::left) << vecIter->Getid() << setw(18) << vecIter->Getvendid() << setw(32) << vecIter->Getname() << setw(42) << vecIter->Getprice() << setw(58) << vecIter->Getdesc() << endl;
	}
	cin.get();
	cin.get();
	return true;
}