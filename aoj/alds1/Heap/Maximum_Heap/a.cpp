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

#define MAX 2000000

int H,A[MAX+1];

void maxHeapify(int i){
  int l,r,largest;
  l = 2*i;
  r = 2*i + 1;

  if(l <= H && A[l] > A[i]) largest = l;
  else largest = i;
  if(r <= H && A[r] > A[largest]) largest = r;

  if(largest != i){
    swap(A[i],A[largest]);
    maxHeapify(largest);
  }
}

int main() {
  cin >> H;

  FOR(i,1,H+1)
    cin >> A[i];
  RFOR(i,1,H/2+1)
    maxHeapify(i);
  FOR(i,1,H+1)
    cout << " " << A[i];
  cout << endl;

  return 0;
}
