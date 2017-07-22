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

bool dp[10000];

int main() {
  int(n);
  int w[100];
  int sum = 0;
  REP(i,n){
    cin >> w[i];
    sum += w[i];
  }

  //cout << (sum&1) << endl;
  if(sum&1){
    cout << "impossible" << endl;
    return 0;
  }
  int m = sum/2;
  
  dp[0] = true;
  REP(i,n){
    for(int j=m; j>=w[i];j--){
      //cout << j << " " << dp[j] << " " << j-w[i] << " " << dp[j-w[i]] << " " << w[i] << endl;
      dp[j] |= dp[j-w[i]];
    }
  }

  
  if(dp[m]) cout << "possible" << endl;
  else cout << "impossible" << endl;
}
