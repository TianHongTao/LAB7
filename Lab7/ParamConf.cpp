#include"stdafx.h"
#include"all.h"
void  ParamConf1()
{
	string UserRequestFilePaths;
	UserRequestFilePaths = UserRequestFilePath;
	if (UserRequestFilePaths == "*")
		cout << "���Ĵ���û�ָ���ļ���Ŀ¼ΪĬ��ֵ" << UserRequestFilePaths << endl;
	cout << "���������µ�·��" << endl;
	while (cin >> UserRequestFilePaths)
	{
		if (access("UserRequestFilePaths", 0) != 0)
		{
			cout << "���������" << UserRequestFilePaths << " " << "����������������������" << endl;
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
		cout << "���Ĵ����ʷ�����ļ�ΪĬ��ֵ" << SimulationFilesPaths << endl;
	cout << "���������µ�·��" << endl;
	while (cin >> SimulationFilesPaths)
	{
		if (access("UserRequestDilePaths", 0) != 0)
		{
			cout << "���������" << SimulationFilesPaths << " " << "����������������������" << endl;
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
		cout << "���ĵ����ܲ���ΪĬ��ֵ" << ElevatorHeights << endl;
	cout << "������������ܲ���" << endl;
	while (cin >> ElevatorHeights)
	{
		if (ElevatorHeights<0)
		{
			cout << "���������" << ElevatorHeights << " " << "����������������������" << endl;
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
		cout << "�����ӳ�ʱ����" << DelayTime << "����" << endl;
	cout << "������������ӳ�ʱ��" << endl;
	while (cin >> DelayTimes) {
		if (DelayTime<0)
		{
			cout << "���������" << DelayTimes << " " << "����������������������" << endl;
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