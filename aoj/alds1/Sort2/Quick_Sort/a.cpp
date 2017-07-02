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

struct Card {
  int num;
  char mark;
  int index;

  void set(int n,char m,int i){
    num = n;
    mark = m;
    index = i;
  }
};

bool isStable(Card A[], int n){
  REP(i,n){
    if(A[i].num == A[i+1].num &&
       A[i].index > A[i+1].index)
      return false;
  }
  return true;
}

int partition(Card A[],int p,int r){
  int x,i,j,t;

  x = A[r].num;
  i = p-1;
  for(j = p; j < r;j++){
    if(A[j].num <= x){
      i++;
      swap(A[i],A[j]);
    }
  }
  swap(A[i+1],A[r]);

  return i + 1;
}

void quickSort(Card A[],int p,int r){
  if (p < r){
    int q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }

}

int main() {
  int(n);
  Card A[n];
  
  REP(i,n){
    char m;
    int n;
    cin >> m;
    cin >> n;
    A[i].set(n,m,i);
  }

  quickSort(A,0,n-1);

  if(isStable(A,n)){
    cout << "Stable" << endl;
  }else{
    cout << "Not stable" << endl;
  }
  REP(i,n){
    cout << A[i].mark << " " << A[i].num << endl;    
  }
  
}
