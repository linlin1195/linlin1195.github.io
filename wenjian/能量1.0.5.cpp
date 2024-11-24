#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int zong,sheng,bai;
void yxzt();
void cd();
void ckzj();
void gyyx() {
	system("cls");
	printf(" 您好，欢迎您玩能量。");
	cout<<"为了给您更好的游戏体验，";
	Sleep(250);
	cout<<"zty时不时会优化本游戏，";
	Sleep(250);
	cout<<"优化后会尽快发布在网上（CSDN）。";
	Sleep(250);
	cout<<"我们在";
	Sleep(250);
	cout<<"1.";
	Sleep(250);
	cout<<"0.";
	Sleep(250);
	cout<<"4";
	Sleep(250);
	cout<<"版本内容";
	Sleep(250);
	cout<<"的基础上进行改进";
	Sleep(250);
	cout<<"主要内容为添加游戏内可查询游戏规则";
	Sleep(250);
	cout<<"已更新完毕，";
	Sleep(250);
	cout<<"希望大家喜欢。";
	Sleep(250);
	cout<<"\n\n作者CSDN名:zty郑桐羽呀（其他都是盗版）";
	Sleep(250);
	cout<<"\n\n";
	Sleep(250);
	system("color 8E");
	system("pause");
	return;
}
void yxgz() {
	system("cls");
	cout<<"游戏规则：\n\n  1,波（消耗1点能量,可被<波>和<波防>防下,可被<海啸><天雷>打回）是攻击技能\n\n  ";
	cout<<"2,海啸（消耗2点能量,可被<海啸>和<海啸防>防下,可被<天雷>打回）是攻击技能\n\n  ";
	cout<<"3,天雷（消耗3点能量,可被<天雷>防下,不可被打回）是攻击技能\n\n  ";
	cout<<"4,能量（增加1点能量（10轮后为2点）,可被<波><海啸><天雷>打回）是其他技能\n\n  ";
	cout<<"5,波防（不消耗能量,可防下<波>,可被<海啸><天雷>打回）是防守技能\n\n  ";
	cout<<"6,海啸防（不消耗能量,可防下<海啸>,可被<波><天雷>打回）是防守技能\n\n  ";
	cout<<"7,如果自己使用的技能被打回,则失败;如果敌人使用的技能被打回,则胜利。\n\n  ";
	cout<<"8,如果自己或敌人使用的技能被防下,则跳过本轮。\n\n  ";
	cout<<"9,如果双方使用的是同一个技能或都不是攻击技能,则跳过本轮。\n  ";
	system("pause");
	return;
}
void ckzj(int zong,int sheng,int bai) {//查看战绩
	system("cls");
	cout<<"================================================================================\n\n\t   总场数:"<<zong;
	cout<<"\t\t胜场数:"<<sheng;
	cout<<"\t\t败场数:"<<bai;
	cout<<"\n\n\n================================================================================";
	system("pause");
	return;
}
void drcd() { //读入存档
	string line;
	fstream myFile;
	int s=0;
	myFile.open("能量存档.txt", ios::in);  // read,读
	if (myFile.is_open()) {
		while(getline(myFile, line)) {
			string str(line);
			s++;
			if(s==1)
				bai = atoi(str.c_str());
			if(s==2)
				sheng = atoi(str.c_str());
			if(s==3)
				zong = atoi(str.c_str());
		}
		myFile.close();
	}
}
int rgzz(int lun, int dineng, int neng) {//人工智障系统
	while(1) {
		int dichu=0;
		if(lun==1) {
			return 4;
		}
		if(dineng>=3) {
			return 3;
		}
		srand(time(0));
		dichu=rand()%5+1;
		if(dineng==1&&dichu==2||dineng<=2&&dichu==3) continue;
		else if(dineng<1&&dichu<4) continue;
		else if(neng>2&&dichu==6) continue;
		else if(neng<1&&dichu>4) continue;
		else if(neng==0 && (dichu==5 || dichu==6)) continue;
		else return dichu;
	}
}
void ts(int lun,int neng) { //战斗提示
	cout<<"\n第"<<lun<<"轮"<<endl<<"1：波  2：海啸  3：天雷  4：能量  5：防（波）  6:防（海啸） 0:退出游戏  能量："<<neng<<endl;
	return;
}
void cd() {//游戏菜单
	while(1) {
		system("cls");
		system("color 8E");
		cout<<"\n\n================================================================================\n\t\t  1,开始游戏     2,查看战绩     3,查看规则\n\n\t\t  4,关于游戏     5,退出游戏\n\n================================================================================";
		int xuan;
		cin>>xuan;
		switch(xuan) {
			case 1:
				yxzt();
				break;
			case 2:
				ckzj(zong,sheng,bai);
				break;
			case 3:
				yxgz();
				break;
			case 4:
				gyyx();
				break;
			case 5:
				return;
				break;
			default:
				printf("无该选项!\n\n\n");
				Sleep(300);
		}
	}

}
void bccd(int zong,int sheng,int bai) { //保存存档
	char line[256];
	fstream myFile;
	myFile.open("能量存档.txt", ios::out);
	if (myFile.is_open()) {
		myFile<<bai<<"\n";
		myFile<<sheng<<"\n";
		myFile<<zong<<"\n";
		myFile.close();
	}
}
void Bling() { //开始动画
	for(int i=0; i<=1; i++) {
		system("color 1A");
		Sleep(40);
		system("color 2B");
		Sleep(40);
		system("color 3C");
		Sleep(40);
		system("color 4D");
		Sleep(40);
		system("color 5D");
		Sleep(40);
		system("color 6E");
		Sleep(40);
		system("color 7F");
		Sleep(40);
	}
}
void yxzt() { //游戏主体
	system("cls");
	system("color 8E");
	int neng=0,dineng=0,lun=0;
	while(1) {
		int gong=0,fang=0,digong=0,difang=0,chu=0,dichu=0;
		lun++;
		ts(lun,neng);
		cin>>chu;
		switch(chu) { //玩家控制
			case 1:
				if(neng>=1) {
					gong=1;
					neng--;
					cout<<"我:\n波"<<endl;
				} else {
					cout<<"没有足够的能量"<<endl;;
					lun--;
					continue;
				}
				break;
			case 2:
				if(neng>=2) {
					gong=2;
					neng-=2;
					cout<<"我:\n海啸"<<endl;
				} else {
					cout<<"没有足够的能量"<<endl;
					lun--;
					continue;
				}
				break;
			case 3:
				if(neng>=3) {
					gong=3;
					neng-=3;
					cout<<"我:\n天雷"<<endl;
				} else {
					cout<<"没有足够的能量"<<endl;
					lun--;
					continue;
				}
				break;
			case 4:
				neng++;
				cout<<"我:\n能量"<<endl;
				break;
			case 5:
				fang=1;
				cout<<"我:\n波防"<<endl;
				break;
			case 6:
				fang=2;
				cout<<"我:\n海啸防"<<endl;
				break;
			case 0:
				cd();
			default:
				printf("无该选项!\n\n\n");
				Sleep(300);
		}
		dichu=rgzz(lun,dineng,neng);
		cout<<"敌："<<endl;
		switch(dichu) { //机器控制
			case 1:
				digong=1;
				dineng--;
				cout<<"波"<<endl;
				break;
			case 2:
				digong=2;
				dineng-=2;
				cout<<"海啸"<<endl;
				break;
			case 3:
				digong=3;
				dineng-=3;
				cout<<"天雷"<<endl;
				break;
			case 4:
				dineng++;
				cout<<"能量"<<endl;
				break;
			case 5:
				difang=1;
				cout<<"波防"<<endl;
				break;
			case 6:
				difang=2;
				cout<<"海啸防"<<endl;
				break;
		}
		if((gong==difang&&gong!=0) || chu==dichu || (digong==fang&&digong!=0)) continue;//判断游戏是否结束
		else if((gong>digong&&gong!=difang) || (dichu==4&&gong>0) || (dichu==4&&gong!=0)) {
			cout<<"YOU WIN!\n\n";
			zong++;
			sheng++;
			bccd(zong,sheng,bai);
			system("pause");
			return;
		} else if((digong>gong&&digong!=fang) || (digong!=fang&&digong!=0) || (chu==4&&digong>0)) {
			cout<<"YOU DIE!\n\n";
			zong++;
			bai++;
			bccd(zong,sheng,bai);
			system("pause");
			return;
		}
	}
	return;
}
int main() {
	system("title 能量 1.0.5  zty出品");
	system("mode con cols=80 lines=20");
	cout<<"欢迎游玩“能量”小游戏\n";
	Bling();
	drcd();
	cd();
	return 0;
}

