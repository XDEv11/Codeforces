//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	vector<int> v(m);
	for (auto& x : v) cin >> x;

	int k, t;
	if (a < b) k = b - a - 1, t = b - 1 - 1;
	else k = a - b - 1, t = n - b - 1;
	sort(v.begin(), v.end());

	int ans{};
	for (int i{min(m - 1, k - 1)}, j{0}; j < k; ++j) {
		while (i >= 0 && j + v[i] > t) --i;
		if (i < 0) break;
		++ans, --i;
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
