//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	const long long mod{998244353};

	int n, k;
	cin >> n >> k;

	vector<long long> ans(n + 1); ans[0] = 1;
	vector<long long> cnt(n + 1); cnt[0] = 1;
	long long x{0};
	for (int i{0}; x + k + i <= n; ++i) {
		x += k + i;
		for (int j{0}; x + j + k + i <= n; ++j) cnt[j + k + i] = (cnt[j + k + i] + cnt[j]) % mod;
		for (int j{0}; x + j <= n; ++j) ans[x + j] = (ans[x + j] + cnt[j]) % mod;
	}

	for (int i{1}; i <= n; ++i) cout << ans[i] << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
