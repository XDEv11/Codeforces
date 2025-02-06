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
		int n, s, t;
		cin >> n >> s >> t, s *= 2, t *= 2;
		vector<int> v(n);
		for (auto& x : v) cin >> x, x *= 2;

		int ans{v[0]}, p{s};
		for (int i{1}; p < t && i < n; ++i) {
			if (p < v[i] - ans) {
				int x{(v[i] - ans - p) / 2};
				ans += x;
				p += x + s;
			} else if (p < v[i] + ans) {
				p += s;
			} else if (p < v[i] + ans + s) {
				p = v[i] + ans + s;
			}
		}
		if (p < t) ans += t - p;

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
