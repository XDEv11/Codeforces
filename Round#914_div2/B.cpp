//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<pair<ll, int>> v(n);
	for (int i{0}; i < n; ++i) cin >> v[i].fi, v[i].se = i;
	sort(v.begin(), v.end());

	vector<ll> t(n);
	t[0] = v[0].fi;
	for (int i{1}; i < n; ++i) t[i] = t[i - 1] + v[i].fi;
	for (int i{n - 1}; i >= 1; --i) t[i] = v[i].fi - t[i - 1];

	vector<int> ans(n);
	for (int i{n - 1}, j{n}; i >= 0; --i) {
		ans[v[i].se] = j;
		if (t[i] > 0) j = i;
	}

	for (auto& x : ans) cout << (x - 1) << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
