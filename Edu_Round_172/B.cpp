//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x, --x;

		vector<int> cnt(n);
		for (auto& x : v) ++cnt[x];

		vector<int> cc(n + 1);
		for (auto& x : cnt) ++cc[x];

		int ans{(cc[1] + 1) / 2 * 2};
		for (int i{2}; i <= n; ++i) ans += cc[i];

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
