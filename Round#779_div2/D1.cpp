//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>

#include <cassert>

using namespace std;

void solve() {
	int l, r;
	cin >> l >> r;
	assert(l == 0 && "l should be 0 in D1.");
	vector<int> v(r + 1);
	for (auto& e : v) cin >> e;

	int x{0};
	for (int b{0}; b < 17; ++b) {
		int cnt1{0}, cnt2{0};
		for (int i{0}; i <= r; ++i) cnt1 += (i >> b) & 1;
		for (int i{0}; i <= r; ++i) cnt2 += (v[i] >> b) & 1;
		if (cnt1 != cnt2) x |= (1 << b);
	}
	cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
