#include<bits/stdc++.h>
#include<time.h>
#include<windows.h>
#define int long long
#define kd(VK_NONAME) ((GetAsyncKeyState(VK_NONAME)&0x8000)?1:0)
using namespace std;
void gotoxy(int x, int y){
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
}
void noedit(){
	HANDLE hStdin=GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hStdin,&mode);
	mode&=~ENABLE_QUICK_EDIT_MODE;
	mode&=~ENABLE_INSERT_MODE;
	mode&=~ENABLE_MOUSE_INPUT;
	SetConsoleMode(hStdin,mode);
}
void HideCursor(){
	CONSOLE_CURSOR_INFO cur={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cur);
}
string chou(){
	int n=rand()%20;
	if(n>18)return "UR";
	if(n>17)return "SSR";
	if(n>15)return "SR";
	if(n>8)return "R";
	return "N";
}
string chou2(){
	int n=rand()%50;
	if(n>18)return "UR";
	if(n>17)return "SSR";
	if(n>15)return "SR";
	if(n>8)return "R";
	return "N";
}
signed main(){
	cout<<"fzt123F制作，盗作品思慕"<<endl<<endl;
	noedit();
	HideCursor();
	srand(time(NULL));
	char c;
	double mm=0;
	while(1){
		double n=0,m=0;
		for(int j=1;j<=10;j++){
			n=0;
			for(int i=1;i<=20;i++){
				string s=chou();
				printf("%s ",s.c_str());
				if(s=="R")n+=0.2;
				else if(s=="SR")n+=0.5;
				else if(s=="SSR")n+=1;
				else if(s=="UR")n+=2;
			}
			printf("            \n");
			m=max(m,n);
			mm=max(mm,m);
		}
		cout<<"         "<<endl<<"最高稀有值:"<<m<<"       ";
		cout<<"         "<<endl<<"最高纪录:"<<mm<<"       ";
		c=getchar();
		gotoxy(0,0);
	}
	return 0;
}
