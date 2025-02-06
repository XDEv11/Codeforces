#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mtx(n, vector<int>(m));
	for (auto& vt : mtx)
		for (auto& x : vt) {
			char c;
			cin >> c;
			x = (c == 'X');
		}

	int s{m % 3 ? 0 : 1};
	for (int j{s}; j < m; j += 3) // 0, 3, 6, 9
		for (int i{0}; i < n; ++i)
			mtx[i][j] = 1;
	for (int j{s}; j + 2 < m; j += 3) {
		bool flag{false};
		for (int i{0}; i < n; ++i)
			if (mtx[i][j + 1] || mtx[i][j + 2]) {
				mtx[i][j + 1] = mtx[i][j + 2] = 1;
				flag = true;
				break;
			}
		if (!flag) mtx[0][j + 1] = mtx[0][j + 2] = 1;
	}

	for (auto& vt : mtx) {
		for (auto& x : vt) cout << (x ? 'X' : '.');
		cout << '\n';
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
