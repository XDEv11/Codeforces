//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> mtx(n, vector<char>(m));
	for (auto& v : mtx)
		for (auto& x : v) cin >> x;

	int mxa{0}, mna{0};
	for (auto& v : mtx) {
		int c{0}, d{0};
		for (int j{0}; j < m; ++j) {
			if (v[j] == '1') {
				if (d < m / 4 && j + 1 < m && v[j + 1] == '1') ++j, ++d;
				else ++c;
			}
		}
		mna += c + d;

		c = 0, d = 0; int e{0};
		for (int j{0}; j < m; ++j) {
			if (v[j] == '1') {
				if (d + e < m / 4 && j + 1 < m && v[j + 1] == '0') ++j, ++d;
				else ++c;
			} else if (d + e < m / 4 && j + 1 < m) {
				if (v[j + 1] == '1') ++j, ++d;
				else ++j, ++e;
			}
		}
		mxa += c + d - (m / 4 - (d + e));
	}

	cout << mna << ' ' << mxa << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
