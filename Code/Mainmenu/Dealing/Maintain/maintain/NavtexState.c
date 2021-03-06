#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include  "run.h"
#include "define.h"	
#include "lcddrive.h"
#include "run.h"
#include "code.h"

/*****************************************/
/*	功能：接收机所选海区状态的显示
入口参数：无
出口参数：无
/*****************************************/
void NavtexState_Paint(); 
void NavtexState_Paint()
{
 	char i;
 	if(Mode==0)				//自动模式
 	{
		for(i=0;i<=25;i++) 	//518接受发射台的情况
		{
			word temp,temp1;
			temp1=Power(BUFFER2[0]-1);
			temp=Auto[0][i]&temp1;
//			temp=Auto[0][i]&(word)(pow(2,BUFFER2[0]-1));	
			
			if(temp!=0) CTAB[i]=i+65;
			else CTAB[i]='-';
		}
		CW_PR(7,7,26);
		
		for(i=0;i<=25;i++) 	//490接受发射台的情况
		{
			word temp,temp1;
			temp1=Power(BUFFER2[0]-1);
			temp=Auto[1][i]&temp1;
			
//			temp=Auto[1][i]&(word)(pow(2,BUFFER2[0]-1));	
			
			if(temp!=0) CTAB[i]=i+65;
			else CTAB[i]='-';

		}
		CW_PR(7,10,26);
		
		for(i=0;i<=25;i++) 	//4209.5接受发射台的情况
		{
			word temp,temp1;
			temp1=Power(BUFFER2[0]-1);
			temp=Auto[2][i]&temp1;
//			temp=Auto[2][i]&(word)(pow(2,BUFFER2[0]-1));	
			
			if(temp!=0) CTAB[i]=i+65;
			else CTAB[i]='-';
		}
		CW_PR(7,13,26);	
 	}
 	
 	if(Mode==1)				//手动模式
 	{

		for(i=0;i<=25;i++) 	//518接受发射台的情况
		{
			if(Manual[0][i]==1) CTAB[i]=i+65;
			else CTAB[i]='-';
		}
		CW_PR(7,7,26);
		
		for(i=0;i<=25;i++) 	//490接受发射台的情况
		{
			if(Manual[1][i]==1) CTAB[i]=i+65;
			else CTAB[i]='-';
		}
		CW_PR(7,10,26);
		
		for(i=0;i<=25;i++) 	//4209.5接受发射台的情况�
		{
			if(Manual[2][i]==1) CTAB[i]=i+65;
			else CTAB[i]='-';
		}
		CW_PR(7,13,26);
 	}
}

