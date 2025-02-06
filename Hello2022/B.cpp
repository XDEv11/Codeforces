//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <limits>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 3>> v(n);
	for (auto& [l, r, c] : v) cin >> l >> r >> c;

	array<int, 3> L{numeric_limits<int>::max(), 0, 0};
	array<int, 3> R{0, numeric_limits<int>::min(), 0};
	array<int, 3> W{numeric_limits<int>::max(), numeric_limits<int>::min(), 0};
	for (int i{0}; i < n; ++i) {
		if (v[i][0] < L[0] || (v[i][0] == L[0] && v[i][2] < L[2])) L = v[i];

		if (v[i][1] > R[1] || (v[i][1] == R[1] && v[i][2] < R[2])) R = v[i];

		if (v[i][0] < W[0] || v[i][1] > W[1] || (v[i][0] == W[0] && v[i][1] == W[1] && v[i][2] < W[2])) W = v[i];

		if (W[0] == L[0] && W[1] == R[1] && W[2] < L[2] + R[2]) cout << W[2] << '\n';
		else cout << L[2] + R[2] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
