//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(2 * n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	int ans{};
	for (int i{0}; i < 2 * n; i += 2) ans += v[i];

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
