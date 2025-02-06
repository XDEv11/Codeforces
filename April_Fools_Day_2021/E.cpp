#include <iostream>
#include <vector>
#include <optional>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> b{};
	for (int i{0}; i < n; ++i)
		for (int j{0}; j < m; ++j) {
			char c;
			cin >> c;
			if (c == '*') b.emplace_back(i, j);
		}

	int ans{0};

	int X{-1}, Y{-1};
	while (true) {
		optional<int> mn{};
		int _X, _Y;
		for (auto& [x, y] : b) {
			int d{(x - X) + (y - Y)};
			if (x < X || y < Y || d == 0) continue;
			if (!mn || d < mn) mn = d, _X = x, _Y = y;
		}
		if (!mn) break;

		X = _X, Y = _Y, ++ans;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
