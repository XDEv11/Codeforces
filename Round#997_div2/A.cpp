//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> v(n);
		for (auto& [x, y] : v) cin >> x >> y;

		int ans{m * 2};
		for (int i{1}; i < n; ++i) ans += v[i].fi + v[i].se;

		cout << (ans * 2) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
