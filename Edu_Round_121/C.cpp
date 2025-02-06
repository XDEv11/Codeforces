//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> k(n), h(n);
	for (auto& x : k) cin >> x;
	for (auto& x : h) cin >> x;

	long long ans{0};
	for (int i{n - 1}; i >= 0; ) {
		int j{i};
		long long l{numeric_limits<long long>::max()};
		while (l = min(l, k[j] - h[j] + 1), j - 1 >= 0 && l <= k[j - 1]) --j;
		long long len{k[i] - l + 1};
		ans += (1 + len) * len / 2;
		i = j - 1;
	}
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
