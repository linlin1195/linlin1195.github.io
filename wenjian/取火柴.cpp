#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;
int main(){
    MessageBox(NULL,"游戏规则：\n1.每次只能取1~4根火柴\n2.取到最后一根为败","游戏规则",MB_OK);
    srand(time(0));
    int n=rand()%49+1;
    cout<<"【fzt123F出品请勿搬运(╯▔皿▔)╯】"<<endl<<endl;
    while(n>0){
        cout << "目前还有火柴" << n << "根\n";
        cout <<endl<< "$  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $\n";
        cout << "你想拿走多少根火柴:";
        int x;
        cin >> x;
        if(x<1||x>4){
            cout << "你犯规了,你太卑鄙了!,you lose!!!\n";
            system("pause");
            exit(3322234);
        }
        n-=x;
        if(n<=0){
            cout << "你拿了最后一根！！you lose!!!我就知道你赢不过我!\n";
            system("pause");
            exit(2356487);
        }
        int x2=rand()%4+1;
        n-=x2;
        cout << "fzt123F想拿走" << x2 << "根火柴\n";
        cout <<endl<< "$  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $  $\n";
    }
    cout << "你赢了不过是我没发挥好,哼(￢︿￢☆),有本事再来一局\n";
    system("pause");
    return 0;
}
