//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<ll>> c(n, vector<ll>(m));
	for (auto& v : c)
		for (auto& x : v) cin >> x;

	for (int i{0}; i < n; ++i) {
		int i{0}, j{m};
		while (i + 1 < j) {

		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
