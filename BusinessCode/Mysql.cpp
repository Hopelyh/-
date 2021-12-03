#include"Mysql.h"

Mysql::Mysql()
{
	username = "root";
	passwd = "hl20010405";
	localname = "localhost";
	dataname = "test";
	port = 3306;
	isOpen = false;
}

Mysql::~Mysql()
{

}

//�������ݿ�
bool Mysql::ConnectMysql()
{
	mysql_init(&mysql);
	//ʹ�� unix���ӷ�ʽ��unix_socketΪnullʱ��������ʹ��socket��ܵ�����
	if (mysql_real_connect(&mysql, localname.c_str(), username.c_str(), passwd.c_str(), dataname.c_str(), port, NULL, 0))		
	{
		isOpen = true;
		return true;
	}
	return false;
}

//�ر����ݿ�
bool Mysql::CloseMysql()
{
	mysql_free_result(result);
	mysql_close(&mysql);
	return true;
}

//������Ʒ����ѯ��Ʒ��Ϣ
bool Mysql::SelectProdName(string name, vector<Prod> &prods)
{
	string sql;
	if (isOpen) {
		mysql_query(&mysql, "SET NAME GBK");
		sql += "select *from products where prod_name like '%" + name + "%'";
		if (!mysql_query(&mysql, sql.c_str()))			//��ѯ�ɹ�����0��ʧ�ܷ���1
		{
			result = mysql_store_result(&mysql);
			if (result) {
				while (sqlrow=mysql_fetch_row(result))
				{
					Prod prod;
					prod.Setid(sqlrow[0]);
					prod.SetVendid(atoi(sqlrow[1]));
					prod.Setname(sqlrow[2]);
					prod.Setprice(atof(sqlrow[3]));
					prod.Setdesc(sqlrow[4]);
					prods.push_back(prod);
				}
			}
		}
		else {
			cout << "query failed!" << endl;
		}
	}
	else {
		cout << "connect failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);
	}
	return true;
}

//��ѯ�û���Ϣ
User Mysql::QueryUserInfo(string strName, string strPswd)
{
	string sql;
	User user;
	if (isOpen)
	{	
		mysql_query(&mysql, "SET NAMES GBK");
		sql += "select * from users where username = '" + strName + "' and userpswd= '" + strPswd + "'";
		if (!mysql_query(&mysql, sql.c_str())) {
			result=mysql_store_result(&mysql);
			if (result)
			{
				while (sqlrow = mysql_fetch_row(result))
				{
					user.UserId = atoi(sqlrow[0]);
					user.UserName = sqlrow[1];
					user.UserPawd = sqlrow[2];
				}
			}
			else {
				user.UserId = -1;
				return user;
			}
		}
		else {
			cout<<"Query Failed!"<<endl;
		}
	}
	else {
		cout << "Connect Failed!" << endl;
	}
	if (result != NULL)
	{
		mysql_free_result(result);
	}
	return user;
}