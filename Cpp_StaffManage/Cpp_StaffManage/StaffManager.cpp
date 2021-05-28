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
	cout << "********************       0.�˳�����ϵͳ         ***********************" << endl;
	cout << "********************       1.����Ա����Ϣ         ***********************" << endl;
	cout << "********************       2.��ʾԱ����Ϣ         ***********************" << endl;
	cout << "********************       3.ɾ����ְԱ��         ***********************" << endl;
	cout << "********************       4.�޸�ְ����Ϣ         ***********************" << endl;
	cout << "********************       5.����Ա����Ϣ         ***********************" << endl;
	cout << "********************       6.���ձ������         ***********************" << endl;
	cout << "********************       7.��������ĵ�         ***********************" << endl;
	cout << "*************************************************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����ְԱ
void WorkerManager::Add_Emp()
{
	//���ְ��
	cout << "����������ְ�������� " << endl;

	int addNum = 0u;
	cin >> addNum;

	if (addNum > 0u)
	{
		//����ռ��С
		int  newSize = this->m_EmpNum + addNum;

		//���ٿռ�
		Worker ** newSpace = new Worker*[newSize];

		//��ԭ�ռ����ݷŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0u; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����Ա����ţ�" << endl;
			cin >> id;

			cout << "������� " << i + 1 << " ����Ա��������" << endl;
			cin >> name;

			cout << "ѡ��Ա��ְ��" << endl;
			cout << "1��ְԱ" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		//�����µĸ���
		this->m_EmpNum = newSize;

		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְԱ��" << endl;

		//���浽�ļ�
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

//�����ļ�
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
		//��¼����
		num++;
	}

	ifs.close();

	return num;
}

//��ʼ��ʱ������ļ����е�Ա������
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
		//f���ݲ�ͬ���Ŵ�����ͬ����
		if (dId == 1) //ְԱ
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) //����
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) //�ϰ�
		{
			worker = new Boss(id, name, dId);
		}
		else
		{

		}

		//�浵��������
		this->m_EmpArray[index] = worker;
		index++;
	}
}

//��ʾԱ��
void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "��ǰ���ݿ������ݣ�" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
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
		cout << "*****************    �״ν���ϵͳ�����ڳ�ʼ����      ********************" << endl;
		cout << "********************            10%~~~~           ***********************" << endl;
		cout << "********************            50%~~~~           ***********************" << endl;
		cout << "********************            90%~~~~           ***********************" << endl;
		cout << "********************        ��ʼ����ɣ�          ***********************" << endl;
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
			cout <<"*********************   warning:��ǰ���ݿ�Ϊ��!   ***********************" << endl;
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

			//����ְ������������
			this->m_EmpArray = new Worker *[this->m_EmpNum];

			//��ʼ��ְ��
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

