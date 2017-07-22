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
int n,D[MAX],H[MAX];

void setDepth(int u,int d){
  if( u == NIL) return;
  D[u] = d;
  setDepth(T[u].l,d+1);
  setDepth(T[u].r,d+1);
}

int setHeight(int u){
  int h1 =  0;
  int h2 =  0;
  
  if( T[u].l != NIL)
    h1 = setHeight(T[u].l) + 1;
  if( T[u].r != NIL)
    h2 = setHeight(T[u].r) + 1;
  return H[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
  if( T[u].p == NIL) return NIL;
  if( T[T[u].p].l != u && T[T[u].p].l != NIL)
    return T[T[u].p].l;
  if( T[T[u].p].r != u && T[T[u].p].r != NIL)
    return T[T[u].p].r;
  return NIL;
}

void print(int u){
  int i,c;
  cout << "node " << u << ": ";
  cout << "parent = " << T[u].p<< ", ";
  cout << "sibling = " << getSibling(u) << ", ";

  int deg =0;
  if( T[u].l != NIL) deg++;
  if( T[u].r != NIL) deg++;
  cout << "degree = " << deg << ", ";
  cout << "depth = " << D[u] << ", ";
  cout << "height = " << H[u] << ", ";
 
  if(T[u].p == NIL) cout << "root" << endl;
  else if(T[u].l == NIL && T[u].r == NIL) cout << "leaf" << endl;
  else cout << "internal node" << endl;

}

int main() {
  int v,l,r,root;
  cin >> n;

  REP(i,n){
    T[i].p = NIL;
  }
  REP(i,n){
    cin >> v >> l >> r;
    T[i].l = l;
    T[i].r = r;
    if(l != NIL) T[l].p = v;
    if(r != NIL) T[r].p = v;
  }
  REP(i,n){
    if(T[i].p == NIL) root = i;
  }

  setDepth(root,0);
  setHeight(root);
  
  REP(i,n){
    print(i);
  }
}
