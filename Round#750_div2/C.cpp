#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int ans{-1};
	for (char c{'a'}; c <= 'z'; ++c) {
		bool f{true};
		int i{0}, j{n - 1}, cnt{0};
		while (i <= j) {
			int c1{0}, c2{0};
			while (i < j && v[i] == c) ++i, ++c1;
			while (i < j && v[j] == c) --j, ++c2;
			if (v[i] != v[j]) {
				f = false;
				break;
			}
			if (v[i] != c) cnt += abs(c1 - c2);
			++i, --j;
		}
		if (f) {
			if (ans == -1) ans = cnt;
			else ans = min(ans, cnt);
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
