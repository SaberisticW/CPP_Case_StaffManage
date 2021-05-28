#include <iostream>
#include <string>
using namespace std;

#include "StaffManager.h"
#include "employee.h"
#include "manager.h"
#include "Boss.h"

void WorkerManager::Show_Menu()
{
	cout << "*************************************************************************" << endl;
	cout << "******************** Welcome to staff management! ***********************" << endl;
	cout << "********************       0.退出管理系统         ***********************" << endl;
	cout << "********************       1.增加员工信息         ***********************" << endl;
	cout << "********************       2.显示员工信息         ***********************" << endl;
	cout << "********************       3.删除离职员工         ***********************" << endl;
	cout << "********************       4.修改职工信息         ***********************" << endl;
	cout << "********************       5.查找员工信息         ***********************" << endl;
	cout << "********************       6.按照编号排序         ***********************" << endl;
	cout << "********************       7.清除所有文档         ***********************" << endl;
	cout << "*************************************************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//增加职员
void WorkerManager::Add_Emp()
{
	//添加职工
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0u;
	cin >> addNum;

	if (addNum > 0u)
	{
		//计算空间大小
		int  newSize = this->m_EmpNum + addNum;

		//开辟空间
		Worker ** newSpace = new Worker*[newSize];

		//将原空间内容放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0u; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新员工编号：" << endl;
			cin >> id;

			cout << "请输入第 " << i + 1 << " 个新员工姓名：" << endl;
			cin >> name;

			cout << "选择员工职务：" << endl;
			cout << "1、职员" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker * worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间指向
		this->m_EmpArray = newSpace;

		//更新新的个数
		this->m_EmpNum = newSize;

		//提示信息
		cout << "成功添加" << addNum << "名新职员！" << endl;

		//保存到文件
		this->save();
	}
	else
	{
		cout << "输入有误！" << endl;
	}

	system("pause");
	system("cls");
}

//保存文件
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum() 
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0u;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		//记录人数
		num++;
	}

	ifs.close();

	return num;
}

//初始化时候读出文件库中的员工数据
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0u;

	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker *worker = NULL;
		//f根据不同部门创建不同对象
		if (dId == 1) //职员
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //经理
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) //老板
		{
			worker = new Boss(id, name, dId);
		}
		else
		{

		}

		//存档在数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
}

//显示员工
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "当前数据库无数据！" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}


WorkerManager::WorkerManager()
{
	ifstream ifs;
	char ch;

	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open())
	{
		cout << "*****************    首次进入系统，正在初始化！      ********************" << endl;
		cout << "********************            10%~~~~           ***********************" << endl;
		cout << "********************            50%~~~~           ***********************" << endl;
		cout << "********************            90%~~~~           ***********************" << endl;
		cout << "********************        初始化完成！          ***********************" << endl;
		this->m_EmpNum = 0u;
		this->m_FileIsEmpty = true;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	else
	{
		ifs >> ch;
		if (ifs.eof())
		{
			cout <<"*********************   warning:当前数据库为空!   ***********************" << endl;
			this->m_EmpNum = 0u;
			this->m_FileIsEmpty = true;
			this->m_EmpArray = NULL;
			ifs.close();
			return;
		}
		else
		{
			this->m_FileIsEmpty = false;
			int num = this->get_EmpNum();
			this->m_EmpNum = num;

			//根据职工数创造数组
			this->m_EmpArray = new Worker *[this->m_EmpNum];

			//初始化职工
			init_Emp();

		}

	}
}



WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

