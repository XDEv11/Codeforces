//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll nl{0}, nr{numeric_limits<ll>::max()};

	vector<ll> ans{};
	int q;
	cin >> q;
	while (q--) {
		int t; ll a, b, n;
		cin >> t >> a >> b;
		if (t == 1 && cin >> n) {
			ll l, r;
			if (n == 1) l = 0, r = a;
			else l = (n - 2) * (a - b) + a + 1, r = (n - 1) * (a - b) + a;

			if (nl > r || nr < l) ans.push_back(0);
			else ans.push_back(1), nl = max(nl, l), nr = min(nr, r);
		} else if (t == 2) {
			ll k;
			if (nl <= a) k = 0;
			else k = (nl - a + (a - b - 1)) / (a - b);

			if (k * (a - b) + a < nr) ans.push_back(-1);
			else ans.push_back(k + 1);
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
