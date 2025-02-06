//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(2 * n);
	for (auto& x : v) cin >> x;

	int cnt{0};
	vector<pair<int, int>> ans{};
	for (int i{0}; i < 2 * n; ++i) {
		if (v[i] == '(') ++cnt;
		else if (v[i] == ')') --cnt;
		cout << cnt << ' ';
	}
	cout << '\n';

	cout << ans.size() << '\n';
	for (auto& [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
