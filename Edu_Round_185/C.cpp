//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll k;
		cin >> n >> k;
		vector<ll> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int l{0}, r{n + 1};
		while (r - l > 1) {
			int m{(l + r) / 2};
			bool f{true};
			for (int i{0}; i < m; ++i) {
				if ((a[i] + 1) * (b[m - 1 - i] + 1) - 1 > k) {
					f = false;
					break;
				}
			}

			(f ? l : r) = m;
		}

		cout << l << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
