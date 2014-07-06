#include "Snake.h"
#include <string>
#include<iostream>
using namespace std;

Snake::Snake(void)
{
	boy=8;
	score=-1;
	int t(0);
	for(int i=0;i<25;i++)
		for(int j=0;j<25;j++)
		{
			if(i==0||j==0||i==24||j==24)
			{
				arr[i][j]=3;
			}
			else
				arr[i][j]=0;
		}
		for (int m=10;m<=17;m++){
			arr[10][m]=1;
			yilan[t].xeks=10;
			yilan[t].yeks=m;
			t++;
		}
		yem();
}
int Snake::getboy()const{
	return boy;}
int Snake::getscore()const{
	return score;
}
void Snake::setboy(int lng){
	boy=lng;
}
void Snake::setscore(int scr){
	score=scr;
}
void Snake::print(void)const{
	double m=((0.1*score)+1.8);
	cout<<"seviye:"<<(int)m<<endl;
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			if(arr[i][j]==3){cout<<"[]";printf(" ");}
			else if(arr[i][j]==0){cout<<"   ";}
			else if(arr[i][j]==2){cout<<"@";printf("  ");}
			else if(arr[i][j]==5){cout<<"@@";printf(" ");}
			else {cout<<"O";printf("  ");}
		}
		cout<<endl;
	}
	for(int z=0;z<10000000/m;z++){}
	system("CLS");
}
void Snake::yem(){
	int m,t,de=0;
	score++;
	do{
		t=rand()%25;
		m=rand()%25;
		if(score%5==4)
		{
			if(arr[t][m]==0)
			{
				arr[t][m]=5;de=1;
				score++;
			}
		}
		else if(arr[t][m]==0)
		{
			arr[t][m]=2;de=1;
		}
	}while(de==0);
}
char Snake::up(void){
	int i;
	if(arr[(yilan[0].xeks)-1][yilan[0].yeks]==2||arr[(yilan[0].xeks)-1][yilan[0].yeks]==5)
	{
		for(i=boy;i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks--;
		for(i=boy;i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		boy++;
		yem();
		return 'w';
	}
	else if((arr[(yilan[0].xeks)-1][yilan[0].yeks]==3)||(arr[(yilan[0].xeks)-1][yilan[0].yeks]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[boy-1].xeks][yilan[boy-1].yeks]=0;
		for(i=(boy-1);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks--;
		for(i=(boy-1);i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		return 'w';
	}
}
char Snake::down(){
	int i;
	if(arr[(yilan[0].xeks)+1][yilan[0].yeks]==2||arr[(yilan[0].xeks)+1][yilan[0].yeks]==5)
	{
		for(i=boy;i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks++;
		for(i=boy;i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		boy++;
		yem();
		return 's';
	}
	else if((arr[(yilan[0].xeks)+1][yilan[0].yeks]==3)||(arr[(yilan[0].xeks)+1][yilan[0].yeks]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[boy-1].xeks][yilan[boy-1].yeks]=0;
		for(i=boy-1;i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].xeks++;
		for(i=boy-1;i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		return 's';
	}
}
char Snake::sol(){
	int i;
	if(arr[(yilan[0].xeks)][(yilan[0].yeks)-1]==2||arr[(yilan[0].xeks)][(yilan[0].yeks)-1]==5)
	{
		for(i=boy;i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].yeks--;
		for(i=boy;i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		boy++;
		yem();
		return 'a';
	}
	else if((arr[yilan[0].xeks][(yilan[0].yeks)-1]==3)||(arr[yilan[0].xeks][(yilan[0].yeks)-1]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[boy-1].xeks][yilan[boy-1].yeks]=0;
		for(i=(boy-1);i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].yeks--;
		for(i=(boy-1);i>=0;i--)
		{
			arr[yilan[0].xeks][yilan[0].yeks]=1;
		}
		return 'a';
	}
}
char Snake::sag(){
	if(arr[(yilan[0].xeks)][(yilan[0].yeks)+1]==2||arr[yilan[0].xeks][(yilan[0].yeks)+1]==5)
	{
		int i;
		for(i=boy;i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		(yilan[0]).yeks++;
		for(i=boy;i>=0;i--)
		{
			arr[(yilan[i]).xeks][(yilan[i]).yeks]=1;
		}
		boy++;
		yem();
		return 'd';
	}
	else if((arr[(yilan[0]).xeks][((yilan[0]).yeks)+1]==3)||(arr[(yilan[0]).xeks][((yilan[0]).yeks)+1]==1))
	{
		return 'm';
	}
	else
	{
		arr[yilan[boy-1].xeks][yilan[boy-1].yeks]=0;
		for(int i=boy-1;i>0;i--)
		{
			yilan[i]=yilan[i-1];
		}
		yilan[0].yeks++;
		for(int i=boy-1;i>=0;i--)
		{
			arr[yilan[i].xeks][yilan[i].yeks]=1;
		}
		return 'd';
	}
}
char Snake::ters(char ok,char ok2)const{
	if (ok2=='d')
	{
		if(ok=='a'){return 'a';}
		else{return(ok2);}
	}
	else if(ok2=='a')
	{
		if(ok=='d'){return 'd';}
		else{return(ok2);}
	}
	else if(ok2=='s')
	{
		if(ok=='w'){return 'w';}
		else{return (ok2);}
	}
	else if(ok2=='w')
	{
		if(ok=='s'){return 's';}
		else{return (ok2);}
	}
	else if(ok2=='p'){return (ok2);}
	else
	{
		return(ok);
	}
}