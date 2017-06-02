#include"stdafx.h"
#include"all.h"
void  SilenceSimulate()
{	
	char use[MAX];
	char temp[] = "";
	cout << "请输入文件名" << endl;
	cin >> user_file_name;
	strcpy(UserRequestFilePath, temp);
	strcpy(use,UserRequestFilePath);
	strcat(use,user_file_name);
	while (_access(use,0) != 0)
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
	while ((fp = fopen(use, "r") )== NULL)
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
	}
	while (LoadUserCallArray(fp) == 0)
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
		while ((fp = fopen(use, "r")) == NULL)
		{
			printf("指令用户文件打开错误\n");
			while (_access(use, 0) != 0)
			{
				printf("指令用户文件不存在\n");
				strcpy(UserRequestFilePath, temp);
				strcpy(use, UserRequestFilePath);
				strcat(use, user_file_name);		strcat(use, user_file_name);
			}
			InitSimulation();
		}
	}
	while (OutputSimulationResult() == 0)
	{
		cout << "请输入文件名" << endl;
		cin >> user_file_name;
		strcpy(UserRequestFilePath, temp);
		strcpy(use, UserRequestFilePath);
		strcat(use, user_file_name);
		while (_access(use, 0) != 0)
		{
			printf("指令用户文件不存在\n");
			strcpy(UserRequestFilePath, temp);
			strcpy(use, UserRequestFilePath);
			strcat(use, user_file_name);		strcat(use, user_file_name);
		}
		InitSimulation();
		while ((fp = fopen(use, "r")) == NULL)
		{
			printf("指令用户文件打开错误\n");
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
		}
		while (LoadUserCallArray(fp) == 0)
		{
			cout << "请输入文件名" << endl;
			cin >> user_file_name;
			strcpy(UserRequestFilePath, temp);
			strcpy(use, UserRequestFilePath);
			strcat(use, user_file_name);
			while (_access(use, 0) != 0)
			{
				printf("指令用户文件不存在\n");
				strcpy(UserRequestFilePath, temp);
				strcpy(use, UserRequestFilePath);
				strcat(use, user_file_name);		strcat(use, user_file_name);
			}
			InitSimulation();
			while ((fp = fopen(use, "r")) == NULL)
			{
				printf("指令用户文件打开错误\n");
				while (_access(use, 0) != 0)
				{
					printf("指令用户文件不存在\n");
					strcpy(UserRequestFilePath, temp);
					strcpy(use, UserRequestFilePath);
					strcat(use, user_file_name);		strcat(use, user_file_name);
				}
				InitSimulation();
			}
		}
	}
	return;
}

void InitElevator(ELEVATORSTATE  *elevator)
{
	elevator->current_floor = 1;
	elevator->run_state = 'S';
	while (elevator->serve_list != NULL)
	{
		SERVELISTNODE *p = elevator->serve_list;
		if (elevator->serve_list->next_node == NULL)
			elevator->serve_list = elevator->serve_list->next_node;
		else
			elevator->serve_list = NULL;
		free(p);
	}
	return;
}
void  InitSimulation()
{
	if (usercall_list != NULL)
	{
		free(usercall_list);
		usercall_list = NULL;
	}
		usercall_list_len = 0;
		finish_call_num = 0;
		if (response_list->head!=NULL)
		{
			while (response_list->head != NULL)
			{
				RESPONSELISTNODE *p;
				p = response_list->head;
				response_list->head = response_list->head->next_node;
				free(p);
				p = NULL;
			}
			response_list = (RESPONSELISTHEADNODE*)malloc(sizeof(RESPONSELISTHEADNODE));
			response_list->head = NULL;
			response_list->tail = NULL;
			response_list->list_num = 0;
			InitElevator(&elevator_a);
			InitElevator(&elevator_b);
		}
		else
		{
			response_list = (RESPONSELISTHEADNODE*)malloc(sizeof(RESPONSELISTHEADNODE));
			response_list->head = NULL;
			response_list->tail = NULL;
			response_list->list_num = 0;
			InitElevator(&elevator_a);
			InitElevator(&elevator_b);
		}
		return;
}

