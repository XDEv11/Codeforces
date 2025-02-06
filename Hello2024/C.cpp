//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x, --x;

	int ans{}, a{n}, b{n};
	for (int i{0}; i < n; ++i) {
		if (v[i] > a) ++ans, b = a, a = v[i];
		else if (v[i] > b) a = v[i];
		else b = v[i];
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
