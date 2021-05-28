#pragma once

#include <iostream>
#include <fstream>
using namespace std;

#include"Worker.h"

#define FILENAME ".\\Data\\empFile.txt"
class WorkerManager
{
public:
	//��¼�ļ��е���������
	int m_EmpNum;

	//Ա�������ָ��
	Worker* *m_EmpArray;

	//�ļ��Ƿ�Ϊ�ձ�־λ
	bool m_FileIsEmpty;

	//չʾ�˵�
	void Show_Menu();

	//�˳��˵�
	void exitSystem();

	//���ְ��
	void Add_Emp();

	//���浽�ļ�
	void save();

	//��ȡְԱ����
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʼ��Ա��
	void show_Emp();


	WorkerManager();
	~WorkerManager();

private:

};




