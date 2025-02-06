//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	ll x;
	cin >> x;

	int hi{1000000000}, lo{-hi};
	vector<int> ans{};
	while (x > 1) {
		if (x & 1) ans.push_back(lo++), x -= 1;
		else ans.push_back(hi--), x /= 2;
	}
	reverse(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (auto& e : ans) cout << e << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
