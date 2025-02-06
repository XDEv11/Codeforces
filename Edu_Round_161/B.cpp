//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> cnt(n + 1);
	for (auto& x : v) ++cnt[x];

	ll ans{};
	for (int i{0}, s{0}; i <= n; s += cnt[i++]) {
		ans += ll(s) * cnt[i] * (cnt[i] - 1) / 2;
		ans += ll(cnt[i]) * (cnt[i] - 1) * (cnt[i] - 2) / 6;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
