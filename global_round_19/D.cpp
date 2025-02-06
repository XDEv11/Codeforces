//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	vector<int> s(n);
	s[0] = a[0] + b[0];
	for (int i{1}; i < n; ++i) s[i] = s[i - 1] + a[i] + b[i];

	map<int, int> dp{};
	dp.emplace(a[0], 0);
	for (int i{1}; i < n; ++i) {
		map<int, int> dp2{};
		for (auto& [s1, x] : dp) {
			auto s2{s[i - 1] - s1};
			auto it1{dp2.find(s1 + a[i])}, it2{dp2.find(s1 + b[i])};
			if (it1 == dp2.end()) dp2.emplace(s1 + a[i], x + s1 * a[i] + s2 * b[i]);
			else it1->second = min(it1->second, x + s1 * a[i] + s2 * b[i]);
			if (it2 == dp2.end()) dp2.emplace(s1 + b[i], x + s1 * b[i] + s2 * a[i]);
			else it2->second = min(it2->second, x + s1 * b[i] + s2 * a[i]);
		}
		dp = move(dp2);
	}

	int ans{numeric_limits<int>::max()};
	for (auto& [s1, x] : dp) ans = min(ans, 2 * x);
	for (int i{0}; i < n; ++i) ans += (a[i] * a[i] + b[i] * b[i]) * (n - 1);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
