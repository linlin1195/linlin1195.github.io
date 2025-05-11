#include <iostream>
#include <cstdio>
#include <windows.h>
#include <ctime>
#include <cstdlib>
using namespace std;
const char Edition[100]="The linker zty 1.3.4";
double cps=50;
int up,down;
int main() {
	HWND hwndDOS=GetForegroundWindow();
	ShowWindow(hwndDOS,SW_HIDE);
	MoveWindow(hwndDOS,150,150,400,300,true);
	MessageBox(NULL,"\n\t按左箭头呼出菜单",Edition,MB_OK);
	srand(time(0));
	while(1) {
		if(GetAsyncKeyState(VK_UP)) {
			while(1) {
				/*if(GetAsyncKeyState(VK_UP)){
					++up;
					if(up>20&&cps<900)++cps,up=0;
				}

				if(GetAsyncKeyState(VK_DOWN)){
					++down;
					if(down>20&&cps>10)--cps,down=0;
				}*/
				mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
				if(GetAsyncKeyState(VK_DOWN))break;

				Sleep(1000/cps);
			}
		}
		if(GetAsyncKeyState(VK_LEFT)) {
			ShowWindow(hwndDOS,SW_RESTORE);
			system("cls");
			printf("\n\t基本操作:上箭头开始,下箭头停止\n\n\t右箭头退出,左箭头呼出菜单\n\n\t请输入每秒点击次数:\n\n\t(不要超过100，否则会炸掉)");
			scanf("%d",&cps);
//    		cout<<1000/cps;
//			Sleep(1000);
			ShowWindow(hwndDOS,SW_HIDE);
		}
		if(GetAsyncKeyState(VK_RIGHT))break;
	}
	MessageBox(NULL,"\n\t成功退出",Edition,MB_OK);
	return 0;
}
