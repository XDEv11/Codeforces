//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		array<vector<ll>, 3> a{}; a.fill(vector<ll>(n));
		for (auto& v : a)
			for (auto& x : v) cin >> x;
		ll t{};
		for (auto& x : a[0]) t += x;
		t = (t + 2) / 3;

		array<vector<int>, 3> v{}; v.fill(vector<int>(n + 1, -1));
		for (int k{0}; k < 3; ++k) {
			ll s{};
			for (int i{0}, j{0}; i < n; ++i) {
				while (j < n && s < t) s += a[k][j++];
				if (s >= t) v[k][i] = j;
				else break;
				s -= a[k][i];
			}
		}

		array<int, 3> p{0, 1, 2};
		do {
			bool f{true};
			array<array<int, 2>, 3> ans{};
			for (int k{0}, i{0}; k < 3; ++k) {
				int j{v[p[k]][i]};
				if (j == -1) {
					f = false;
					break;
				}
				ans[p[k]] = {i, j};
				i = j;
			}
			if (!f) continue;

			for (auto& x : ans) cout << (x[0] + 1) << ' ' << x[1] << ' ';
			cout << '\n';
			return ;
		} while (next_permutation(p.begin(), p.end()));
		cout << "-1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
