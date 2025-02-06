//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		map<int, int> cnt{};
		for (auto& x : v) ++cnt[x];

		vector<int> t{};
		for (auto& [x, y] : cnt) t.push_back(y);
		sort(t.begin(), t.end());

		int ans{t.size()};
		for (int i{0}; i < t.size() - 1 && k >= t[i]; ++i) k -= t[i], --ans;

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
