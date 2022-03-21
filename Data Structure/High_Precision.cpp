#include<bits/stdc++.h>
using namespace std;
const int maxn = 10000;
struct HugeInt{
    int len;
    int num[maxn];
};
HugeInt a,b,w;
char c[maxn],d[maxn];
bool negative;
void scan_Num_1(){
    cin>>c;
    cin>>d;
    a.len = strlen(c);
    b.len = strlen(d);
    for(int i=0;i<a.len;i++) a.num[a.len-i] = c[i]-'0';    //倒着存
    for(int i=0;i<b.len;i++) b.num[b.len-i] = d[i]-'0';
}

void scan_Num_2(){
    cin>>c;
    cin>>d;
    if(strlen(c)<strlen(d) || (strlen(c)==strlen(d) && strcmp(c,d)<0)){
        negative=true;
        swap(c,d);
    }
    a.len = strlen(c);
    b.len = strlen(d);
    for(int i=0;i<a.len;i++) a.num[a.len-i] = c[i]-'0';
    for(int i=0;i<b.len;i++) b.num[b.len-i] = d[i]-'0';
}

void Plus(){
    w.len = max(a.len,b.len);
    for(int i=1;i<=w.len;i++){       //这里从1开始遍历是因为17行和18行只遍历到len-1
        w.num[i] += a.num[i]+b.num[i];  //这里使用+=是因为要加上前面进位的值
        w.num[i+1] += w.num[i]/10;
        w.num[i]%=10;
    }
    if(w.num[w.len+1]!=0) w.len++;
}

void Minus(){
    w.len = a.len;
    for(int i=1;i<=w.len;i++){
        if(a.num[i]<b.num[i]){
            a.num[i+1]--;
            a.num[i]+=10;
        }
        w.num[i] = a.num[i] - b.num[i];
    }
    while(w.num[w.len] == 0 && w.len!=1) w.len--;
}


int main(){
    scan_Num_2();
    Minus();
    for(int i=w.len;i>=1;i--) cout<<w.num[i];




return 0;
}
