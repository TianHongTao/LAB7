#include"stdafx.h"
#include"all.h"
void  ParamConf1()
{
	string UserRequestFilePaths;
	UserRequestFilePaths = UserRequestFilePath;
	if (UserRequestFilePaths == "*")
		cout << "您的存放用户指令文件的目录为默认值" << UserRequestFilePaths << endl;
	cout << "请您输入新的路径" << endl;
	while (cin >> UserRequestFilePaths)
	{
		if (access("UserRequestFilePaths", 0) != 0)
		{
			cout << "您输入的是" << UserRequestFilePaths << " " << "您的输入有误请重新输入" << endl;
			continue;
		}
		else
			break;
	}
}
void  ParamConf2()
{
	string  SimulationFilesPaths;
	SimulationFilesPaths = SimulationFilesPath;
	if (SimulationFilesPaths == "*")
		cout << "您的存放历史仿真文件为默认值" << SimulationFilesPaths << endl;
	cout << "请您输入新的路径" << endl;
	while (cin >> SimulationFilesPaths)
	{
		if (access("UserRequestDilePaths", 0) != 0)
		{
			cout << "您输入的是" << SimulationFilesPaths << " " << "您的输入有误请重新输入" << endl;
			continue;
		}
		else
			break;
	}
}
void  ParamConf3()
{
	int ElevatorHeights = atoi(ElevatorHeight);
	if (ElevatorHeights == 20)
		cout << "您的电梯总层数为默认值" << ElevatorHeights << endl;
	cout << "请您输入电梯总层数" << endl;
	while (cin >> ElevatorHeights)
	{
		if (ElevatorHeights<0)
		{
			cout << "您输入的是" << ElevatorHeights << " " << "您的输入有误请重新输入" << endl;
			continue;
		}
		else
			break;
	}
	int n =strlen(ElevatorHeight)*10,i=0;
	while (ElevatorHeights % n == 0)
	{
		ElevatorHeight[i++] = ElevatorHeights % n;
		n /= n;
	}
}
void  ParamConf4()
{
	int DelayTimes = atoi(DelayTime);
	if (DelayTimes == 1000)
		cout << "您的延迟时间是" << DelayTime << "毫秒" << endl;
	cout << "请您输入电梯延迟时间" << endl;
	while (cin >> DelayTimes) {
		if (DelayTime<0)
		{
			cout << "您输入的是" << DelayTimes << " " << "您的输入有误请重新输入" << endl;
			continue;
		}
		else
			break;
	}
	int n = strlen(DelayTime)*10, i = 0;
	while (DelayTimes % n == 0)
	{
		DelayTime[i++] = DelayTimes % n;
		n /= n;
	}
}