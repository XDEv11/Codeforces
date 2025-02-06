#include <iostream>
#include <vector>
#include <array>
#include <numeric>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<array<int, 5>> v(n);
	for (auto& a : v)
		for (auto& x : a) cin >> x;

	vector<int> c(n); iota(c.begin(), c.end(), 0);

	while (c.size() > 1) {
		vector<int> nc{};
		for (int i{0}; i + 1 < c.size(); i += 2) {
			int cnt{0};
			for (int k{0}; k < 5; ++k) cnt += v[c[i]][k] < v[c[i + 1]][k];

			if (cnt >= 3) nc.push_back(c[i]);
			else nc.push_back(c[i + 1]);
		}
		if (c.size() & 1) nc.push_back(c.back());
		c = move(nc);
	}

	for (int j{0}; j < n; ++j) {
		if (j == c[0]) continue;

		int cnt{0};
		for (int k{0}; k < 5; ++k) cnt += v[c[0]][k] < v[j][k];

		if (cnt < 3) return cout << "-1\n"s, []{}();
	}
	cout << c[0] + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
