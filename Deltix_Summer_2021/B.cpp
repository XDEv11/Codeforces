#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int cnt{0};
	vector<int> odd{};
	for (int i{0}; i < n; ++i)
		if (v[i] & 1) ++cnt, odd.push_back(i);

	if (cnt != n / 2 && cnt != (n + 1) / 2) return cout << "-1\n"s, []{}();

	int ans1{numeric_limits<int>::max()}, ans2{numeric_limits<int>::max()};
	if (cnt == n / 2) {
		ans1 = 0;
		for (int i{0}; i < odd.size(); ++i) ans1 += abs(i * 2 + 1 - odd[i]);
	}
	if (cnt == (n + 1) / 2) {
		ans2 = 0;
		for (int i{0}; i < odd.size(); ++i) ans2 += abs(i * 2 - odd[i]);
	}

	cout << min(ans1, ans2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
