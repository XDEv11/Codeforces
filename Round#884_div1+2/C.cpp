//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	bool f{true};
	for (int i{1}; i <= n; ++i) {
		if (v[i] > 0) {
			f = false;
			break;
		}
	}
	if (f) return cout << *max_element(v.begin() + 1, v.end()) << '\n', []{}();

	vector<ll> dp(n + 2);
	for (int i{1}; i <= n; ++i) dp[i + 1] = dp[i - 1] + max(0ll, v[i]);

	cout << max(dp[n], dp[n + 1]) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
