//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;
	if (v[0] != v[n - 1]) return cout << "0\n", []{}();

	int j{1}, k{n - 2};
	while (j < n && v[j] == v[0]) ++j;
	if (j == n) return cout << "-1\n", []{}();
	while (v[k] == v[n - 1]) --k;

	int ans{min(j, (n - 1) - k)};
	for (int i{j + 1}, l{j}; i <= k; ++i) {
		if (v[i] == v[0]) continue;
		ans = min(ans, i - 1 - l);
		l = i;
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
