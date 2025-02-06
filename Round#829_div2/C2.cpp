//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <utility>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int c{accumulate(v.begin(), v.end(), 0)};
	if (c & 1) return cout << "-1\n", []{}();

	vector<pair<int, int>> ans{};
	for (int i{0}; i < n; ++i) {
		if (c > 0 && v[i + 1] == 1) {
			ans.emplace_back(i, i + 1);
			i = i + 1;
			c -= 2;
		} else if (c < 0 && v[i + 1] == -1) {
			ans.emplace_back(i, i + 1);
			i = i + 1;
			c += 2;
		} else ans.emplace_back(i, i);
	}

	cout << ans.size() << '\n';
	for (auto& [l, r] : ans) cout << l + 1 << ' ' << r + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
