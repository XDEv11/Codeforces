//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	int c1{}, c2{};
	for (int i{0}; i < n; ++i) {
		c1 += (a[i] != b[i]);
		c2 += (a[i] != b[n - 1 - i]);
	}

	int ans1{c1 ? 2 * c1 - (c1 & 1) : 0}, ans2;
	if (!c2) ans2 = 2;
	else ans2 = 2 * c2 - !(c2 & 1);
	cout << min(ans1, ans2) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
