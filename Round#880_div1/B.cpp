//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define fi first
#define se second

using namespace std;

void solve() {
	using ll = long long;

	int n; ll m; int k;
	cin >> n >> m >> k;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	if (k > n) return cout << m + 1 << " 0\n", []{}();
	sort(v.begin(), v.end());

	ll ans1{}, ans2{0};
	for (int i{0}, j; i < n; i = j) {
		j = i + 1;
		while (j < n && v[j] == v[i]) ++j;

		if (i < k && (i ? v[i - 1] : -1) < v[i] - 2) {
			ll y{i + k - 1 < n ? (v[i] - 2 + v[i + k - 1] - 1) / 2 : m};
			if (y + 1 > ans1) ans1 = y + 1, ans2 = v[i] - 2;
		}
		if (i < k && (i ? v[i - 1] : -1) < v[i] - 1) {
			ll y{i + k - 1 < n ? (v[i] - 1 + v[i + k - 1] - 1) / 2 : m};
			if (y + 1 > ans1) ans1 = y + 1, ans2 = v[i] - 1;
		}
		{
			ll x{j - k >= 0 ? (v[j - k] + v[i]) / 2 : -1};
			ll y{i + k - 1 < n ? (v[i] + v[i + k - 1] - 1) / 2 : m};
			if (y - x > ans1) ans1 = y - x, ans2 = v[i];
		}
		if (v[i] + 1 < (j < n ? v[j] : m + 1)) {
			ll x{j - k >= 0 ? (v[j - k] + v[i] + 1) / 2 : -1};
			ll y{j + k - 1 < n ? (v[i] + 1 + v[j + k - 1] - 1) / 2 : m};
			if (y - x > ans1) ans1 = y - x, ans2 = v[i] + 1;
		}
		if (v[i] + 2 < (j < n ? v[j] : m + 1)) {
			ll x{j - k >= 0 ? (v[j - k] + v[i] + 2) / 2 : -1};
			ll y{j + k - 1 < n ? (v[i] + 2 + v[j + k - 1] - 1) / 2 : m};
			if (y - x > ans1) ans1 = y - x, ans2 = v[i] + 2;
		}
	}

	cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
