#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int zong,sheng,bai;
void yxzt();
void cd();
void ckzj();
void gyyx() {
	system("cls");
	printf(" ���ã���ӭ����������");
	cout<<"Ϊ�˸������õ���Ϸ���飬";
	Sleep(250);
	cout<<"ztyʱ��ʱ���Ż�����Ϸ��";
	Sleep(250);
	cout<<"�Ż���ᾡ�췢�������ϣ�CSDN����";
	Sleep(250);
	cout<<"������";
	Sleep(250);
	cout<<"1.";
	Sleep(250);
	cout<<"0.";
	Sleep(250);
	cout<<"4";
	Sleep(250);
	cout<<"�汾����";
	Sleep(250);
	cout<<"�Ļ����Ͻ��иĽ�";
	Sleep(250);
	cout<<"��Ҫ����Ϊ�����Ϸ�ڿɲ�ѯ��Ϸ����";
	Sleep(250);
	cout<<"�Ѹ�����ϣ�";
	Sleep(250);
	cout<<"ϣ�����ϲ����";
	Sleep(250);
	cout<<"\n\n����CSDN��:zty֣ͩ��ѽ���������ǵ��棩";
	Sleep(250);
	cout<<"\n\n";
	Sleep(250);
	system("color 8E");
	system("pause");
	return;
}
void yxgz() {
	system("cls");
	cout<<"��Ϸ����\n\n  1,��������1������,�ɱ�<��>��<����>����,�ɱ�<��Х><����>��أ��ǹ�������\n\n  ";
	cout<<"2,��Х������2������,�ɱ�<��Х>��<��Х��>����,�ɱ�<����>��أ��ǹ�������\n\n  ";
	cout<<"3,���ף�����3������,�ɱ�<����>����,���ɱ���أ��ǹ�������\n\n  ";
	cout<<"4,����������1��������10�ֺ�Ϊ2�㣩,�ɱ�<��><��Х><����>��أ�����������\n\n  ";
	cout<<"5,����������������,�ɷ���<��>,�ɱ�<��Х><����>��أ��Ƿ��ؼ���\n\n  ";
	cout<<"6,��Х��������������,�ɷ���<��Х>,�ɱ�<��><����>��أ��Ƿ��ؼ���\n\n  ";
	cout<<"7,����Լ�ʹ�õļ��ܱ����,��ʧ��;�������ʹ�õļ��ܱ����,��ʤ����\n\n  ";
	cout<<"8,����Լ������ʹ�õļ��ܱ�����,���������֡�\n\n  ";
	cout<<"9,���˫��ʹ�õ���ͬһ�����ܻ򶼲��ǹ�������,���������֡�\n  ";
	system("pause");
	return;
}
void ckzj(int zong,int sheng,int bai) {//�鿴ս��
	system("cls");
	cout<<"================================================================================\n\n\t   �ܳ���:"<<zong;
	cout<<"\t\tʤ����:"<<sheng;
	cout<<"\t\t�ܳ���:"<<bai;
	cout<<"\n\n\n================================================================================";
	system("pause");
	return;
}
void drcd() { //����浵
	string line;
	fstream myFile;
	int s=0;
	myFile.open("�����浵.txt", ios::in);  // read,��
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
int rgzz(int lun, int dineng, int neng) {//�˹�����ϵͳ
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
void ts(int lun,int neng) { //ս����ʾ
	cout<<"\n��"<<lun<<"��"<<endl<<"1����  2����Х  3������  4������  5����������  6:������Х�� 0:�˳���Ϸ  ������"<<neng<<endl;
	return;
}
void cd() {//��Ϸ�˵�
	while(1) {
		system("cls");
		system("color 8E");
		cout<<"\n\n================================================================================\n\t\t  1,��ʼ��Ϸ     2,�鿴ս��     3,�鿴����\n\n\t\t  4,������Ϸ     5,�˳���Ϸ\n\n================================================================================";
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
				printf("�޸�ѡ��!\n\n\n");
				Sleep(300);
		}
	}

}
void bccd(int zong,int sheng,int bai) { //����浵
	char line[256];
	fstream myFile;
	myFile.open("�����浵.txt", ios::out);
	if (myFile.is_open()) {
		myFile<<bai<<"\n";
		myFile<<sheng<<"\n";
		myFile<<zong<<"\n";
		myFile.close();
	}
}
void Bling() { //��ʼ����
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
void yxzt() { //��Ϸ����
	system("cls");
	system("color 8E");
	int neng=0,dineng=0,lun=0;
	while(1) {
		int gong=0,fang=0,digong=0,difang=0,chu=0,dichu=0;
		lun++;
		ts(lun,neng);
		cin>>chu;
		switch(chu) { //��ҿ���
			case 1:
				if(neng>=1) {
					gong=1;
					neng--;
					cout<<"��:\n��"<<endl;
				} else {
					cout<<"û���㹻������"<<endl;;
					lun--;
					continue;
				}
				break;
			case 2:
				if(neng>=2) {
					gong=2;
					neng-=2;
					cout<<"��:\n��Х"<<endl;
				} else {
					cout<<"û���㹻������"<<endl;
					lun--;
					continue;
				}
				break;
			case 3:
				if(neng>=3) {
					gong=3;
					neng-=3;
					cout<<"��:\n����"<<endl;
				} else {
					cout<<"û���㹻������"<<endl;
					lun--;
					continue;
				}
				break;
			case 4:
				neng++;
				cout<<"��:\n����"<<endl;
				break;
			case 5:
				fang=1;
				cout<<"��:\n����"<<endl;
				break;
			case 6:
				fang=2;
				cout<<"��:\n��Х��"<<endl;
				break;
			case 0:
				cd();
			default:
				printf("�޸�ѡ��!\n\n\n");
				Sleep(300);
		}
		dichu=rgzz(lun,dineng,neng);
		cout<<"�У�"<<endl;
		switch(dichu) { //��������
			case 1:
				digong=1;
				dineng--;
				cout<<"��"<<endl;
				break;
			case 2:
				digong=2;
				dineng-=2;
				cout<<"��Х"<<endl;
				break;
			case 3:
				digong=3;
				dineng-=3;
				cout<<"����"<<endl;
				break;
			case 4:
				dineng++;
				cout<<"����"<<endl;
				break;
			case 5:
				difang=1;
				cout<<"����"<<endl;
				break;
			case 6:
				difang=2;
				cout<<"��Х��"<<endl;
				break;
		}
		if((gong==difang&&gong!=0) || chu==dichu || (digong==fang&&digong!=0)) continue;//�ж���Ϸ�Ƿ����
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
	system("title ���� 1.0.5  zty��Ʒ");
	system("mode con cols=80 lines=20");
	cout<<"��ӭ���桰������С��Ϸ\n";
	Bling();
	drcd();
	cd();
	return 0;
}

