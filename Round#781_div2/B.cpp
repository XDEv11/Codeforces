//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	map<int, int> mp{};
	for (auto& x : v) ++mp[x];
	int mxc{0};
	for (auto& [x, c] : mp) mxc = max(mxc, c);

	int ans{n - mxc};
	while (mxc < n) mxc *= 2, ++ans;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
