#include "stdafx.h"
#include "all.h"
void Menu1()
{
	printf("������Ϊһ�����ݷ�����򣬷����������ݵ��������У��ṩ���¹��ܣ�\n");
	printf("1. ָ���û�ָ���ļ�����Ĭ���棨ֻ����������ļ���\n");
	printf("2. ָ���û�ָ���ļ����������棨������������ļ���\n");
	printf("3. ָ���û�ָ���ļ���ȫ����棨����ʾ���������������ļ�)\n");
	printf("4.ָ����ʷ�����ļ���������ʽ�ط�\n");
	printf("5.�޸�ϵͳ����\n");
	printf("0. �˳�\n");
	printf("��������Ҫִ�еĹ�����ţ�\n");
	return;

}
void Menu2()
{
	printf("����ǰ���ڡ���Ĭ���桱ģ�飬��ѡ��Ҫ���еĲ�����\n");
	printf("1. �����û�ָ���ļ����ƣ���ʼ��Ĭ����\n");
	printf("0. �����ϼ��˵�\n");
	printf("����������Ҫ���еĲ�����ţ�\n");
	return;
}
void Menu3()
{
	printf("����ǰ���ڡ��������桱ģ�飬��ѡ��Ҫ���еĲ�����\n");
	printf("1. �����û�ָ���ļ����ƣ���ʼ��������\n");
	printf("0. �����ϼ��˵�\n");
	printf("����������Ҫ���еĲ�����ţ�\n");
	return;
}
void Menu5()
{
	printf("����ǰ���ڡ�ȫ����桱ģ�飬��ѡ��Ҫ���еĲ�����\n");
	printf("1. �����û�ָ���ļ����ƣ���ʼȫ�����\n");
	printf("0. �����ϼ��˵�\n");
	printf("����������Ҫ���еĲ�����ţ�\n");
	return;
}
void Menu4()
{
	printf("����ǰ���ڡ���ʷ�����ļ��طš�ģ�飬��ѡ��Ҫ���еĲ�����\n");
	printf("1. �����û�ָ���ļ����ƣ���ʼ�����ļ��ط�\n");
	printf("0. �����ϼ��˵�\n");
	printf("����������Ҫ���еĲ�����ţ�\n");
	return;
}
void Menu6()
{
	printf("����ǰ���ڡ�ϵͳ�������á�ģ�飬��ѡ��Ҫ���õĲ�����\n");
	printf("1. �����û�ָ���ļ����Ŀ¼\n");
	printf("2. ������ʷ�����ļ����Ŀ¼\n");
	printf(
		"3. ���õ����ܲ���\n");
	printf("4. ���õ��ݶ�������ʱ���ӳ�ϵ��\n");
	printf("0. �����ϼ��˵�\n");
	printf("����������Ҫ�������õĲ�����ţ�\n");
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
				printf("�������!\n");
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
				printf("�������!\n");
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
				printf("�������!\n");
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
				printf("�������!\n");
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
				printf("�������!\n");
		}else if (menu_flag == 0) {
			return;
		}
		else
		{
			printf("����������������룡\n");
		}
	}
	return;
}