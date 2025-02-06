//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

#include <numeric>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	long long ans{1};
	for (int i{0}; k--; ) {
		while (i < n && v[i] - (i + 1) < ans) ++i;
		ans += i;
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
