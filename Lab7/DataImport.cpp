#include"stdafx.h"
#include"all.h"
#include"stdio.h"
#include"stdlib.h"
/*×Ô¼ìº¯Êý*/
int SystemInit()
{
	int param_lenth;
	int Check_result = -1;
	FILE *fp = NULL;
	if (access("SysConf", 0) != 0)
	{
		Check_result = 0;
		return Check_result;
	}
	if (access("SysConf/SysParam.txt", 0) != 0)
	{
		Check_result = -1;
		return Check_result;
	}
	if ((fp = fopen("SysConf/SysParam.txt", "r")) == NULL)
	{
		Check_result = -2;
		return Check_result;
	}
	fscanf(fp,"%d", &param_lenth);
	int param_num = 0;
	int i = 0;
	char temp;
	SysParam *sysparam;
	sysparam = (SysParam *) malloc(param_num*sizeof(SysParam));
	while (
		fscanf(fp, "%*c%[^=]", sysparam->param_name, sysparam->param_value) != EOF &&
		fscanf(fp, "%*c%s", sysparam->param_value) != EOF
		)
	{
		if (strcmp(sysparam->param_name, "UserRequestFilePath") == 0)
		{
			if (strcmp(sysparam->param_value, "*") != 0)
			{
				if (access("UserRequest",0)==-1)
				Check_result = -3;
				fclose(fp);
				free(sysparam);
				return Check_result;
			}
			else
			{
				strcpy(param_array->param_name, sysparam->param_name);
				strcpy(param_array->param_value, sysparam->param_value);
				param_num++;
				sysparam++;
			}
		}else if (strcmp(sysparam->param_name, "SimulationFilePath") == 0) {
			if (strcmp(sysparam->param_value, "*") != 0)
			{
				if (access(sysparam->param_value, 0) != 0)
				{
					fclose(fp);
					free(sysparam);
					Check_result = -4;
					return Check_result;
				}
			}
			else
			{
				strcpy(param_array->param_name, sysparam->param_name);
				strcpy(param_array->param_value, sysparam->param_value);
				param_num++;
				sysparam++;
			}
		}
		else if (strcmp(sysparam->param_name, "ElevatorHeight") == 0) {
			if (strcmp(sysparam->param_value, "2") <= 0)
			{
				fclose(fp);
				free(sysparam);
				Check_result = -5;
				return Check_result;
			}
			else
			{
				strcpy(param_array->param_name, sysparam->param_name);
				strcpy(param_array->param_value, sysparam->param_value);
				param_num++;
				sysparam++;
			}
		}
		else if (strcmp(sysparam->param_name, "Delaytime") == 0) {
			if (strcmp(sysparam->param_value, "0") <= 0)
			{
				fclose(fp);
				free(sysparam);
				Check_result = -6;
				return Check_result;
			}
			else
			{
				strcpy(param_array->param_name, sysparam->param_name);
				strcpy(param_array->param_value, sysparam->param_value);
				param_num++;
				sysparam++;
			}
		}
		else 
		{
			fclose(fp);
			free(sysparam);
			Check_result = -8;
			return Check_result;
		}
	}
	if (param_num != param_lenth)
	{
		fclose(fp);
		free(sysparam);
		Check_result = -7;
		return Check_result;
	}
	fclose(fp);
	free(sysparam);
	return Check_result;
}