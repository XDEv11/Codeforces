//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	const ll L{1000000000};
	void solve() {
		int n;
		cin >> n;
		vector<ll> v(n);
		for (auto& x : v) cin >> x;

		ll l{-L}, r{L};
		while (r - l > 1) {
			ll m{(l + r) / 2};

			set<pair<int, int>> mn{};
			vector<vector<int>> g(n);
			for (int i{0}; i < n; ++i) {
				for (auto& [x, j] : mn) {
					if (v[i] - x >= m) {
						g[j].push_back(i);
						g[i].push_back(j);
					}
				}
				mn.emplace(v[i], i);
				if (mn.size() > 3) mn.erase(prev(mn.end()));
			}

			int c{};
			for (int i{0}; i < n; ++i) c += (g[i].size() >= 2);

			bool f{false};
			for (int i{0}; i < n; ++i) {
				int d{g[i].size() >= 2};
				for (auto& j : g[i]) d += (g[j].size() == 2);
				if (d == c) {
					f = true;
					break;
				}
			}
			(f ? r : l) = m;
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
