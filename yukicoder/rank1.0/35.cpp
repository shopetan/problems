# include <bits/stdc++.h>

# define FOR(i,a,b) for (int i=(a);i<(b);i++)
# define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
# define REP(i, n) for (int i = 0; i < (int)(n); i++)
# define RREP(i,n) for (int i=(n)-1;i>=0;i--)

# define int(x) int x; scanf("%d",&x);
# define vint(v,n) vector<int> v(n); REP(i,n) scanf("%d", &v[i]);
# define string(x) string x; cin >> x;
# define all(a) a.begin(),a.end()

# define INF 1<<30
typedef long long ll;
const ll MOD = 1e9+7;

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


int main() {
  int(n);

  int total_word=0;
  int total_miss=0;
  
  REP(i,n){
    int(t);
    string(s);
    int word = 0;
    int miss = 0;
    t = 12*t/1000;
    word = min((int)s.size(), t);
    miss = s.size() - word;

    total_word += word;
    total_miss += miss;
  }
  cout << total_word << " " << total_miss << endl;
}
