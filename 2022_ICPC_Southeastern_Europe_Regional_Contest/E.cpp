#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	using ll = long long;

	int n;
	if (!(cin >> n)) return false;
	vector<ll> v(2 * n);
	for (auto& x : v) cin >> x;

	vector<pair<ll, int>> tmp(2 * n);
	for (int i{0}; i < 2 * n; ++i) tmp[i] = {v[i], i};
	sort(tmp.begin(), tmp.end());

	ll ans{};
	for (int i{0}; i < 2 * n; i += 2) ans += tmp[i + 1].fi - tmp[i].fi;

	for (int i{0}; i < 2 * n; ) {
		int j{i};
		while (j < 2 * n && (tmp[j].se ^ tmp[j + 1].se) == 1) j += 2;
		if (j == i) {
			i += 2;
			continue;
		}
		int m{(j - i) / 2};
		vector<ll> a(m + 1);
		for (int k{0}; k <= m; ++k) {
			int idx{i + 2 * k};
			if (idx - 1 >= 0 && idx < 2 * n) a[k] = tmp[idx].fi - tmp[idx - 1].fi;
			else a[k] = 1000000000000000ll;
		}
		vector<ll> dp0(m + 1), dp1(m + 1);
		dp0[0] = 0, dp1[0] = a[0];
		for (int k{1}; k <= m; ++k) {
			dp0[k] = dp1[k - 1];
			dp1[k] = min(dp0[k - 1], dp1[k - 1]) + a[k];
		}
		ans += 2 * min(dp0[m], dp1[m]);
		i = j;
	}

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
