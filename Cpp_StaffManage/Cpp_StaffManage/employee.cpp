#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "employee.h"

void Employee::showInfo()
{
	cout <<"���ţ�" <<this->m_Id << "\t����" <<this->m_Name << "\tְ��" << this->getDeptName() << endl;
}

string Employee::getDeptName()
{
	return "Ա��";
}

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

