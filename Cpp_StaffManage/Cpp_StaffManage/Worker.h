#pragma once

#include <iostream>
#include <string>

using namespace std;

class Worker
{
public:

	//��ʾ������Ϣ
	virtual void showInfo() = 0u;
	//��ȡ��λ����
	virtual string getDeptName() = 0u;

	int m_Id;
	string m_Name;
	int m_DeptId;

	Worker();
	~Worker();

private:

};