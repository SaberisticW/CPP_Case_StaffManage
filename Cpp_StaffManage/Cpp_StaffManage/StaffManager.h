#pragma once

#include <iostream>
#include <fstream>
using namespace std;

#include"Worker.h"

#define FILENAME ".\\Data\\empFile.txt"
class WorkerManager
{
public:
	//记录文件中的人数个数
	int m_EmpNum;

	//员工数组的指针
	Worker* *m_EmpArray;

	//文件是否为空标志位
	bool m_FileIsEmpty;

	//展示菜单
	void Show_Menu();

	//退出菜单
	void exitSystem();

	//添加职工
	void Add_Emp();

	//保存到文件
	void save();

	//获取职员人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//初始化员工
	void show_Emp();


	WorkerManager();
	~WorkerManager();

private:

};




