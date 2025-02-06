//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	for (int i{0}; i < n - 1 - i; ++i) ans = gcd(ans, abs(v[i] - v[n - 1 - i]));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
