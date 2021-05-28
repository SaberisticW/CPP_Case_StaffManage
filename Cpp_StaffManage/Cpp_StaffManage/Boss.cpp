#pragma once
#include <iostream>
#include <string>

using namespace std;

#include "Boss.h"

void Boss::showInfo()
{
	cout << "工号：" << this->m_Id << "\t姓名" << this->m_Name << "\t职务" << this->getDeptName() << endl;
}

string Boss::getDeptName()
{
	return "总裁";
}

Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}


