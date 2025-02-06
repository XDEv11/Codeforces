//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<array<int, 2>> v(n + 1, {0, 0});
	for (int i{2}; i <= n; ++i) {
		if (v[i][0]) continue;

		int j{2};
		long long k{i * i};
		while (k <= n) {
			if (!v[k][0]) v[k] = {i, j};
			++j, k *= i;
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
