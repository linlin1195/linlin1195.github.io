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
	system("title GB�ļ���ȡ�ж�");
	system("cls");
	cout<<"GB�ļ���ȡ�ж���\n\n"
		<<"[1]��ƪ��Ϸ\n"
		<<"[2]���ߵļ�\n"
		<<"[0]�뿪";
	char t=_getch();
	if(t=='0') exit(0);
	else if(t=='2'){
		auh:;
		system("cls");
		system("title ���ߵļ�");
		cout<<"ttcandy: ";
		io::out::delay_print("���������ˣ�������е�æ������ʱ��İɡ�");
		Sleep(3000);
		goto title;
	}else if(t=='1'){
		ms:;
		system("cls");
		system("title �ж�������");
		io::out::delay_print("���Ǻڿ�Jacson��Ϊ��̽ѰGlobe Bintree�ܳ�������Ʒ��ԭ����׼��Ǳ��GBϵͳ��ȡ�ļ�����Ȼ���ⲻ����ô���׵�...",12);
		Sleep(2000);
		system("cls");
		io::out::delay_print("��������ҵ���GB����վ��-----------------��",12);
		Sleep(1000);
		system("cls");
		io::out::delay_print("����ඣ���һ������վ����һЩ�ֽŵġ����Ű�ɣ�",12);
		Sleep(1000);
		mss:;
		system("cls");
		cout<<"Globe Bintree [1]��ҳ [2]��Ʒ�б� [3]��Ѷ [4]��¼\n"
			<<"������Ѷ��GB�ձ�ȷ����\n"
			<<"��Ѷ��\n"
			<<"[F]GB�ձ�ȷ��\n"
			<<"[S]GitHub��פ\n"
			<<"[T]ttcandy�ع�\n";
		t=_getch();
		if(t=='1'){
			system("cls");
			io::out::delay_print("�㣺��ҳ�Ϻ������Щ����...",12);
			Sleep(1000);
			goto mss;
		}else if(t=='2'){
			system("cls");
			io::out::delay_print("�㣺��Ʒ�б��ﻹ����Щ...",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("�㣺�ɶ񰡣�������ô�ܻ�ӭ��",12);
			Sleep(1000);
			goto mss;
		}else if(t=='3'){
			system("cls");
			io::out::delay_print("�㣺��Ѷ�϶���ʲôף�ص���Ϣ...",12);
			Sleep(1000);
			goto mss;
		}else if(t=='4'){
			system("cls");
			io::out::delay_print("�㣺��Ү��ע����˺ţ�",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("�㣺������...-------@--.com",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("�㣺��֤��------",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("�㣺�ߺ���ע��ɹ���",12);
			Sleep(1000);
			system("cls");
			io::out::delay_print("�㣺�ף���ҳ�����µĶ����ˣ�",12);
			Sleep(1000);
			ne:;
			system("cls");
			cout<<"Globe Bintree [1]��ҳ [2]��Ʒ�б� [3]��Ѷ [4]���� [5]����Ա\n"
				<<"������Ѷ��GB�ձ�ȷ����\n"
				<<"��Ѷ��\n"
				<<"[F]GB�ձ�ȷ��\n"
				<<"[S]GitHub��פ\n"
				<<"[T]ttcandy�ع�\n";
			t=_getch();
			if(t=='1'||t=='2'||t=='3'||t=='4'||t=='f'||t=='s'||t=='t'){
				system("cls");
				io::out::delay_print("�㣺����ʱ���ȱ��˰�...",12);
				Sleep(1000);
				goto ne;
			}else if(t!='5') goto ne;
			else if(t=='5'){
				system("cls");
				io::out::delay_print("�㣺����Ա��",12);
				Sleep(1000);system("cls");
				io::out::delay_print("�㣺\"GB���й���Ա����ӭ��λӦƸ��\"",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("�㣺���õĻ��ᣡ",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("Ȼ����μ����������ԡ�",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy����ӭ�μӹ���Ա���ԣ�",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("�㣺(��Ȼ��ttcandy���ˣ�)",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("�㣺�����Ǹ���лл��",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy�����ý��ţ�GB���Ѻõġ�",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("�㣺��̫���ˣ���ʼ�ɡ�",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy����������һֱ�ã�",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("�㣺�԰�������ո�ġ�",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("ttcandy����̫���ˡ��ҵ�����------@--.com����ͷ����ϵ�㡣�Ұ������ԱȨ��Ū������",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("�㣺лл�ˣ�(���Ǹ�����Ļ��ᣡ)",12);
				Sleep(1000);
				system("cls");
				io::out::delay_print("�㣺���ˣ����ڿ�ʼ�ɣ�",12);
				Sleep(1000);
				xdks:;
				system("cls");
				cout<<"����Ա����\n"
					<<"[1]GB�ļ�\n"
					<<"[2]GB��Ա\n"
					<<"[0]�뿪";
				t=_getch();
				if(t=='2'){
					system("cls");
					io::out::delay_print("�㣺ttcandy, linyunxiang1111, blue_peace, fzt123F, ... , Jacson",12);
					Sleep(2000);
					goto xdks;
				}else if(t=='0'){
					system("cls");
					io::out::delay_print("�㣺�ȱ��뿪��...",12);
					Sleep(1000);
					goto xdks;
				}else if(t=='1'){
					system("cls");
					io::out::delay_print("�㣺�����ļ��������ˣ�",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("�㣺LS.cpp...VS2.cpp............�ⶼʲô����",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("�㣺�ף�GB�����ƶȣ�",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("�㣺�����и����ӣ�",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("�㣺ttcandy������ҳ...ɶ���Ⱑ��",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("�㣺�G����һ�£�����ʲô��",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("�㣺\"���Լ���Ϊ��߹���ķ�����������ļ��������\'__name__\'\"",12);
					Sleep(1000);
					system("cls");
					io::out::delay_print("�㣺��������ļ���ֻ����������취�ɡ�",12);
					Sleep(1000);
					gz:;
					system("cls");
					cout<<"����ô����\n"
						<<"[1]������վ�޸�Դ����\n"
						<<"[2]��ϵttcandy";
					t=_getch();
					if(t=='1'){
						system("cls");
						io::out::delay_print("�㣺Դ���룡���������㿴���ҵ�������",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("�㣺�ţ���...��...��...��...��...������������",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("�㣺���ˣ�����",12);
						Sleep(1000);
						system("cls");
						cout<<"GAME OVER";
						exit(0);
					}else if(t=='2'){
						system("cls");
						io::out::delay_print("�㣺ttcandy�����ң�",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("ttcandy��Ŷ��Jacson������ô�ˣ�",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("�㣺���������ҿ����ǹ����е����⣬�Ҹ������һ�¡�",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("ttcandy���ð���Ȩ�޸��㡣",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("�㣺лл�ˣ�(���Ǹ�����Ļ��ᣡ)",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("�㣺���ողŵķ������ɣ���Ҳ������д�㶫����",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("�㣺��ɣ����棡",12);
						Sleep(1000);
						system("cls");
						io::out::delay_print("���ˣ�������ʲô�仯��",12);
						Sleep(1000);
						jmwj:;
						system("cls");
						cout<<"��߹������\n"
							<<"[1]��ɢGB\n"
							<<"[2]�����ļ�";
						t=_getch();
						if(t=='1'){
							system("cls");
							io::out::delay_print("�㣺��ɢ���Ļ����Ͳ��ܿ��ļ��˰ɡ�����Ҳ�ܿ�ϧ�ġ�",12);
							Sleep(1000);
							goto jmwj;
						}else if(t=='2'){
							system("cls");
							io::out::delay_print("�㣺����Ҫ������...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�㣺��һ�°ɡ�",12);
							Sleep(2000);
							system("cls");
							io::out::delay_print("����㿴������ļ���ܼ����ɡ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("����ļ��Ѿ��ܾ�û�˶����ˡ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�ڸ���������֮ǰ������˵��",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("������ͬ�����ˡ����Ƕ��ǿɳܵġ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�ų�ttcandy��Ҳ�����ң�֮ǰ�ɹ���ʧ�ܵ��¡�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("����һ�죬�����˱ס�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("��ֻ����Ӯ����ȴ������һ�㣺��Ӯ��Ӯ�����ҵ�ʵ�������������ף����ҵ�˼�롣",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("����һ��֮�����Ƕ�ô��̵���ʶ�����ж�ô������������������ģ��Ҳ����Ǹ���",16);
							io::out::delay_print("�����ȵ��X�m��",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("��Ҳһ����Ϊ��֪�����ǵ����ܣ���ƭ��Ͷ��ȡ�ɡ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("��һ��ʼ���������Ȥ�����ǿ������ҵ�Ӱ�ӡ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("����Ϊ�����䣬�����ҵĴ��붼���������Եİ�Ȩ��ǡ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("����ǡǡ�����������չʾ�Լ�����������Ϊ����������Ҫ������",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�����������������ܡ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("������ô��ʢ����Ϊ�����Žᡣ",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("��Ȼ�й�����죬����������Ȼ��һ���ġ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("����Ҫȥ��CSP�ˡ��ҿ����е����������Ҳ�й������Ϊ�������Լ���ˮƽ��",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("����Ŭ������û�б�ķ����ı䡣",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("һ���һ�����绰��",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�㣺ʲô��",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�㣺ԭ��������ôʧ��...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�ֻ����ˡ�",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�㣺ι...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("ttcandy���㲢��ʧ�ܡ����Ƕ���ͬ·�ˣ�ֻҪ����Ŀ��Ŭ����ûʲô�����ɵġ�",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�㣺����ô...",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("ttcandy���������ǰɡ�����������˶������ѡ�",12);
							Sleep(1000);
							system("cls");
							io::out::delay_print("�㣺лл...лл��",12);
							Sleep(1000);
							system("cls");
							system("title �ж�Բ��������");
							io::out::delay_print("������Ҫ��ȡ�ļ����㣬û�뵽����GB�ˡ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("Ҳ�����ǲ���ǿ����������Ŭ������һ����ϵ��ġ�",16);
							Sleep(1000);
							system("cls");
							io::out::delay_print("��л�����浽���",16);
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

