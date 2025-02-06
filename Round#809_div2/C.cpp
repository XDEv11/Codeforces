//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<long long> cnt(n);
	for (int i{1}; i <= n - 2; ++i) {
		if (i == 1 || i == 2) cnt[i] = 0;
		else cnt[i] = cnt[i - 2];
		cnt[i] += max(0, max(v[i - 1], v[i + 1]) + 1 - v[i]);
	}
	if (n & 1) cout << cnt[n - 2] << '\n';
	else {
		long long ans{cnt[n - 2]};
		for (int i{2}; i <= n - 2; i += 2) ans = min(ans, cnt[i - 1] + cnt[n - 2] - cnt[i]);
		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
