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

#define MAX 500000

int L[MAX/2 + 2],R[MAX/2 + 2];
int cnt;

void merge(int A[],int n, int left,int mid,int right){
  int n1 = mid-left;
  int n2 = right-mid;

  REP(i,n1)
    L[i] = A[left+i];
  REP(i,n2)
    R[i] = A[mid+i];

  L[n1] = 2000000000;
  R[n2] = 2000000000;

  int i =0,j=0;
  for(int k = left;k < right; k++){
    cnt++;
    if(L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];
  }
}

void mergeSort(int A[],int n,int left,int right){
  if((left+1) < right){
    int  mid = (left + right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int main() {
  int(n);
  int A[n];
  REP(i,n)
    cin >> A[i];

  mergeSort(A,n,0,n);

  REP(i,n){
    if (i)
      cout << " ";
    cout << A[i];
  }
  cout << endl;
  cout << cnt << endl;
}
