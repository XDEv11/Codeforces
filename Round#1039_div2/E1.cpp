//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, c;
		cin >> n >> c;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		auto check{[&](int m) -> pair<int, int> {
			vector<int> t(n + 1);
			for (int i{0}; i < n; ++i) t[i + 1] = (v[i] >= m);
			for (int i{0}; i < n; ++i) t[i + 1] += t[i];
			for (int i{c - 1}, j{0}; i < n; ++i) {
				if (t[i + 1 - c] - t[j] <= (i + 1 - c - j) / 2) j = i + 1 - c;
				if (t[i + 1] - t[j] >= (i + 1 - j + 1) / 2) return {j, i};
			}
			return {-1, -1};
		}};

		int l{1}, r{n + 1};
		int a, b;
		while (r - l > 1) {
			int m{(l + r) / 2};
			tie(a, b) = check(m);
			if (a == -1) r = m;
			else l = m;
		}
		tie(a, b) = check(l);

		cout << l << ' ' << (a + 1) << ' ' << (b + 1) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
