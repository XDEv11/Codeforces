//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	long long ans{0};
	for (int i{0}; i + 1 < n; ++i) ans += abs(v[i] - v[i + 1]);

	int c1{min(v[0] - 1, v[n - 1] - 1)};
	for (int i{0}; i + 1 < n; ++i) {
		c1 = min(c1, 2 * (min(v[i], v[i + 1]) - 1));
	}
	ans += c1;

	if (*max_element(v.begin(), v.end()) < x) {
		int c2{min(x - v[0], x - v[n - 1])};
		for (int i{0}; i + 1 < n; ++i) {
			c2 = min(c2, 2 * (x - max(v[i], v[i + 1])));
		}
		ans += c2;
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
