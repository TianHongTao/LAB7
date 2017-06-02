// Lab 7.cpp : 定义控制台应用程序的入口点。
//
#include"stdafx.h"
#include"all.h"
char Elevatorspeed[] = { '1' };
char UserRequestFilePath[] = { '*' };
char SimulationFilesPath[] = { '*' };
char ElevatorHeight[] = { '2','0' };
char DelayTime[] = { '1','0','0','0' };
USERCALL *usercall_list = NULL;
int usercall_list_len = 0;
SYSPARAM param_array[MAX];
ELEVATORSTATE elevator_a, elevator_b;
RESPONSELISTHEADNODE *response_list = NULL;
char user_file_name[10000];
int finish_call_num;
int time;
int status_change_flag;
void Menu1();
void Menu2();
void Menu3();
void Menu4();
void Menu5();
void Menu6();
void ShowMenu(int Menu_flag);
int main()
{
	cout << SystemInit() << endl;
	usercall_list = (USERCALL*)calloc(1, sizeof(USERCALL));
	response_list = (RESPONSELISTHEADNODE*)calloc(1, sizeof(RESPONSELISTHEADNODE));
	ShowMenu(1);
	return 0;
	free(usercall_list);
	free(response_list);
}

