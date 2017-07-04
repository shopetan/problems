# include <bits/stdc++.h>

# define FOR(i,a,b) for (int i=(a);i<(b);i++)
# define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
# define REP(i, n) for (int i = 0; i < (int)(n); i++)
# define RREP(i,n) for (int i=(n)-1;i>=0;i--)

# define int(x) int x; scanf("%d",&x);
# define double(x) double x; scanf("%lf",&x);
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


int main() {
  int(n);
  int(k);
  int odd = 0;
  int num = 0;
  int cnt =0;
  double A[k] = {};
  
  vint(a,n);
  sort(a.begin(),a.end(),greater<int>());

  if(n%k == 0){
  }else{
    cout << n%k << endl;
    int i = n;
    while(i >= 0){
      i -= k;
      if(i < 0)
	odd = abs(i);
    }
  }
  
  num = ceil((double)n/(double)k);
  
  if(odd != 0){
    REP(i,odd){
      A[0] += a[i];
      cnt++;
    }
    cout << "hoge" << endl;
    A[0] /= odd;
    REP(i,k){
      REP(j,num){
	A[i+1] += a[cnt];
	cnt++;
      }
      A[i+1] /= num;
    }
  }else{
    REP(i,k){
      REP(j,num){
	A[i] += a[cnt];
	cnt++;
      }
      A[i] /= num;
    }
  }

  
  sort(a.begin(),a.end(),greater<int>());
  
  int ans = ceil(*max_element(&A[0],&A[k]) - *min_element(&A[0],&A[k]));
  
  REP(i,k)
    cout << A[i] << " ";
  cout << endl;
  cout << ans << endl;
}
