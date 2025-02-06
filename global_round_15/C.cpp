#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> m(2 * n, -1);
	for (int i{0}; i < k; ++i) {
		int x, y;
		cin >> x >> y, --x, --y;
		m[x] = y;
		m[y] = x;
	}

	vector<int> um{};
	for (int i{0}; i < 2 * n; ++i)
		if (m[i] == -1) um.push_back(i);

	for (int i{0}; i < n - k; ++i) {
		m[um[i]] = um[n - k + i];
		m[um[n - k + i]] = um[i];
	}

	int ans{0};
	for (int i{0}; i < 2 * n; ++i) {
		if (m[i] < i) continue;
		for (int j{i + 1}; j < 2 * n; ++j) {
			if (m[j] < j) continue;

			if (m[i] > j && m[j] > m[i]) ++ans;
		}
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
