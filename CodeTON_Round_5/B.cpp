//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <vector>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	array<vector<int>, 3> b{}; b.fill(vector<int>(n));
	for (auto& v : b)
		for (auto& e : v) cin >> e;

	int y{};
	for (int k{0}; k < 3; ++k)
		for (int i{0}; i < n; ++i) {
			if ((b[k][i] | x) > x) break;
			y |= b[k][i];
		}

	cout << (y == x ? "Yes\n" : "No\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
