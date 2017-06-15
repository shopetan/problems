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

#define MAX 100

vector<int> G;
int m = 0;
int cnt = 0;

void insertionSort(vector<int>&A,int n,int g){
  for(int i = g;i<n;i++){
    int v = A[i];
    int j = i - g;
    while(j >= 0 && A[j] > v){
      A[j+g] = A[j];
      j = j - g;
      cnt++;
    }
    A[j+g] = v;
  }
}

void shellSort(vector<int> &A,int n){
  cnt = 0;
  int h = 1;
  while(h <= A.size()){
    G.push_back(h);
    h = (3*h)+1;
  }
  for(int i = G.size()-1;i >= 0;i--)
    insertionSort(A,n,G[i]);
}

int main() {
  int(n);
  vint(A,n);
  
  shellSort(A,n);
  
  cout << G.size() << endl;

  RREP(i,G.size())
    if(i <= G.size()-1)
      cout << G[i] << " ";
    else
      cout << G[i];
  cout << endl;
    
  cout << cnt << endl;
  REP(i,A.size())
    cout << A[i] << endl;
}
