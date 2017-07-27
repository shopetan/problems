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

int matrix[100][100];
int n;
int prim(){
  bool visit[1000] = {true};
  int sum = 0;

  while(1){
    int min = 2001;
    int mini = -1;

    REP(i,n){
      if(visit[i] == true){
	REP(j,n){
	  if(matrix[i][j] > -1 && matrix[i][j] < min && visit[j] == false){
	    min = matrix[i][j];
	    mini = j;
	  }
	}
      }
    }
    if(mini == -1){
      break;
    }else{
      sum += min;
      visit[mini] = true;
    }
  }
  return sum;
}

int main() {
  cin >> n;
  REP(i,n){
    REP(j,n)
      cin >> matrix[i][j];
  }
  cout << prim() << endl;
  
}
