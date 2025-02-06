//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(m);
	for (auto& x : v) cin >> x, --x;

	sort(v.begin(), v.end());

	int ans{m - 2};
	for (int i{0}; i < m; ++i) ans += ((v[i] + 2) % n == v[(i + 1) % m]);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
