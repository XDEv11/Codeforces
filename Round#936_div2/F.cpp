//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	while (q--) {
		int l, r;
		cin >> l >> r, --l, --r;

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
