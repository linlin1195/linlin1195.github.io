#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;
int main(){
    MessageBox(NULL,"��Ϸ����\n1.ÿ��ֻ��ȡ1~4�����\n2.ȡ�����һ��Ϊ��","��Ϸ����",MB_OK);
    srand(time(0));
    int n=rand()%49+1;
    cout<<"��fzt123F��Ʒ�������(�s����)�s��"<<endl<<endl;
    while(n>0){
        cout << "Ŀǰ���л��" << n << "��\n";
        cout <<endl<< "$  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $\n";
        cout << "�������߶��ٸ����:";
        int x;
        cin >> x;
        if(x<1||x>4){
            cout << "�㷸����,��̫������!,you lose!!!\n";
            system("pause");
            exit(3322234);
        }
        n-=x;
        if(n<=0){
            cout << "���������һ������you lose!!!�Ҿ�֪����Ӯ������!\n";
            system("pause");
            exit(2356487);
        }
        int x2=rand()%4+1;
        n-=x2;
        cout << "fzt123F������" << x2 << "�����\n";
        cout <<endl<< "$  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $\n";
    }
    cout << "��Ӯ�˲�������û���Ӻ�,��(�V��V��),�б�������һ��\n";
    system("pause");
    return 0;
}