/*****************************************/
/*	功能：接收机状态菜单NavvtexState的显示
入口参数：无
出口参数：无
/*****************************************/
void NavtexState_Paintintial();
void NavtexState_Paintintial()
 {	
	byte i;
//	CLEAR1();		//清一区和二区的存储空间
	if(LANGUAGE==0)	//英文菜单
	{
		/* 表头STATUS */
		CTAB[2]='S';	CTAB[3]='T';	CTAB[4]='A';	CTAB[5]='T';
		CTAB[6]='U';	CTAB[7]='S';
		CW_PR(0,1,8);	
	}
	
	else			//中文菜单
	{
		W_XLINE(0,319,25);	
		W_CLEARXLINE(0,319,22);
	
 		CCW_PR1(1,7,0xbdd3,1);	//第一行内容"接收机状态"
 		CCW_PR1(3,7,0xcad5,1);
 		CCW_PR1(5,7,0xbbfa,1);
  		CCW_PR1(7,7,0xd7b4,1);
  		CCW_PR1(9,7,0xccac,1);
	}

	W_Mode(35,6,32,1);			//手动，自动模式的显示	

	/* 航行区选择NAVAREA:11 */
	CTAB[0]='N';	CTAB[1]='A';	CTAB[2]='V';	CTAB[3]='A';
	CTAB[4]='R';	CTAB[5]='E';	CTAB[6]='A';	CTAB[7]=':';
	CTAB[8]='1';	CTAB[9]='1';
	CW_PR(2,5,10);
	

	/* 518KHZ无效接收站 */
	CTAB[5]='5';	CTAB[6]='1';	CTAB[7]='8';	CTAB[8]='K';
	CTAB[9]='H';	CTAB[10]='Z';	CTAB[12]='D';	CTAB[13]='I';
	CTAB[14]='S';	CTAB[15]='A';	CTAB[16]='B';	CTAB[17]='L';
	CTAB[18]='E';	CTAB[19]='D';	CTAB[21]='A';	CTAB[22]='R';
	CTAB[23]='E';	CTAB[24]='A';		
	CW_PR(0,6,25);
	

	/* 490KHZ无效接收站 */
	CTAB[5]='4';	CTAB[6]='8';	CTAB[7]='6';	CTAB[8]='K';
	CTAB[9]='H';	CTAB[10]='Z';	CTAB[12]='D';	CTAB[13]='I';
	CTAB[14]='S';	CTAB[15]='A';	CTAB[16]='B';	CTAB[17]='L';
	CTAB[18]='E';	CTAB[19]='D';	CTAB[21]='A';	CTAB[22]='R';
	CTAB[23]='E';	CTAB[24]='A';		
	CW_PR(0,9,25);
	

	/* 4209.5KHZ无效接收站 */
	CTAB[5]='4';	CTAB[6]='2';	CTAB[7]='0';	CTAB[8]='9';
	CTAB[9]='.';	CTAB[10]='5';	CTAB[11]='K';	CTAB[12]='H';	
	CTAB[13]='Z';	CTAB[15]='D';	CTAB[16]='I';
	CTAB[17]='S';	CTAB[18]='A';	CTAB[19]='B';	CTAB[20]='L';
	CTAB[21]='E';	CTAB[22]='D';	CTAB[24]='A';	CTAB[25]='R';
	CTAB[26]='E';	CTAB[27]='A';		
	CW_PR(0,12,28);
	

	/* 518KHZ无效接收信息类别 */
	CTAB[5]='5';	CTAB[6]='1';	CTAB[7]='8';	CTAB[8]='K';
	CTAB[9]='H';	CTAB[10]='Z';	CTAB[12]='D';	CTAB[13]='I';
	CTAB[14]='S';	CTAB[15]='A';	CTAB[16]='B';	CTAB[17]='L';
	CTAB[18]='E';	CTAB[19]='D';	CTAB[21]='M';	CTAB[22]='S';
	CTAB[23]='G';	CTAB[25]='T';	CTAB[26]='Y';	CTAB[27]='P';	CTAB[28]='E';	
	CW_PR(0,15,29);
	

	/* 490KHZ无效接收信息类别 */
	CTAB[5]='4';	CTAB[6]='8';	CTAB[7]='6';	CTAB[8]='K';
	CTAB[9]='H';	CTAB[10]='Z';	CTAB[12]='D';	CTAB[13]='I';
	CTAB[14]='S';	CTAB[15]='A';	CTAB[16]='B';	CTAB[17]='L';
	CTAB[18]='E';	CTAB[19]='D';	CTAB[21]='M';	CTAB[22]='S';
	CTAB[23]='G';	CTAB[25]='T';	CTAB[26]='Y';	CTAB[27]='P';	CTAB[28]='E';		
	CW_PR(0,18,29);
	

	/* 4209.5KHZ无效接收信息类别 */
	CTAB[5]='4';	CTAB[6]='2';	CTAB[7]='0';	CTAB[8]='9';
	CTAB[9]='.';	CTAB[10]='5';	CTAB[11]='K';	CTAB[12]='H';	
	CTAB[13]='Z';	CTAB[15]='D';	CTAB[16]='I';
	CTAB[17]='S';	CTAB[18]='A';	CTAB[19]='B';	CTAB[20]='L';
	CTAB[21]='E';	CTAB[22]='D';	CTAB[24]='M';	CTAB[25]='S';
	CTAB[26]='G';	CTAB[28]='T';	CTAB[29]='Y';	CTAB[30]='P';	CTAB[31]='E';		
	CW_PR(0,21,32);
	

	for(i=0;i<=25;i++) 	//580接受信息类别的情况
	{
		if(MSGTYPE[0][i]==1) CTAB[i]=i+65;
		else CTAB[i]='-';
	}
	CW_PR(7,16,26);
	
	
	for(i=0;i<=25;i++) 	//490接受信息类别的情况
	{
		if(MSGTYPE[1][i]==1) CTAB[i]=i+65;
		else CTAB[i]='-';
	}
	CW_PR(7,19,26);
	
	for(i=0;i<=25;i++) 	//4209.5接受信息类别的情况
	{
		if(MSGTYPE[2][i]==1) CTAB[i]=i+65;
		else CTAB[i]='-';
	}
	CW_PR(7,22,26);

	CTAB[2]='S';	CTAB[3]='A';	CTAB[4]='V';	CTAB[5]='E';
	CTAB[7]='M';	CTAB[8]='S';	CTAB[9]='G';	CTAB[10]=':';
	CW_PR(0,25,11);		
	
	CTAB[2]='L';	CTAB[3]='O';	CTAB[4]='C';
	CTAB[5]='K';	CTAB[7]='M';	CTAB[8]='S';	CTAB[9]='G';
	CTAB[10]=':';
	CW_PR(0,26,11);
		
 	DISASCIII(11,25,Messageinfo.savenumber[1]); CW_PR3(14,25,';');//显示各通道存储信息情况
 	DISASCIII(15,25,Messageinfo.savenumber[2]); CW_PR3(18,25,';');
  	DISASCIII(19,25,Messageinfo.savenumber[3]); CW_PR3(22,25,';');	
	
	DISASCIII(11,26,Messageinfo.locknumber[1]); CW_PR3(14,26,';');//显示各通道锁定信息情况
 	DISASCIII(15,26,Messageinfo.locknumber[2]); CW_PR3(18,26,';');
  	DISASCIII(19,26,Messageinfo.locknumber[3]); CW_PR3(22,26,';');
 
  	W_YLINE(0,0,239);
	W_YLINE(319,0,239);
	
	NavtexState_Paint();//接收机接收岸台的显示		
 }
