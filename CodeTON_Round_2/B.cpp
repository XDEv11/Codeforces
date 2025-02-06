//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(n);
	for (auto& e : v) cin >> e;

	int ans{0};
	int al{v[0] - x}, ar{v[0] + x};
	for (int i{1}; i < n; ++i) {
		int l{v[i] - x}, r{v[i] + x};
		if (ar < l || r < al) ++ans, al = l, ar = r;
		else al = max(al, l), ar = min(ar, r);
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
