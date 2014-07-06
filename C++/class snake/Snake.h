#ifndef SNAKE
#define SNAKE
#include<iostream>
using namespace std;
struct ylan{
	int xeks;
	int yeks;
};
class Snake
{
private:
	int boy;
	int score;
	int arr[25][25];
	struct ylan yilan[625];
public:
	Snake(void);
	int getboy (void)const;
	int getscore(void)const;
	void setboy(int);
	void setscore(int);
	void print (void)const;
	void yem(void);
	char up(void);
	char down(void);
	char sag(void);
	char sol(void);
	char ters(char,char)const;	
};
#endif
