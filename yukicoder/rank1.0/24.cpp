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
struct Check{
  int num;
  char c;
};


int main() {
  int(n);
  Check A[10];
  Check C[10];
  
  REP(i,10){
    A[i].num = i;
    A[i].c = 't';
    C[i].num = i;
    C[i].c = 'n';
  }
  
  
  REP(i,n){
    vint(B,4);
    string(st);
    if(st == "NO"){
      REP(j,4)
	A[B[j]].c = 'n';
    }else if(st == "YES"){
      REP(j,4){
	if(A[B[j]].c != 'n')
	  A[B[j]].c = 'c';
      }
      REP(j,10){	
	if(A[j].c != 'c'){
	  A[j].c = 'n';
	}
      }
      REP(j,4){
	if(A[B[j]].c != 'n')
	  A[B[j]].c = 't';
      }
      REP(j,10){
	C[j].num = i;
	C[j].c = 'n';
      }
    }
  }

  REP(i,10){
    if(A[i].c != 'n')
    cout << A[i].num << endl;
  }

}
