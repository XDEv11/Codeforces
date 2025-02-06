#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<bool> v(n + 2);
	v[0] = v[n + 1] = 0;
	for (int i{1}; i <= n; ++i) {
		char c;
		cin >> c;
		v[i] = (c == '1');
	}

	for (int j{0}; j < m; ++j) {
		bool flag{true};
		auto v2{v};
		for (int i{1}; i <= n; ++i) {
			if (!v[i] && (v[i - 1] ^ v[i + 1]))
				v2[i] = 1, flag = false;
		}
		v = move(v2);
		if (flag) break;
	}

	for (int i{1}; i <= n; ++i) cout << v[i];
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