/***************************************************/
/*	功能：左右按键处理函数，选择所需查看海区的状态
入口参数：无
出口参数：无
/***************************************************/
void NavtexState_Leftright();
void NavtexState_Leftright()          
{
	if(G_Key==LEFT)
	{
		G_Key=0;
		BUFFER2[0]=(BUFFER2[0]+14)%16+1;
		DISASCII(10,5,BUFFER2[0]);	//显示所选海区
		NavtexState_Paint();		//当前状态的显示
	}

	 else if(G_Key==RIGHT)
	{
		G_Key=0;
		BUFFER2[0]=BUFFER2[0]%16+1;
		DISASCII(10,5,BUFFER2[0]);
		NavtexState_Paint();
	}
}
 
/***************************************************/
/*	功能：返回上一级菜单，MainTain菜单
入口参数：无
出口参数：无
/***************************************************/  
void NavtexState_Return();
void NavtexState_Return()
{
	if(G_Key==CLR)
	{
		G_Key=0;		//按键清零
		BUFFER2[0]=0;	//本菜单全局变量清零
		FLAG=0;			//结束循环
		STATE=44;		//MainTain的状态为44
		State44parameter=0;	
	}
}

/***************************************************/
/*	功能：显示接收机状态：各海区每个通道下设置的
          接收岸台和接收信息类别，显示各通道下所
          接收的信息数
入口参数：无
出口参数：无
/***************************************************/ 
void RunNavtexState()
{
    maske=0;
    maskc=0;
	BUFFER2[0]=11;	//初始化显示的是海区11的接收机状态
	NavtexState_Paintintial();
	while(FLAG)                          
	{
		NavtexState_Leftright();		
		NavtexState_Return();	
		run_tip();		
	}

}