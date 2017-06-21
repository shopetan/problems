# include <bits/stdc++.h>

# define FOR(i,a,b) for (int i=(a);i<(b);i++)
# define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
# define REP(i, n) for (int i = 0; i < (int)(n); i++)
# define RREP(i,n) for (int i=(n)-1;i>=0;i--)

# define int(x) int x; scanf("%d",&x);
# define vint(v,n) vector<int> v(n); REP(i,n) scanf("%d", &v[i]);
# define string(x) string x; cin >> x;

using namespace std;

namespace utils{
  template <typename T> void print(vector<vector<T>> mat) {
    REP (i, mat.size()) {
      REP (j, mat[0].size()) cout << mat[i][j] << ' ';
      cout << endl;
    }
  }

  template <typename T> void print(vector<T> v) {
    REP (i, v.size())
      if (i >= v.size()-1)
	cout << v[i];
      else
	cout << v[i] << ' ';
    
    cout << endl;
  }

  template <typename T> pair<T, T> shape(vector<vector<T>> mat) {
    int d1, d2;

    d1 = mat.size();
    if (d1 > 0) d2 = mat[0].size();
    else int d2 = 0;
    cout << "(" << d1 << ", " << d2 << ")" << endl;
    return make_pair(0, 0);
  }

  template <typename T> vector<vector<T>> empty(int n, int m) {
    vector<vector<T>> mat(n, vector<T>(m));
    return mat;
  }
}

struct Node{
  int key;
  Node *prev;
  Node *next;
};

Node *nil;

void init(){
  nil = (Node *)malloc(sizeof(Node));
  nil->next = nil;
  nil->prev = nil;
}
void insert(int key){
  Node *x = (Node *)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  nil->next = x;
  x->prev = nil;
}

void printList(){
  Node *cur;
  int isf = 0;
  cur = nil->next;
  printf("%d",cur->key);
  while(1){
    if(cur == nil)
      break;
    if(isf++ > 0)
      printf(" ");
    printf("%d",cur->key);
    cur = cur->next;
  }
  printf("\n");
}

int main() {
  int(n);
  deque<int> dq;
  init();
  REP(i,n){
    int key;
    char command[20];
    scanf("%s",command);
    if(command[0] == 'i'){
      scanf("%d",&key);
      dq.push_front(key);
    }
    else if(command[0] == 'd' && command[6] == '\0'){
      scanf("%d",&key);
      REP(j,dq.size()){
	if(dq[j] == key){
	  dq.erase(dq.begin() + j);
	  break;
	}
      }
    }
    else if(command[6] == 'F')
      dq.pop_front();
    else if(command[6] == 'L')
      dq.pop_back();
    else
      return -1;
  }
  while(dq.size() > 1) {
    printf("%d ",dq.front());
    dq.pop_front();
  }
  if(dq.size() > 0)
    printf("%d\n",dq.front());
  return 0;
}
