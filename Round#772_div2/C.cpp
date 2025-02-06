//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (v[n - 2] > v[n - 1]) return cout << "-1\n"s, []{}();

	vector<tuple<int, int, int>> ans{};
	if (v[n - 1] >= 0) {
		for (int i{n - 3}; i >= 0; --i) {
			v[i] = v[i + 1] - v[n - 1];
			ans.emplace_back(i, i + 1, n - 1);
		}
	} else if (!is_sorted(v.begin(), v.end())) return cout << "-1\n"s, []{}();

	cout << ans.size() << '\n';
	for (auto& [x, y, z] : ans) cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
