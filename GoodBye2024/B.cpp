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
		int n;
		cin >> n;
		vector<pair<int, int>> v(n);
		for (auto& [x, y] : v) cin >> x >> y;

		vector<int> cnt(2 * n + 1);
		for (auto& [x, y] : v) {
			if (x == y) ++cnt[x];
		}
		vector<int> ps(2 * n + 1);
		ps[0] = (cnt[0] > 0);
		for (int i{1}; i <= 2 * n; ++i) ps[i] = ps[i - 1] + (cnt[i] > 0);

		for (auto& [x, y] : v) {
			if (x == y) cout << (cnt[x] > 1 ? '0' : '1');
			else cout << (ps[y] - ps[x - 1] == y - (x - 1) ? '0' : '1');
		}
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
