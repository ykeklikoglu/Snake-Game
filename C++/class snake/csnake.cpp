#include "Snake.h"
#include <string>
#include<conio.h>
#include<time.h>
#include<iostream>
using namespace std;
int main(void){
	srand(time(NULL));
	system ("color 4F");
	char ok,ok2,ok3;
	Snake snake;
	do{
		cout<<"Uyari:Oyun w,a,s,d tuslariyla oynanmaktadir.\n@=1\n@@=2puan\nOyunda yilanin hizi seviye ile zamanla degisebilir.\n\nOyunu tam ekrana aliniz.\nbaslamak icin 'a'ye basiniz.\nOyunu duraklatmak icin 'p' ye basiniz\n";
		cin>>ok;}while(ok!='a');
		do{
			switch(ok)
			{
			case 'w':ok=snake.up();break;
			case 's':ok=snake.down();break;
			case 'd':ok=snake.sag();break;
			case 'a':ok=snake.sol();break;
			case 'p':system("pause");ok=ok3;
			}
			ok2=ok;
			ok3=ok;
			snake.print();
			if(ok=='m'){break;}
			if(kbhit( )){ok2=getch();ok=snake.ters(ok,ok2);}
		}while(!(ok=='m'));
		cout<<"\noyun bitti.\n";printf("\nscore=%d\n",snake.getscore());cout<<"\ncikis icin bir tusa basin.\n";ok=getch();
		printf("\nBYE BYE\n");
		return(0);
}