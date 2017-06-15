# include <bits/stdc++.h>

# define FOR(i,a,b) for (int i=(a);i<(b);i++)
# define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
# define REP(i, n) for (int i = 0; i < (int)(n); i++)
# define RREP(i,n) for (int i=(n)-1;i>=0;i--)

# define int(x) int x; scanf("%d",&x);
# define vint(v,n) vector<int> v(n); REP(i,n) scanf("%d", &v[i]);
# define string(x) string x; cin >> x;

using namespace std;

struct card{
  char mark;
  int number;
};

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


void Bubble_Sort(vector<card> &A) {
  bool flag = true;
  while(flag== true) {
    flag = false;
    RFOR(i,0,A.size()){
      if(A[i].number < A[i-1].number){
	swap(A[i],A[i-1]);
	flag = true;
      }
    }
  }  
}

void Selection_Sort(vector<card> &A) {
  int minj;
  REP(i,A.size()){
    minj = i;
    FOR(j,i,A.size()){
      if(A[j].number < A[minj].number)
	minj = j;
    }
    if (i != minj){
      int tmp;
      swap(A[i],A[minj]);
    }
  }
}

int main() {
  int(x);
  vector<card> A;
  A.resize(x);
  REP(i,A.size())
    cin >> A[i].mark >> A[i].number;
  vector<card>B = A;
  bool flag = false;
  
  Bubble_Sort(A);
  Selection_Sort(B);
  
  REP(i,A.size()-1)
    cout << A[i].mark << A[i].number << " ";
  cout << A[A.size()-1].mark << A[A.size()-1].number << endl;
  cout << "Stable" << endl;


  REP(i,B.size()-1)
    cout << B[i].mark << B[i].number << " ";
  cout << B[B.size()-1].mark << B[B.size()-1].number << endl;
  REP(i,A.size())
    if(A[i].mark != B[i].mark){
      flag = true;
      break;
    }

  if(flag == true)
    cout << "Not stable" << endl;
  else
    cout << "Stable" << endl;
}
