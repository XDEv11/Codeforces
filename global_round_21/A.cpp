//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, z;
	cin >> n >> z;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	for (auto& x : v) ans = max(ans, x | z);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
