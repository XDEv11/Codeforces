#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, len;
	cin >> n >> len;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int r{1};
	while (r < n) {
		bool flag{false};
		for (int j{0}, k{r}; j < r; ++j, k = (k + 1) % n) {
			if (v[j] != v[k]) {
				if (v[j] < v[k]) flag = true;
				break;
			}
		}
		if (flag) break;

		++r;
	}

	int i{0};
	while (len--) cout << v[i], i = (i + 1) % r;
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
