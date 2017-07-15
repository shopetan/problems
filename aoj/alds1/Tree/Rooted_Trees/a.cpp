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

#define MAX 100005
#define NIL -1

struct Node{
  int p,l,r;
};
Node T[MAX];
int n,D[MAX];

void print(int u){
  int i,c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p<< ", ";
  cout << "depth = " << D[u] << ", ";

  if(T[u].p == NIL) cout << "root, ";
  else if(T[u].l == NIL) cout << "leaf, ";
  else cout << "internal node, ";

  cout << "[";
  for(i = 0, c = T[u].l; c != NIL; i++,c=T[c].r){
    if(i) cout << ", ";
    cout << c;
  }
  cout << "]" << endl;
}

int rec(int u,int p){
  D[u] = p;
  if(T[u].r != NIL) rec(T[u].r,p);
  if(T[u].l != NIL) rec(T[u].l,p+1);
}

int main() {
  int i,j,d,v,c,l,r;
  cin >> n;

  REP(i,n){
    T[i].p = T[i].l = T[i].r = NIL;
  }
  REP(i,n){
    cin >> v >> d;
    for(j=0;j<d;j++){
      cin >> c;
      if(j ==0) T[v].l = c;
      else T[l].r = c;
      l = c;
      T[c].p = v;
    }
  }
  REP(i,n){
    if(T[i].p == NIL) r = i;
  }

  rec(r,0);
  REP(i,n){
    print(i);
  }
}
