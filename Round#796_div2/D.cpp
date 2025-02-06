//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	long long n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long s{0}, ans{0};
	for (int i{0}; i < n; ++i) {
		s += v[i];
		if (i >= k) s -= v[i - k];
		ans = max(ans, s);
	}
	if (k >= n) {
		ans += n * (k - n);
		ans += n * (0 + (n - 1)) / 2;
	} else ans += k * (0 + (k - 1)) / 2;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
