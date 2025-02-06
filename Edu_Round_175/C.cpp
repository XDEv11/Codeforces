//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<char> a(n);
		for (auto& x : a) cin >> x;
		vector<int> b(n);
		for (auto& x : b) cin >> x;

		int l{-1}, r{*max_element(b.begin(), b.end())};
		while (r - l > 1) {
			int m{(l + r) / 2};

			int c{};
			bool f{false};
			for (int i{0}; i < n; ++i) {
				if (b[i] <= m) continue;
				if (a[i] == 'B') {
					f = true;
				} else if (a[i] == 'R') {
					c += f;
					f = false;
				}
			}
			c += f;

			(c <= k ? r : l) = m;
		}

		cout << r << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
