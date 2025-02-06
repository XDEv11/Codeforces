//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	for (auto& v : g)
		for (auto& x : v) cin >> x;

	int ans{0};
	for (auto& v : g)
		for (auto& x : v) ans ^= x;
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
