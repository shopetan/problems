# include <bits/stdc++.h>
# include <math.h>

# define FOR(i,a,b) for (int i=(a);i<(b);i++)
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
    REP (i, v.size()) cout << v[i] << ' ';
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

bool isPrime(int x){

  if(x == 2)
    return true;
  
  if(x < 2 || x % 2)
    return false;

  int i = 3;
  while(i <= (double)sqrt(x)){
    if (x%i == 0)
      return false;
    i = i + 2;
  }
  
  return true;
}

int main() {
  int(n);
  int prime_num = 0;
  REP(i,n){
    int(num);
    if (true == isPrime(num))
      prime_num++;
  }

  cout << prime_num << endl;
}
