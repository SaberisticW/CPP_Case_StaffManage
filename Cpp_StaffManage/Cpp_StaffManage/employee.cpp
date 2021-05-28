#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "employee.h"

void Employee::showInfo()
{
	cout <<"工号：" <<this->m_Id << "\t姓名" <<this->m_Name << "\t职务" << this->getDeptName() << endl;
}

string Employee::getDeptName()
{
	return "员工";
}

Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}


