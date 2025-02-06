//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mf{[] {
	const int maxn{1000000};
	vector<int> t(maxn + 1);
	for (long long i{2}; i <= maxn; ++i) {
		if (t[i]) continue;
		t[i] = i;
		for (long long j{i * i}; j <= maxn; j += i) 
			if (!t[j]) t[j] = i;
	}
	return t;
}()};

void solve() {
	int n, m;
	cin >> n >> m;

	cout << (n == 1 || mf[n] > m ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
