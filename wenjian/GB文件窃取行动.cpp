#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<conio.h>
#include<windows.h>
#include<fstream>
#define ll long long
#define cls(a,b) memset(a,b,sizeof(a))
#include<unistd.h>

using namespace std;

void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info); 
}


namespace io{
	namespace out{
		void delay_print(std::string msg, int delay = 8){
			for(int i=0;i<msg.size();i++){
				cout<<msg[i];
				Sleep(delay);
			}
		}
		void change_color(int color);
	}
}

bool cmp(int a,int b){
	return a<b;
}

int main(){
	HideCursor();
	title:;
	system("title GB文件窃取行动");
	system("cls");
	cout<<"GB文件窃取行动！\n\n"
		<<"[1]正篇游戏\n"
		<<"[2]作者的家\n"
		<<"[0]离开";
	char t=_getch();
	if(t=='0') exit(0);
	else if(t=='2'){
		auh:;
		system("cls");
		system("title 作者的家");
		cout<<"ttcandy: ";
		io::out::delay_print("啊，你来了？我最近有点忙，过段时间的吧。");
		Sleep(3000);
		goto title;
	}else if(t=='1'){
		ms:;
		system("cls");
		system("title 行动进行中");
		io::out::delay_print("你是黑客Jacson，为了探寻Globe Bintree能出优质作品的原因，你准备潜入GB系统窃取文件。当然，这不是那么容易的...",12);
		Sleep(2000);
		system("cls");
		io::out::delay_print("现如今，你找到了GB的网站：-----------------。",12);
		Sleep(1000);
		system("cls");
		io::out::delay_print("所以喽，你一定会网站他做一些手脚的。看着办吧！",12);
		Sleep(1000);
		mss:;
		system("cls");
		cout<<"Globe Bintree [1]首页 [2]作品列表 [3]资讯 [4]登录\n"
			<<"最新资讯：GB徽标确定！\n"
			<<"资讯榜\n"
			<<"[F]GB徽标确定\n"
			<<"[S]GitHub入驻\n"
			<<"[T]ttcandy回归\n";
		t=_getch();
		if(t=='1'){
			system("cls");
			io::out::delay_print("你：首页上好像就这些东西...",12);
			Sleep(1000);
			goto mss;
		}else if(t=='2'){
			system("cls");
			io::out::delay_print("你：作品列表里还是那些...",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("你：可恶啊，还是那么受欢迎！",12);
			Sleep(1000);
			goto mss;
		}else if(t=='3'){
			system("cls");
			io::out::delay_print("你：资讯上都是什么祝贺的消息...",12);
			Sleep(1000);
			goto mss;
		}else if(t=='4'){
			system("cls");
			io::out::delay_print("你：好耶！注册个账号！",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("你：邮箱吗...-------@--.com",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("你：验证码------",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("你：芜湖！注册成功！",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("你：咦？主页上有新的东西了？",12);
			Sleep(1000);
			ne:;
			system("cls");
			cout<<"Globe Bintree [1]首页 [2]作品列表 [3]资讯 [4]个人 [5]管理员\n"
				<<"最新资讯：GB徽标确定！\n"
				<<"资讯榜\n"
				<<"[F]GB徽标确定\n"
				<<"[S]GitHub入驻\n"
				<<"[T]ttcandy回归\n";
			t=_getch();
			if(t=='1'||t=='2'||t=='3'||t=='4'||t=='f'||t=='s'||t=='t'){
				system("cls");
				io::out::delay_print("你：这种时候先别看了吧...",12);
				Sleep(1000);
				goto ne;
			}else if(t!='5') goto ne;
			else if(t=='5'){
				system("cls");
				io::out::delay_print("你：管理员？",12);
				Sleep(1000);system("cls");
				io::out::delay_print("你：\"GB诚招管理员，欢迎各位应聘！\"",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("你：这大好的机会！",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("然后你参加了线上面试。",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy：欢迎参加管理员面试！",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("你：(竟然是ttcandy本人！)",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("你：啊，那个，谢谢。",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy：不用紧张！GB很友好的。",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("你：那太好了，开始吧。",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy：你邮箱能一直用？",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("你：对啊，最近刚搞的。",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy：那太好了。我的邮箱------@--.com，回头我联系你。我把你管理员权限弄好啦！",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("你：谢谢了！(真是个绝妙的机会！)",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("你：好了！现在开始吧！",12);
				Sleep(1000);
				xdks:;
				system("cls");
				cout<<"管理员界面\n"
					<<"[1]GB文件\n"
					<<"[2]GB成员\n"
					<<"[0]离开";
				t=_getch();
				if(t=='2'){
					system("cls");
					io::out::delay_print("你：ttcandy, linyunxiang1111, blue_peace, fzt123F, ... , Jacson",12);
					Sleep(2000);
					goto xdks;
				}else if(t=='0'){
					system("cls");
					io::out::delay_print("你：先别离开吧...",12);
					Sleep(1000);
					goto xdks;
				}else if(t=='1'){
					system("cls");
					io::out::delay_print("你：哈！文件！我来了！",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("你：LS.cpp...VS2.cpp............这都什么啊！",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("你：咦？GB规章制度？",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("你：这里有个链接？",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("你：ttcandy个人主页...啥玩意啊！",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("你：欸？等一下，这是什么？",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("你：\"把自己设为最高管理的方法：在这个文件后面加上\'__name__\'\"",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("你：可是这个文件是只读啊？想个办法吧。",12);
					Sleep(1000);
					gz:;
					system("cls");
					cout<<"该怎么做？\n"
						<<"[1]黑入网站修改源代码\n"
						<<"[2]联系ttcandy";
					t=_getch();
					if(t=='1'){
						system("cls");
						io::out::delay_print("你：源代码！来，我让你看看我的厉害！",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("你：嗯？账...号...已...被...封...！？！？！？",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("你：完了！！！",12);
						Sleep(1000);
						system("cls");
						cout<<"GAME OVER";
						exit(0);
					}else if(t=='2'){
						system("cls");
						io::out::delay_print("你：ttcandy！是我！",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("ttcandy：哦，Jacson啊。怎么了？",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("你：是这样，我看咱们公告有点问题，我给你更新一下。",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("ttcandy：好啊，权限给你。",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("你：谢谢了！(又是个绝妙的机会！)",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("你：按照刚才的方法做吧！但也象征性写点东西。",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("你：完成！保存！",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("好了，看看有什么变化。",12);
						Sleep(1000);
						jmwj:;
						system("cls");
						cout<<"最高管理界面\n"
							<<"[1]解散GB\n"
							<<"[2]机密文件";
						t=_getch();
						if(t=='1'){
							system("cls");
							io::out::delay_print("你：解散掉的话，就不能看文件了吧。而且也很可惜的。",12);
							Sleep(1000);
							goto jmwj;
						}else if(t=='2'){
							system("cls");
							io::out::delay_print("你：终于要看了吗...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("你：读一下吧。",12);
							Sleep(2000);
							system("cls");
							io::out::delay_print("想必你看到这个文件后很激动吧。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("这个文件已经很久没人动过了。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("在告诉你秘密之前，我想说：",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("我们是同道中人。我们都是可耻的。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("团长ttcandy，也就是我，之前干过很失败的事。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("在那一天，我作了弊。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("我只是想赢，但却忽视了一点：我赢不赢，是我的实力；我作不作弊，是我的思想。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("在那一天之后，我是多么深刻地意识到我有多么弱。蓝和是真正的神犇，我才是那个，",16);
							io::out::delay_print("被爆踩的蒟蒻。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("你也一样。为了知道我们的秘密，欺骗、投机取巧。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("我一开始觉得你很有趣，但是看到了我的影子。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("正因为我怕输，所以我的代码都打上了明显的版权标记。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("而这恰恰是我在向敌人展示自己的怯弱。因为怯弱，所以要保护。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("现在我来告诉你秘密。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("我们这么昌盛，因为我们团结。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("虽然有过不愉快，但是我们仍然是一条心。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("我们要去考CSP了。我可能有点悬，但是我不泄气，因为这是我自己的水平。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("除了努力，我没有别的方法改变。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("一会我会给你打电话。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("你：什么！",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("你：原来我们这么失败...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("手机响了。",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("你：喂...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("ttcandy：你并不失败。我们都是同路人，只要对着目标努力，没什么做不成的。",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("你：你怎么...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("ttcandy：加入我们吧。团里的所有人都是朋友。",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("你：谢谢...谢谢！",12);
							Sleep(1000);
							system("cls");
							system("title 行动圆满结束！");
							io::out::delay_print("本来想要窃取文件的你，没想到加入GB了。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("也许我们并不强，但我们有努力，有一颗真诚的心。",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("感谢你能玩到这里！",16);
							Sleep(3000);
							goto title; 
						}else goto jmwj;
					}else goto gz;
				}else goto xdks;
			}
		}else goto mss;
	}else goto title;
	return 0;
}

