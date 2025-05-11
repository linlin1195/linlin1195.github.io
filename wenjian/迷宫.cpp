#include <stdio.h>//fzt123F出品
#include <conio.h>//fzt123F出品
#include <windows.h>//fzt123F出品
#include <time.h>//fzt123F出品
#define Height 25 //迷宫的高度，必须为奇数
#define Width 25 //迷宫的宽度，必须为奇数
#define Wall 1//fzt123F出品
#define Road 0//fzt123F出品
#define Start 2//fzt123F出品
#define End 3//fzt123F出品
#define Esc 5//fzt123F出品
#define Up 1//fzt123F出品
#define Down 2//fzt123F出品
#define Left 3//fzt123F出品
#define Right 4//fzt123F出品
int map[Height+2][Width+2];
void gotoxy(int x,int y){ //移动坐标
	COORD coord;//fzt123F出品
	coord.X=x;//fzt123F出品
	coord.Y=y;//fzt123F出品
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );//fzt123F出品
}//fzt123F出品
void hidden(){//隐藏光标
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;//赋1为显示，赋0为隐藏
	SetConsoleCursorInfo(hOut,&cci);
}
void create(int x,int y){ //随机生成迷
	int c[4][2]={0,1,1,0,0,-1,-1,0}; //四个方向
	int i,j,t;
//将方向打乱
	for(i=0;i<4;i++){
	j=rand()%4;
	t=c[i][0];c[i][0]=c[j][0];c[j][0]=t;
	t=c[i][1];c[i][1]=c[j][1];c[j][1]=t;
}
map[x][y]=Road;
for(i=0;i<4;i++)
if(map[x+2*c[i][0]][y+2*c[i][1]]==Wall){
	map[x+c[i][0]][y+c[i][1]]=Road;
	create(x+2*c[i][0],y+2*c[i][1]);
	}
}
int get_key(){//接收按键
	char c;
while(c=getch()){
	if(c==27) return Esc; //Esc
	if(c!=-32)continue;
	c=getch();
	if(c==72) return Up; //上
	if(c==80) return Down; //下
	if(c==75) return Left; //左
	if(c==77) return Right; //右
}
return 0;
}
void paint(int x,int y){ //fzt123F开始给你画迷宫
gotoxy(2*y-2,x-1);
switch(map[x][y]){
	case Start:
	printf("入");break; //画入口，主要是怕你把入口当出口了
	case End:
	printf("出");break; //画出口
	case Wall:
	printf("▇");break; //画墙
	case Road:
	printf(" ");break; //画路
	}
}
void game(){
	int x=2,y=1; //玩家当前位置，刚开始在入口处
	int c; //用来接收按键
while(1){
	gotoxy(2*y-2,x-1);
	printf("●"); //画出玩家当前位置
if(map[x][y]==End){ //判断是否到达出口
	gotoxy(30,24);
	printf("到达终点，按任意键结束");
	printf("\n");
	printf("￥fzt123F出品，请勿搬运(╯▔皿▔)╯￥");
	getch();
	break;
}
c=get_key();
if(c==Esc){
	gotoxy(0,24);
	break;
}
switch(c){
	case Up: //向上走
if(map[x-1][y]!=Wall){
	paint(x,y);
	x--;
}
break;
case Down: //向下走
if(map[x+1][y]!=Wall){
	paint(x,y);
	x++;
}
break;
case Left: //向左走
if(map[x][y-1]!=Wall){
	paint(x,y);
	y--;
}
break;
case Right: //向右走
if(map[x][y+1]!=Wall){
	paint(x,y);
	y++;
}
	break;
		}
	}
}
int main(){	//fzt123F出品
	int i,j;//fzt123F出品
	srand((unsigned)time(NULL)); //初始化随即种子
	hidden(); //隐藏光标
	for(i=0;i<=Height+1;i++)//fzt123F出品
	for(j=0;j<=Width+1;j++)//fzt123F出品
	if(i==0||i==Height+1||j==0||j==Width+1) //初始化迷宫
	map[i][j]=Road;//fzt123F出品
	else map[i][j]=Wall;//fzt123F出品
	create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //从随机一个点开始生成迷宫，该点行列都为偶数
	for(i=0;i<=Height+1;i++) {//边界处理
		map[i][0]=Wall;//fzt123F出品
	map[i][Width+1]=Wall;//fzt123F出品
	}//fzt123F出品
	for(j=0;j<=Width+1;j++){ //边界处理
	map[0][j]=Wall;//fzt123F出品
	map[Height+1][j]=Wall;//fzt123F出品
	}//fzt123F出品
	map[2][1]=Start; //给定入口
	map[Height-1][Width]=End; //给定出口
	for(i=1;i<=Height;i++)//fzt123F出品
	for(j=1;j<=Width;j++) //画出迷宫
	paint(i,j);//fzt123F出品
	game(); //开始游戏
	getch();//fzt123F出品
	return 0;//fzt123F出品
}//fzt123F出品
