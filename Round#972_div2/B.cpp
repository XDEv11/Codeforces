//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int k, n, q;
		cin >> k >> n >> q;
		vector<int> v(n);
		for (auto& x : v) cin >> x, --x;

		sort(v.begin(), v.end());

		while (q--) {
			int p;
			cin >> p, --p;

			int l{-1}, r{n};
			while (r - l > 1) {
				int m{(l + r) / 2};
				(v[m] < p ? l : r) = m;
			}

			if (r == 0) cout << v[0] << '\n';
			else if (l == n - 1) cout << (k - 1 - v[n - 1]) << '\n';
			else cout << ((v[r] - v[l]) / 2) << '\n';
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
