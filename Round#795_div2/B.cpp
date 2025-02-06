//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	map<int, vector<int>> mp{};
	for (int i{0}; i < n; ++i) mp[v[i]].push_back(i);

	vector<int> ans(n);
	for (auto& [k, v] : mp) {
		if (v.size() == 1) return cout << "-1\n", []{}();
		for (int i{0}; i < v.size(); ++i) ans[v[i]] = v[(i + 1) % v.size()];
	}

	for (auto& x : ans) cout << x + 1 << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
