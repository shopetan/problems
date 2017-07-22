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
static const int N = 1000;

int lcs(string X,string Y){
  int c[N+1][N+1];
  int m = X.size();
  int n = Y.size(); 
  int maxl =0;
  X = ' ' + X;
  Y = ' ' + Y;
  c[0][0] = 0;
  for(int i=1;i <= m;i++){
    c[i][0] = 0;
  }
  for(int j=1;j <= n;j++){
    c[0][j] = 0;
  }
  for(int i=1;i <= m;i++){
    for(int j = 1; j <= n;j++){
      if(X[i] == Y[j])
	c[i][j] = c[i-1][j-1] + 1;
      else
	c[i][j] = max(c[i-1][j],c[i][j-1]);
      maxl = max(maxl,c[i][j]);
    }
  }
  return maxl;
}

int main() {
  int(n);
  string x,y;
  int A[n] ={};
  for(int i=0;i<n;i++){
    //cout << x << " " << y;
    cin >> x >> y;
    A[i] = lcs(x,y);
  }

  REP(i,n)
    cout << A[i] << endl;
  return 0;
}
