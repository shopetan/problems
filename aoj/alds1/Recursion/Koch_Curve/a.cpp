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

struct Point{
  double x;
  double y;
};

void koch(int n, Point a, Point b){

  if(n == 0)
    return;

  // calc
  Point s, t, u;
  double tanh = M_PI * 60.0 / 180.0;

  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = ((2.0 * a.y) + (1.0 * b.y)) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = ((1.0 * a.y) + (2.0 * b.y)) / 3.0;
  u.x = (t.x - s.x) * cos(tanh) - (t.y - s.y) * sin(tanh) + s.x;
  u.y = (t.x - s.x) * sin(tanh) + (t.y - s.y) * cos(tanh) + s.y;

  // recursion
  koch(n-1, a, s);
  printf("%.8f %.8f\n", s.x, s.y);

  koch(n-1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);

  koch(n-1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(n-1, t, b);
}


int main() {
  int(n);
  Point p1,p2;
  p1.x = 0.0;
  p1.y = 0.0;
  p2.x = 100.0;
  p1.y = 0.0;

  printf("%.8f %.8f\n", p1.x, p1.y);
  koch(n,p1,p2);
  printf("%.8f %.8f\n", p2.x, p2.y);
  
}
