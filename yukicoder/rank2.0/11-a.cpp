#include "bits/stdc++.h"
using namespace std;


int main() {
	long long W, H;
	cin >> W >> H;
	int N;
	cin >> N;
	set<int> ms, mk;
	for (int i = 0; i < N; i++)
	{
		int S, K;
		cin >> S >> K;
		ms.insert(S);
		mk.insert(K);
	}
	long long ans = 0;
	ans += ms.size() * H;
	ans += mk.size() * W;
	ans -= ms.size() * mk.size();
	ans -= N;
	cout << ans << endl;
}

