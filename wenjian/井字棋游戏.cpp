#include<bits/stdc++.h>
using namespace std;
int a[101][101],x,y;
bool asd(int k){
    for(int i=1;i<=3;i++){
        if(a[i][1]==a[i][2]&&a[i][2]==a[i][3]&&a[i][3]==k){
            return 1;
        }
        if(a[1][i]==a[2][i]&&a[2][i]==a[3][i]&&a[3][i]==k){
            return 1;
        }
    }
    if(a[1][1]==a[2][2]&&a[2][2]==a[3][3]&&a[3][3]==k){
        return 1;
    }
    if(a[3][1]==a[2][2]&&a[2][2]==a[1][3]&&a[1][3]==k){
        return 1;
    }
    return 0;
}
int main(){
    cout<<"井字棋游戏现在开始"<<endl<<"此作品由@fzt123F制作，严禁搬运"<<endl;
    for(int i=0;i<9;i++){
        cout<<"玩家"<<i%2+1<<"开始下棋"<<endl;
        cin>>x>>y;
        system("cls");
        if(x>=4||y>=4){
        	cout<<"棋子出界,视为作弊"<<endl;
        	cout<<"玩家"<<(i+1)%2+1<<"胜利!";
            return 0;
		}else if(a[3-y+1][x]!=0){
            cout<<"此处已有棋子,视为作弊"<<endl;
            cout<<"玩家"<<(i+1)%2+1<<"胜利!";
            return 0;
        }else{
            a[3-y+1][x]=i%2+1;
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                if(a[i][j]==0){
                    cout<<".";
                }else if(a[i][j]==1){
                    cout<<"X";
                }else{
                    cout<<"O";
                }
            }
            cout<<endl;
        }
        if(asd(i%2+1)){
            cout<<"玩家"<<i%2+1<<"胜利!";
            return 0;
        }
    }
    cout<<"平局"; 
    return 0;
}