int  LoadUserCallArray(FILE  *fp)
{
	int result;
	fscanf(fp, "%d", &usercall_list_len);
	usercall_list = (USERCALL *)calloc(usercall_list_len, sizeof(USERCALL));
	int item_num = 0;
	while (fscanf(fp, "%d,%d,%d", &usercall_list[item_num].user_floor, &usercall_list[item_num].user_target, &usercall_list[item_num].call_time)!=EOF)
	{
		if (usercall_list[item_num].user_floor < usercall_list[item_num].user_target)
			usercall_list[item_num].call_type = 'U';
		else if (usercall_list[item_num].user_floor > usercall_list[item_num].user_target)
			usercall_list[item_num].call_type = 'D';
		else
			usercall_list[item_num].call_type = 'S';
		item_num++;
	}
	if (item_num == usercall_list_len)
	{
		result = 1;
	}
	else
		result = 0;
	return result;
}
void ImportUserCall(FILE *fp)
{
	fprintf(fp, "%d", usercall_list_len);
	for (int i = 0; i < usercall_list_len; i++)
	{
		fprintf(fp, "%d%d%d%c\n", usercall_list->user_floor, usercall_list->user_target, usercall_list->call_time, usercall_list->call_type);
	}
	fprintf(fp, "*************************\n");
	return;
}

void GerNextTimeStatusModule1()
{
	RESPONSELISTNODE  *p;
	p = (RESPONSELISTNODE*)malloc(sizeof(RESPONSELISTNODE));
	p->usercall_index = 0;
	p->next_node = NULL;
	response_list->head = p;
	response_list->tail = p;
	response_list->list_num = 1;
	status_change_flag = 1;
}

void GerNextTimeStatusModule2()
{
	int i = response_list->tail->usercall_index;
	while ( (i + 1) < usercall_list_len)
	{
		if (usercall_list[i + 1].call_time > time)
			return;
		else
		{
		RESPONSELISTNODE  *p;
		p = (RESPONSELISTNODE*)malloc(sizeof(RESPONSELISTNODE));
		p->usercall_index = i + 1;
		p->next_node = NULL;
		response_list->tail->next_node = p;
		response_list->tail = p;
		response_list->list_num++;
		status_change_flag = 1;
		i += 1;
		}
	}
	return;
}

void GetNextTimeStatus(ELEVATORSTATE  *elevator)
{
	int index = 0;
	if (response_list->head != NULL)
		GerNextTimeStatusModule2();
	else
	{
		while (elevator->serve_list!=NULL && elevator->serve_list->next_node==NULL)
		{
			elevator->serve_list = elevator->serve_list->next_node;
			index++;
		}
		if (usercall_list[index].call_time <= time)
		{
		GerNextTimeStatusModule1();
		GerNextTimeStatusModule2();
		}
	}
	if (elevator->serve_list == NULL)
	{
		if (response_list->head == NULL)
		{
			SetElevatorState(elevator);
			return;
		}
		else
		{
			elevator->serve_list = (ServeListNode*)malloc(sizeof(ServeListNode));
			elevator->serve_list->user_call = &usercall_list[response_list->head->usercall_index];
			elevator->serve_list->next_node = NULL;
			status_change_flag = 1;
			if (response_list->head == response_list->tail)
			{
				free(response_list->head);
				response_list->head = NULL;
				response_list->tail = NULL;
				response_list->list_num = 0;
			}
			else
			{
				ResponseListNode *q=response_list->head;
				response_list->head = response_list->head->next_node;
				free(q);
				q = NULL;
			}
			if (elevator->current_floor == elevator->serve_list->user_call->user_floor)
				elevator->serve_list->serve_state = 'E';
			else
				elevator->serve_list->serve_state = 'P';
			FindUserCallCanServe(elevator, GetElevatorDirection(elevator));
			SetElevatorState(elevator);
		}
	}
	else
	{
		if (elevator->run_state == 'S')
		{
			if (GetElevatorDirection(elevator) == 'S' || GetElevatorDirection(elevator) == ' ')
			{
				SetElevatorState(elevator);
			}
			else
			{
				FindUserCallCanServe(elevator, GetElevatorDirection(elevator));
				SetElevatorState(elevator);
			}
		}
		else
		{
			FindUserCallCanServe(elevator, GetElevatorDirection(elevator));
			SetElevatorState(elevator);
		}
	}

}

