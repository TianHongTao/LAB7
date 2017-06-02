#include"stdafx.h"
#include"all.h"
void  MovieSimulate()//动画仿真模块函数
{
	char use[MAX];
	char temp[] = "";
	cout << "请输入文件名" << endl;
	cin >> user_file_name;
	strcpy(UserRequestFilePath, temp);
	strcpy(use, UserRequestFilePath);
	strcat(use, user_file_name);
	while (_access(use, 0) != 0)
	{
		printf("指令用户文件不存在\n");
		cout << "请输入文件名" << endl;
		cin >> user_file_name;
		strcpy(UserRequestFilePath, temp);
		strcpy(use, UserRequestFilePath);
		strcat(use, user_file_name);
	}
	InitSimulation();
	FILE *fp;
	while ((fp = fopen(use, "r")) == NULL)
	{
		cout << "请输入文件名" << endl;
		cin >> user_file_name;
		strcpy(UserRequestFilePath, temp);
		strcpy(use, UserRequestFilePath);
		strcat(use, user_file_name);
		while (_access(use, 0) != 0)
		{
			printf("指令用户文件不存在\n");
			cout << "请输入文件名" << endl;
			cin >> user_file_name;
			strcpy(UserRequestFilePath, temp);
			strcpy(use, UserRequestFilePath);
			strcat(use, user_file_name);
		}
		InitSimulation();
		fclose(fp);
	}
	while (LoadUserCallArray(fp) == 0)
	{
		char use[MAX];
		char temp[] = "";
		cout << "请输入文件名" << endl;
		cin >> user_file_name;
		strcpy(UserRequestFilePath, temp);
		strcpy(use, UserRequestFilePath);
		strcat(use, user_file_name);
		while (_access(use, 0) != 0)
		{
			printf("指令用户文件不存在\n");
			cout << "请输入文件名" << endl;
			cin >> user_file_name;
			strcpy(UserRequestFilePath, temp);
			strcpy(use, UserRequestFilePath);
			strcat(use, user_file_name);
		}
		InitSimulation();
		FILE *fp;
		while ((fp = fopen(use, "r")) == NULL)
		{
			cout << "请输入文件名" << endl;
			cin >> user_file_name;
			strcpy(UserRequestFilePath, temp);
			strcpy(use, UserRequestFilePath);
			strcat(use, user_file_name);
			while (_access(use, 0) != 0)
			{
				printf("指令用户文件不存在\n");
				cout << "请输入文件名" << endl;
				cin >> user_file_name;
				strcpy(UserRequestFilePath, temp);
				strcpy(use, UserRequestFilePath);
				strcat(use, user_file_name);
			}
			InitSimulation();
			fclose(fp);
		}
	}
	ShowMovie();
}

void  ShowMovie()//显示动画仿真过程函数
{
	time = 0;
	/*
	int Weight,Width;
	cout << "请您初始化你画布的高宽"<<endl;
	cin >> Weight >> Width;
	initgraph(Width,Weight);
	*/
	initgraph(1000, 800);
	setorigin(0, 800);
	while (finish_call_num != usercall_list_len)
	{
		PaintPicture();
		GetNextTimeStatus(&elevator_a);
		GetNextTimeStatus(&elevator_b);
		time++;
		Sleep(atoi(DelayTime));
	}
	closegraph();
	return;
}

void  PaintPicture()//将当前时刻电梯状态绘制成图形的函数
{
	cleardevice();
	int i = 0, t = 0;
	for (i = 0; i < atoi(ElevatorHeight); i++)
	{
		t = i + 1;
		fillrectangle(80, 40 * t, 140, i * 40);
		TCHAR s[5];
		_stprintf(s, _T("%d"), &t);
		outtextxy(60*t , 20*t , s);
	}
	TCHAR c[] = _T("建筑物");
	outtextxy(110, 40*t+20,c);
}