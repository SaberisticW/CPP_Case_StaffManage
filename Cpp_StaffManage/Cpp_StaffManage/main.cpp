#include <iostream>
#include <string>
#include "StaffManager.h"
using namespace std;

WorkerManager wm;
int choice = 0u;
int main()
{
	

	wm.Show_Menu();
	cout << "����ѡ��" << endl;
	cin >> choice;

	switch (choice)
	{
	//�˳�
	case 0:
		wm.exitSystem();
		break;
	//����Ա����Ϣ
	case 1:
		wm.Add_Emp();
		break;
	//��ʾ��Ϣ
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