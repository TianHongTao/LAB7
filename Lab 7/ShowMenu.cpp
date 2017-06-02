#include "stdafx.h"
#include "all.h"
void Menu1()
{
	printf("本程序为一个电梯仿真程序，仿真两部电梯的联动运行，提供如下功能：\n");
	printf("1. 指定用户指令文件，静默仿真（只输出仿真结果文件）\n");
	printf("2. 指定用户指令文件，动画仿真（不输出仿真结果文件）\n");
	printf("3. 指定用户指令文件，全面仿真（即显示动画，又输出结果文件)\n");
	printf("4.指定历史仿真文件，动画形式回放\n");
	printf("5.修改系统参数\n");
	printf("0. 退出\n");
	printf("请输入您要执行的功能序号：\n");
	return;

}
void Menu2()
{
	printf("您当前处于“静默仿真”模块，请选择要进行的操作：\n");
	printf("1. 输入用户指令文件名称，开始静默仿真\n");
	printf("0. 返回上级菜单\n");
	printf("请输入您需要进行的操作序号：\n");
	return;
}
void Menu3()
{
	printf("您当前处于“动画仿真”模块，请选择要进行的操作：\n");
	printf("1. 输入用户指令文件名称，开始动画仿真\n");
	printf("0. 返回上级菜单\n");
	printf("请输入您需要进行的操作序号：\n");
	return;
}
void Menu5()
{
	printf("您当前处于“全面仿真”模块，请选择要进行的操作：\n");
	printf("1. 输入用户指令文件名称，开始全面仿真\n");
	printf("0. 返回上级菜单\n");
	printf("请输入您需要进行的操作序号：\n");
	return;
}
void Menu4()
{
	printf("您当前处于“历史仿真文件回放”模块，请选择要进行的操作：\n");
	printf("1. 输入用户指令文件名称，开始仿真文件回放\n");
	printf("0. 返回上级菜单\n");
	printf("请输入您需要进行的操作序号：\n");
	return;
}
void Menu6()
{
	printf("您当前处于“系统参数配置”模块，请选择要配置的参数：\n");
	printf("1. 配置用户指令文件存放目录\n");
	printf("2. 配置历史仿真文件存放目录\n");
	printf(
		"3. 配置电梯总层数\n");
	printf("4. 配置电梯动画仿真时的延迟系数\n");
	printf("0. 返回上级菜单\n");
	printf("请输入您需要重新配置的参数序号：\n");
	return;
}
void  ShowMenu(int  menu_flag)
{
	int flag=0;
	while (flag != 500)
	{

		Menu1();
		scanf("%d", &menu_flag);
		if (menu_flag == 1) {
			Menu2();
			scanf("%d", &flag);
			if (flag == 0)
				continue;
			else if (flag == 1)
			{
				SilenceSimulate();
				continue;
			}
			else
				printf("输入错误!\n");
		}
		else if (menu_flag == 2) {
			Menu3();
			scanf("%d", &flag);
			if (flag == 0)
				continue;
			else if (flag == 1)
			{

				continue;
			}
			else
				printf("输入错误!\n");
		}
		else if (menu_flag == 3) {
			Menu4();
			scanf("%d", &flag);
			if (flag == 0)
				continue;
			else if (flag == 1)
			{

				continue;
			}
			else
				printf("输入错误!\n");
		}
		else if (menu_flag == 4) {
			Menu5();
			scanf("%d", &flag);
			if (flag == 0)
				continue;
			else if (flag == 1)
			{

				continue;
			}
			else
				printf("输入错误!\n");
		}else if(menu_flag == 5) {
			Menu6();
			scanf("%d", &flag);
			if (flag == 0)
				continue;
			else if (flag == 1)
			{
				ParamConf1();
				continue;
			}
			else if (flag == 2)
			{
				ParamConf2();
			}
			else if (flag == 3)
			{
				ParamConf3();
			}
			else if (flag == 4)
			{
				ParamConf4();
			}
			else if (flag == 0)
			{
				continue;
			}
			else 
				printf("输入错误!\n");
		}else if (menu_flag == 0) {
			return;
		}
		else
		{
			printf("输入错误请重新输入！\n");
		}
	}
	return;
}