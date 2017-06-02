#ifndef _ALL_H_
#define _ALL_H_
#include"stdafx.h"
#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"io.h"
#include"iostream"
#include"string"
#include "graphics.h"
#include "conio.h"
using  std::string;
using  std::cin;
using  std::cout;
using  std::endl;
#define MAX_PARAM_NAME_LEN 10000
#define MAX_PARAM_VALUE_LEN 10000
#define MAX 10000
/*用户指令数据*/
typedef  struct  UserCall {
	int  user_floor;     	//用户所在楼层
	int  user_target;     //用户目标楼层
	int  call_time;         //用户请求时刻
	char  call_type;       //用户指令类型，´U´表示上行指令，´D´表示下行指令
}USERCALL;
typedef  struct  UserCallInformation {
	USERCALL *usercall_list;
	int usercall_list_len;
}USERCALLINFO;
/*系统参数数据*/
typedef  struct  SysParam {
	char  param_name[MAX_PARAM_NAME_LEN];     	//参数名
	char  param_value[MAX_PARAM_VALUE_LEN];     //参数值
}SYSPARAM;
/*电梯状态数据*/
typedef  struct  ServeListNode {
	char  serve_state;       //电梯服务状态
	USERCALL  *user_call;//电梯当前响应用户指令时，指向指令数组的某一个元素
	struct ServeListNode  *next_node;//存储下一个结点的地址
}SERVELISTNODE;
typedef  struct  elevatorstate {
	int  current_floor;     	//电梯当前所处楼层
	char  run_state;          //电梯运行状态
	SERVELISTNODE  *serve_list;//电梯响应的用户指令队列
	SERVELISTNODE *temp;
}ELEVATORSTATE;
/*电梯待响应指令数据*/
typedef  struct  ResponseListNode {
	int  usercall_index;       //用户指令在指令数组中对应的序号
	struct  ResponseListNode  *next_node;//存储下一个结点的地址
}RESPONSELISTNODE;
typedef  struct  ResponseListHeadNode {
	int  list_num;       //待响应用户指令链表中数据结点的个数
	RESPONSELISTNODE  *head;//链表中第一个数据结点的指针
	RESPONSELISTNODE  *tail;//链表中最后一个数据结点的指针
}RESPONSELISTHEADNODE;
extern char Elevatorspeed[MAX];  //电梯运行速度
extern char UserRequestFilePath[MAX];   //存放用户指令文件的目录，默认值为“*”时，表示与本系统exe文件存放在同一目录下
extern char SimulationFilesPath[MAX];   //存放用户历史仿真文件（历史仿真文件），默认值为“*”时，表示与本系统exe文件存放在同一目录下
extern char ElevatorHeight[MAX];  //电梯总层数
extern char DelayTime[MAX];  //动画展示仿真过程时，每个时刻将电梯状态绘制完毕后，延迟时间，单位为毫秒
extern USERCALL *usercall_list;  //用户指令数组首地址，数组根据用户指令多少动态生成
extern int usercall_list_len;  //用户指令数组长度，从用户指令文件第一行读出
extern SYSPARAM param_array[MAX];  //系统参数数组
extern ELEVATORSTATE elevator_a, elevator_b;  //A、B电梯状态变量
extern RESPONSELISTHEADNODE *response_list;  //电梯响应指令队列，用于指示当前响应的电梯指令
extern char user_file_name[10000];  //用户存放用户指令文件名称的数组，FILE_NAME_LEN为常
extern int finish_call_num;  //用于记录当前已响应完成的用户指令个数
extern int time;  //仿真时间计数器，用于记录当前的仿真时刻
extern int status_change_flag;  //用于记录下一时刻相较于当前时刻电梯状态是否发生了改变，其值为1表示电梯状态发生了改变，为0表示未发生改变
void Menu1();
void Menu2();
void Menu3();
void Menu4();
void Menu5();
void Menu6();
void ShowMenu(int Menu_flag);
void ParamConf4();
void ParamConf3();
void ParamConf2();
void ParamConf1();
void  SilenceSimulate();//静默仿真模块函数
void  InitSimulation();//初始化仿真变量函数
void InitElevator(ELEVATORSTATE  elevator);//初始化电梯状态变量函数
int  LoadUserCallArray(FILE  *fp);//用户指令数组加载数据函数
int OutputSimulationResult();//计算仿真结果并输出为结果文件的函数
void ImportUserCall(FILE *fp);//将用户指令写入仿真结果文件的函数
void ImportSimulateParam(FILE *fp);//将仿真参数写入仿真结果文件的函数
void  GetNextTimeStatus(ELEVATORSTATE  *elevator);//计算电梯下一时刻状态的函数
void  ImportSimulateResult(FILE  *fp);//将电梯当前时刻状态写入仿真结果文件的函数
void  FindUserCallCanServe(ELEVATORSTATE  *elevator, char r_state);//处理当前电梯是否可以同时响应其它用户指令的函数
char  GetElevatorDirection(ELEVATORSTATE  *elevator);//电梯在服务过程中处于停止状态时判断其上下行状态的函数
void  SetElevatorState(ELEVATORSTATE  *elevator);//将电梯状态修改为下一时刻状态的函数
int SystemInit();//自检函数
void  MovieSimulate();//动画仿真模块函数
void  ShowMovie();//显示动画仿真过程函数
void  PaintPicture();//将当前时刻电梯状态绘制成图形的函数
#endif // !ALL_H_
