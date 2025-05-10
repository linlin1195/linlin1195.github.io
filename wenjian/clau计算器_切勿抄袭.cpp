#include<bits/stdc++.h>
using namespace std;
const int maxn = 50;
int n;
int top;
int v[maxn];
char s[maxn],c[maxn];
void calu_Push(int x,int flag);
int calu_Pow(int x,int n);
void calu_Pop();
int calu_Opr(char x);
bool calu_Check(char x);
void calu();


void calu_Push(int x,int flag) {
	if(!flag) c[++top] = x;
	else v[top] = x;
}
int calu_Pow(int x,int n) {
	int sum=1;
	for(int i=1; i<=n; i++) sum*=x;
	return sum;
}
void calu_Pop() {
	if(c[top] == '+') v[top-1] += v[top];
	if(c[top] == '-') v[top-1] -= v[top];
	if(c[top] == '*') v[top-1] *= v[top];
	if(c[top] == '/') v[top-1] /= v[top];
	if(c[top] == '^') v[top-1] = calu_Pow(v[top-1],v[top]);
	top--;
}
int calu_Opr(char x) {
	if(x == '+' || x == '-') return 0;
	if(x == '*' || x == '/') return 1;
	if(x == '^') return 2;
	
	return -1;
}
bool calu_Check(char x) {
	if(calu_Opr(x) <= calu_Opr(c[top])) return true;
	return false;
}
void calu() {
	cin.getline(s,40);
	n = strlen(s);
	s[n] = ')';
	calu_Push('(',0);
	for(int i=0; i<=n; i++) {
		while(s[i] == '(') calu_Push(s[i++],0);
		int x = 0;
		while(isdigit(s[i]))
			x = x * 10 + s[i++] - '0';
		calu_Push(x,1);
		while(true) {
			if(s[i] == ')') {
				while(c[top] != '(') calu_Pop();
				v[top-1] = v[top--];
			} else {
				while(calu_Check(s[i])) calu_Pop();
				calu_Push(s[i],0);
				break;
			}
			i++;
			if(i>n) break;
		}
	}
	cout << v[0] << endl;
}
int main() {
	calu();
	return 0;
}
