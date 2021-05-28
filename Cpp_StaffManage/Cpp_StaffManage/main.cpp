#include <iostream>
#include <string>
#include "StaffManager.h"
using namespace std;

WorkerManager wm;
int choice = 0u;
int main()
{
	

	wm.Show_Menu();
	cout << "功能选择：" << endl;
	cin >> choice;

	switch (choice)
	{
	//退出
	case 0:
		wm.exitSystem();
		break;
	//增加员工信息
	case 1:
		wm.Add_Emp();
		break;
	//显示信息
	case 2:
		wm.show_Emp();
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default:
		system("cls");
		break;
	}


	system("pause");
	return 0u;
}