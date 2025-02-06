//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static void solve() {
	using ll = long long;

	int n, m;
	cin >> n >> m;
	vector<ll> a(n + m + 1), b{a};
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	ll ansn{}; {
		int cn{n + 1}, cm{m};
		for (int i{0}; i < n + m + 1; ++i) {
			if (!cm || (a[i] > b[i] && cn)) --cn, ansn += a[i];
			else --cm, ansn += b[i];
		}
	}
	ll ansm{}; {
		int cn{n}, cm{m + 1};
		for (int i{0}; i < n + m + 1; ++i) {
			if (!cm || (a[i] > b[i] && cn)) --cn, ansm += a[i];
			else --cm, ansm += b[i];
		}
	}

	vector<ll> ans(n + m + 1); {
		int cn{n}, cm{m};
		for (int i{0}; i < n + m; ++i) {
			if (!cm || (a[i] > b[i] && cn)) {
				--cn, ans[i] = ansn - a[i];
				if (i == n + m - 1) ans[n + m] = ansn - a[n + m];
			} else {
				--cm, ans[i] = ansm - b[i];
				if (i == n + m - 1) ans[n + m] = ansm - b[n + m];
			}
		}
	}

	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
