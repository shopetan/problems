# include <bits/stdc++.h>

# define REP(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

class Process {
  string name;
  int time;
public:
  Process(int t, char *n){
    time = t;
    name = n;
  }
  int take(int n) {
    time -= n;
    if(time > 0)
      return -1;
    else
      return time + n;
  }
  string getName(){
    return name;
  }
};


int main() {
  queue<Process> que;
  int i_process,i_quantum;
  int i_now_time;

  scanf("%d %d",&i_process,&i_quantum);
  
  REP(i,i_process){
    char str[11];
    int time;
    scanf("%s %d", str, &time);
    que.push(Process(time,str));
  }
  while(!que.empty()){
    int taken = que.front().take(i_quantum);
    if(taken == -1){
      i_now_time += i_quantum;
      que.push(que.front());
    }
    else{
      i_now_time += taken;
      printf("%s %d\n",que.front().getName().c_str(), i_now_time);
    }
    que.pop();
  }
  
}
