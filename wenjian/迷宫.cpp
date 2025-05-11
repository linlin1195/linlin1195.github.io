#include <stdio.h>//fzt123F��Ʒ
#include <conio.h>//fzt123F��Ʒ
#include <windows.h>//fzt123F��Ʒ
#include <time.h>//fzt123F��Ʒ
#define Height 25 //�Թ��ĸ߶ȣ�����Ϊ����
#define Width 25 //�Թ��Ŀ�ȣ�����Ϊ����
#define Wall 1//fzt123F��Ʒ
#define Road 0//fzt123F��Ʒ
#define Start 2//fzt123F��Ʒ
#define End 3//fzt123F��Ʒ
#define Esc 5//fzt123F��Ʒ
#define Up 1//fzt123F��Ʒ
#define Down 2//fzt123F��Ʒ
#define Left 3//fzt123F��Ʒ
#define Right 4//fzt123F��Ʒ
int map[Height+2][Width+2];
void gotoxy(int x,int y){ //�ƶ�����
	COORD coord;//fzt123F��Ʒ
	coord.X=x;//fzt123F��Ʒ
	coord.Y=y;//fzt123F��Ʒ
	SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );//fzt123F��Ʒ
}//fzt123F��Ʒ
void hidden(){//���ع��
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;//��1Ϊ��ʾ����0Ϊ����
	SetConsoleCursorInfo(hOut,&cci);
}
void create(int x,int y){ //���������
	int c[4][2]={0,1,1,0,0,-1,-1,0}; //�ĸ�����
	int i,j,t;
//���������
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
int get_key(){//���հ���
	char c;
while(c=getch()){
	if(c==27) return Esc; //Esc
	if(c!=-32)continue;
	c=getch();
	if(c==72) return Up; //��
	if(c==80) return Down; //��
	if(c==75) return Left; //��
	if(c==77) return Right; //��
}
return 0;
}
void paint(int x,int y){ //fzt123F��ʼ���㻭�Թ�
gotoxy(2*y-2,x-1);
switch(map[x][y]){
	case Start:
	printf("��");break; //����ڣ���Ҫ���������ڵ�������
	case End:
	printf("��");break; //������
	case Wall:
	printf("�~");break; //��ǽ
	case Road:
	printf(" ");break; //��·
	}
}
void game(){
	int x=2,y=1; //��ҵ�ǰλ�ã��տ�ʼ����ڴ�
	int c; //�������հ���
while(1){
	gotoxy(2*y-2,x-1);
	printf("��"); //������ҵ�ǰλ��
if(map[x][y]==End){ //�ж��Ƿ񵽴����
	gotoxy(30,24);
	printf("�����յ㣬�����������");
	printf("\n");
	printf("��fzt123F��Ʒ���������(�s����)�s��");
	getch();
	break;
}
c=get_key();
if(c==Esc){
	gotoxy(0,24);
	break;
}
switch(c){
	case Up: //������
if(map[x-1][y]!=Wall){
	paint(x,y);
	x--;
}
break;
case Down: //������
if(map[x+1][y]!=Wall){
	paint(x,y);
	x++;
}
break;
case Left: //������
if(map[x][y-1]!=Wall){
	paint(x,y);
	y--;
}
break;
case Right: //������
if(map[x][y+1]!=Wall){
	paint(x,y);
	y++;
}
	break;
		}
	}
}
int main(){	//fzt123F��Ʒ
	int i,j;//fzt123F��Ʒ
	srand((unsigned)time(NULL)); //��ʼ���漴����
	hidden(); //���ع��
	for(i=0;i<=Height+1;i++)//fzt123F��Ʒ
	for(j=0;j<=Width+1;j++)//fzt123F��Ʒ
	if(i==0||i==Height+1||j==0||j==Width+1) //��ʼ���Թ�
	map[i][j]=Road;//fzt123F��Ʒ
	else map[i][j]=Wall;//fzt123F��Ʒ
	create(2*(rand()%(Height/2)+1),2*(rand()%(Width/2)+1)); //�����һ���㿪ʼ�����Թ����õ����ж�Ϊż��
	for(i=0;i<=Height+1;i++) {//�߽紦��
		map[i][0]=Wall;//fzt123F��Ʒ
	map[i][Width+1]=Wall;//fzt123F��Ʒ
	}//fzt123F��Ʒ
	for(j=0;j<=Width+1;j++){ //�߽紦��
	map[0][j]=Wall;//fzt123F��Ʒ
	map[Height+1][j]=Wall;//fzt123F��Ʒ
	}//fzt123F��Ʒ
	map[2][1]=Start; //�������
	map[Height-1][Width]=End; //��������
	for(i=1;i<=Height;i++)//fzt123F��Ʒ
	for(j=1;j<=Width;j++) //�����Թ�
	paint(i,j);//fzt123F��Ʒ
	game(); //��ʼ��Ϸ
	getch();//fzt123F��Ʒ
	return 0;//fzt123F��Ʒ
}//fzt123F��Ʒ
