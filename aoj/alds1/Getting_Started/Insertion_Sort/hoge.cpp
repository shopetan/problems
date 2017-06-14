# include <bits/stdc++.h>

# define rep(i, n) for (int i = 0; i < (int)(n); i++)
# define int(x) int x; scanf("%d",&x);
# define lint(x) long long x; scanf("%lld",&x);
# define vint(v,n) vector<int> v(n); rep(i,n) scanf("%d", &v[i]);
# define vlint(v,n) vector<lint> v(n); rep(i,n) scanf("%lld", &v[i]);
# define double(x) double x; scanf("%lf",&x);
# define vdouble(v,n) vector<double> v(n); rep(i,n) scanf("%lf", &v[i]);
# define string(x) string x; cin >> x;

using namespace std;

namespace utils{
  template <typename T> void print(vector<vector<T>> mat) {
    rep (i, mat.size()) {
      rep (j, mat[0].size()) cout << mat[i][j] << ' ';
      cout << endl;
    }
  }

  template <typename T> void print(vector<T> v) {
    rep (i, v.size()) cout << v[i] << ' ';
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
  std::vector<std::vector<int>> data{{1,2,3},{4,5,6}};
  utils::empty<int>(10,10);

  vint(v,10);

  utils::print(vint(v,10));
  utils::print(utils::empty<int>(10,10));
  
}
