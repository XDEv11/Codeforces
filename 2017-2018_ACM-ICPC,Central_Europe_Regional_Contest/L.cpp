//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<vector<int>> a(4003, vector<int>(4003)), b{a};
	for (int i{0}; i < n; ++i) {
		char t;
		int x, y, l;
		cin >> t >> x >> y >> l;
		if (t == 'A') {
			x = x - l / 2 + 2000, y = y - l / 2 + 2000;
			a[x][y] = max(a[x][y], l);
		} else {
			x = x - l / 2 + 2000, y = y + 2000;
			b[x][y] = max(b[x][y], l / 2);
		}
	}

	for (int i{0}; i <= 4000; ++i)
		for (int j{0}; j <= 4000; ++j) {
			a[i + 1][j] = max(a[i + 1][j], a[i][j] - 1);
			a[i][j + 1] = max(a[i][j + 1], a[i][j] - 1);
			a[i + 1][j + 1] = max(a[i + 1][j + 1], a[i][j] - 1);
			if (j - 1 >= 0) b[i + 1][j - 1] = max(b[i + 1][j - 1], b[i][j] - 1);
			b[i + 1][j + 1] = max(b[i + 1][j + 1], b[i][j] - 1);
			b[i + 2][j] = max(b[i + 2][j], b[i][j] - 1);
		}

	int ans{};
	for (int i{0}; i <= 4000; ++i)
		for (int j{0}; j <= 4000; ++j) {
			if (a[i][j]) ans += 4;
			else {
				if ((i - 1 >= 0 && b[i - 1][j]) || b[i][j]) ++ans;
				if (b[i][j] || b[i][j + 1]) ++ans;
				if (b[i][j + 1] || (i - 1 >= 0 && b[i - 1][j + 1])) ++ans;
				if (i - 1 >= 0 && (b[i - 1][j] || b[i - 1][j + 1])) ++ans;
			}
		}

	cout << ans / 4;
	switch (ans % 4) {
		break; case 0: cout << ".00\n";
		break; case 1: cout << ".25\n";
		break; case 2: cout << ".50\n";
		break; case 3: cout << ".75\n";
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
