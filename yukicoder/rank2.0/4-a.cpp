#include<iostream>
#include<algorithm>
using namespace std;


bool dp[10000];
int main(void){
int N,w[100];

int sum=0;
cin>>N;
for(int i=0;i<N;i++){
cin>>w[i];
sum+=w[i];
}
if(sum&1){
cout<<"impossible"<<endl;
return 0;
}
int m=sum/2;
dp[0]=true;
for(int i=0;i<N;i++)
for(int j=m;j>=w[i];j--)
dp[j]|=dp[j-w[i]];

if(dp[m])cout<<"possible"<<endl;
else cout<<"impossible"<<endl;
return 0;
}
