#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "Manager.h"

void Manager::showInfo()
{
	cout << "工号：" << this->m_Id << "\t姓名" << this->m_Name << "\t职务" << this->getDeptName() << endl;
}

string Manager::getDeptName()
{
	return "经理";
}

Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}


