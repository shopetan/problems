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


int main() {
  int(n);
  int(k);
  stack<int> st;
  int A[n] = {};
  int B[n] = {};
  
  REP(i,n){
    char c;
    cin >> c;
    if(c == '('){
      st.push(i);
      A[i] = st.top();
      B[i] = -1;
    }
    if(c == ')'){
      B[i] = st.top();
      A[i] = -1;
      st.pop();
    }
  }

  REP(i,n){
    if(i == k-1){
      if(A[i] != -1){
	REP(j,n){
	  if(B[j] == A[i]){
	    cout << j+1 << endl;
	  }
	}
      }else{
	REP(j,n){
	  if(A[j] == B[i])
	    cout << j+1 << endl;
	}
      }
    }
  }

  /*
  REP(i,n)
    cout << A[i] << " ";
  cout << endl;

  REP(i,n)
    cout << B[i] << " ";
  cout << endl;
  */
}