void  FindUserCallCanServe(ELEVATORSTATE  *elevator, char r_state)
{
	int uf = elevator->serve_list->user_call->user_floor;
	char us = elevator->serve_list->user_call->call_type;
	char ue = elevator->run_state;
	if (response_list->head == NULL)
		return;
	else
	{
		ResponseListNode *r, *k, *p;
		r = k = p = response_list->head;
		int m = elevator->current_floor;
		while (p != NULL)
		{
			int i = p->usercall_index;
			int f = usercall_list[i].user_floor;
			char s = usercall_list[i].call_type;
			int t = usercall_list[i].user_target;
			int judge = -1;//用来判断r_state模块的正确与否（0 假 1 真 -1 没进行判断）
			if (uf != r_state)
			{
				if (
					(r_state == 'U' && s == 'U' && f >= m && t <= uf)
					||
					(r_state == 'D' && s == 'D' && f <= m && t >= uf)
					||
					(ue == 'S' && f == m && r_state == 'U'  && t <= uf)
					||
					(ue == 'S' && f == m && r_state == 'D'  && t >= uf)
					)
					judge = 1;
				else
					judge = 0;
			}
			else
			{
				if (
					(r_state == 'U' && s == 'U' && f > m)
					||
					(r_state == 'D' && s == 'D' && f < m)
					||
					(ue == 'S' && f == m)
					)
					judge = 1;
				else
					judge = 0;
			}
			if (judge == 0)
			{
				if (p->next_node == NULL)
					return;
				else
				{
					if (p == response_list->head)
					{
						p = p->next_node;
						k = p->next_node;
					}
					else
					{
						r = p;
						p = k;
						k = p->next_node;
					}
					continue;
				}
			}
			else
			{
				int i = 0;
				SERVELISTNODE *q;
				elevator->serve_list = (SERVELISTNODE *)malloc(sizeof(ResponseListNode));
				elevator->temp = elevator->serve_list;
				q = elevator->serve_list;
				q->user_call = usercall_list + 1;
				q->next_node = NULL;
				if (f != m)
					q->serve_state = 'P';
				else
					q->serve_state == 'E';
				while (elevator->temp!=NULL)
				{
					elevator->temp = elevator->temp->next_node;
				}
				elevator->temp = q;
				status_change_flag = 1;
				if (p->next_node == NULL)
				{
					if (p == response_list->head)
					{
						response_list->head = NULL;
						response_list->tail = NULL;
						response_list->list_num = 0;
						free(p);
						r = k = p = NULL;
					}
					else
					{
						response_list->tail = r;
						r->next_node = NULL;
						response_list->list_num--;
						free(p);
						p = NULL;
					}
					return;
				}
				else
				{
					if (p == response_list->head)
					{
						response_list->head = p->next_node;
						free(p);
						r = k = p = response_list->head;
						response_list->list_num--;
					}
					else
					{
						r->next_node = k;
						free(p);
						p = k;
						k = k->next_node;
						response_list->list_num--;
					}
				}
				//p = p->next_node;
			}
			return;
		}
	}
}

char  GetElevatorDirection(ELEVATORSTATE  *elevator)
{
	char e_status=' ';
	if (elevator == NULL)
		e_status = 'S';
	else
	{
		SERVELISTNODE *p = elevator->serve_list;
		int m = elevator->current_floor;
		if (p->serve_state == 'p')
		{
			int f = p->user_call->user_floor;
			if (f > m)
				e_status = 'U';
			else
				e_status = 'D';
		}
		else
		{
			if (p->serve_state == 'E')
				return e_status;
			else
			{
				int t = p->user_call->user_target;
				if (t > m)
					e_status = 'U';
				else
					e_status = 'D';
			}
		}
	}
	return e_status;
}

