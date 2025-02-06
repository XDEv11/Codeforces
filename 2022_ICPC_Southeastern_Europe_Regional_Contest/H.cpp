#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	reverse(v.begin(), v.end());

	vector<pair<int, int>> ans{};
	for (int i{1}; i < n; ++i) {
		int j{0};
		while (j < i && v[j] > v[i]) ++j;
		for (int _{0}; _ < j; ++_) ans.emplace_back(1, 3);
		for (int _{j}; _ < i; ++_) ans.emplace_back(1, 2);
		ans.emplace_back(1, 3);
		for (int _{j}; _ < i; ++_) ans.emplace_back(2, 1);
		ans.emplace_back(3, 1);
		for (int _{0}; _ < j; ++_) ans.emplace_back(3, 1);

		for (int k{i}; k - 1 >= j; --k) swap(v[k], v[k - 1]);
	}
	for (int _{0}; _ < n; ++_) ans.emplace_back(1, 3);

	cout << ans.size() << '\n';
	for (auto& [x, y] : ans) cout << x << ' ' << y << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}
