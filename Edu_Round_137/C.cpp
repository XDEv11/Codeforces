//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> c(n);
	vector<int> v(n);
	for (auto& x : c) cin >> x;
	for (auto& x : v) cin >> x;

	int ans{0};
	int i{0};
	while (i < n && c[i] != '0') ans += v[i++];
	while (i + 1 < n) {
		if (c[i + 1] == '0') {
			i = i + 1;
			continue;
		}
		int j{i + 2};
		while (j < n && c[j] != '0') ++j;
		int mn{numeric_limits<int>::max()};
		for (int k{i}; k < j; ++k) {
			mn = min(mn, v[k]);
			ans += v[k];
		}
		ans -= mn;
		i = j;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