void  SetElevatorState(ELEVATORSTATE  *elevator)
{
	int m = elevator->current_floor;
	char e_rs = elevator->run_state;
	int step_flag = 0;
	if (elevator->serve_list == NULL)
	{
		elevator->current_floor = elevator->current_floor + step_flag;
		return;
	}
	else
	{
		int f = 0, t = 0;
		char s;
		ServeListNode *r, *k, *p;
		r = k = p = elevator->serve_list;
		while (p != NULL)
		{
			f = p->user_call->user_floor;
			t = p->user_call->user_target;
			s = p->serve_state;
			if (e_rs == 'U')
			{
				step_flag = 1;
				if (s == 'E'&&t == m + 1)
				{
					elevator->run_state = 'S';
					status_change_flag = 1;
					if (p->next_node = NULL)
					{
						if (p == elevator->serve_list)
						{
							elevator->serve_list = NULL;
							free(p);
							r = k = p = NULL;
						}
						else
						{
							r->next_node = NULL;
							free(p);
							k = p = NULL;
						}
						finish_call_num++;
					}
					else
					{
						if (elevator->serve_list == p)
						{
							elevator->serve_list = p->next_node;
							free(p);
							r = k = p = elevator->serve_list;
						}
						else
						{
							r->next_node = k;
							free(p);
							p = k;
							k = k->next_node;
						}
						finish_call_num++;
					}
				}
				else
				{
					if (s == 'p' && f == m + 1)
					{
						elevator->run_state = 'S';
						p->serve_state = 'E';
						status_change_flag = 1;
					}
					p = p->next_node;
				}
			}
			else
			{
				if (e_rs == 'D')
				{
					step_flag = -1;
					if (s == 'E'&&t == m - 1)
					{
						elevator->run_state = 'S';
						status_change_flag = 1;
						if (p->next_node = NULL)
						{
							if (p == elevator->serve_list)
							{
								elevator->serve_list = NULL;
								free(p);
								r = k = p = NULL;
							}
							else
							{
								r->next_node = NULL;
								free(p);
								k = p = NULL;
							}
							finish_call_num++;
						}
						else
						{
							if (elevator->serve_list == p)
							{
								elevator->serve_list = p->next_node;
								free(p);
								r = k = p = elevator->serve_list;
							}
							else
							{
								r->next_node = k;
								free(p);
								p = k;
								k = k->next_node;
							}
							finish_call_num++;
						}
					}
					else
					{
						if (s == 'P'&&f == m - 1)
						{
							elevator->run_state = 'S';
							p->serve_state = 'E';
							status_change_flag = 1;
						}
						p = p->next_node;
					}
				}
				else
				{
					if (s == 'P')
					{
						if (f > m)
						{
							elevator->run_state = 'U';
							elevator->run_state = 'D';
						}
						status_change_flag = 1;
						elevator->current_floor += step_flag;
						return;
					}
					else
					{
						if (s == 'E')
						{
							if (t > m)
								elevator->run_state = 'U';
							else
								elevator->run_state = 'D';
							status_change_flag = 1;
							elevator->current_floor += step_flag;
							return;
						}
						else
						{
							elevator->current_floor += step_flag;
							return;
						}
					}
				}
			}
		}
		elevator->current_floor += step_flag;
		return;
	}
}

void ImportSimulateParam(FILE *fp)
{
	FILE *p = fp;
	while (feof(p))
	{
		p++;
	}
	fprintf(p, "%s%s%s", ElevatorHeight,Elevatorspeed, DelayTime);
	fprintf(p, "**********************\n");
}

void  ImportSimulateResult(FILE *fp)
{
	ServeListNode *z;
	z = elevator_a.serve_list;
	ServeListNode *q;
	q = elevator_b.serve_list;
	FILE *p = fp;
	while (!feof(p))
	{
		p++;
	}
	char Anow[MAX];
	sprintf(Anow, "%d,A,%d,%c,B,%d,%c",
		elevator_a.serve_list->user_call->call_time,
		elevator_a.current_floor,
		elevator_a.run_state,
		elevator_b.current_floor,
		elevator_b.run_state);
	char Await[MAX];
	while (elevator_a.serve_list->next_node = NULL)
	{
		sprintf(Await, "<%d>,<%d>,<%d>,<%c>,<A>"
			, elevator_a.serve_list - z+1
			, elevator_a.serve_list->user_call->user_floor
			,elevator_a.serve_list->user_call->user_target
			,elevator_a.run_state);
		elevator_a.serve_list = elevator_a.serve_list->next_node;
	}
	char Bwait[MAX];
	while (elevator_b.serve_list->next_node = NULL)
	{
		sprintf(Bwait, "<%d>,<%d>,<%d>,<%c>,<B>"
			, elevator_b.serve_list - q + 1
			, elevator_a.serve_list->user_call->user_floor
			, elevator_a.serve_list->user_call->user_target
			, elevator_a.run_state);
		elevator_b.serve_list = elevator_b.serve_list->next_node;
	}
	char Rwait[MAX];
	while (response_list->head!=NULL)
	{
		sprintf(Rwait, "<%d>,<%d>,<%d>,<N>,<N>"
			, response_list->head->usercall_index
			, usercall_list[response_list->head->usercall_index].user_floor
			, usercall_list[response_list->head->usercall_index].user_target);
		response_list->head = response_list->head->next_node;
	}

}

int OutputSimulationResult()
{
	strcat(UserRequestFilePath, "_SimResult");
	int fun_result = 1;
	FILE *fp;
	if ((fp = fopen(UserRequestFilePath, "w+")) == NULL)
	{		fun_result = 0;
	        return fun_result;
    }
	ImportUserCall(fp);
	ImportSimulateParam(fp);
	time = 0;
	while (finish_call_num != usercall_list_len)
	{
		status_change_flag = 0;
		GetNextTimeStatus(&elevator_a);
		GetNextTimeStatus(&elevator_b);
		if (status_change_flag == 1)
		{
			ImportSimulateResult(fp);
			time++;
		}
		else
			time++;
	}
	fclose(fp);
	fun_result = 1;
	return fun_result;
}
