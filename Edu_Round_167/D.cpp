//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <queue>
#include <algorithm>

using namespace std;

namespace {
	bool solve() {
		int n, m;
		if (!(cin >> n >> m)) return false;
		vector<int> a(n), b(n), c(m);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;
		for (auto& x : c) cin >> x;

		vector<pair<int, int>> v(n);
		for (int i{0}; i < n; ++i) v[i] = {a[i] - b[i], a[i]};
		sort(v.begin(), v.end());
		{
			int j{0};
			for (int i{1}; i < n; ++i) {
				if (v[j].fi < v[i].fi && v[j].se > v[i].se) {
					v[++j] = v[i];
				}
			}
			v.resize(j + 1);
		}

		vector<int> dp(v[0].se);
		if (v.size() > 1) {
			for (int i{0}, j{v.size() - 1}; i < v[0].se; ++i) {
				if (i >= v[j - 1].se) --j;
				if (i >= v[j].se) dp[i] = dp[i - v[j].fi] + 2;
			}
		}

		long long ans{};
		for (auto& z : c) {
			if (z >= v[0].se) {
				int t{(z - v[0].se) / v[0].fi + 1};
				ans += t * 2, z -= t * v[0].fi;
			}
			ans += dp[z];
		}

		cout << ans << '\n';
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
