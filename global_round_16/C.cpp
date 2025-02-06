#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i{0}; i < n; ++i) {
		char a; cin >> a;
		v[i] += a - '0';
	}
	for (int i{0}; i < n; ++i) {
		char b; cin >> b;
		v[i] += b - '0';
	}

	vector<bool> p(n, false);
	int ans{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] == 1) ans += 2;
		else if (v[i] == 0) {
			if (i - 1 >= 0 && !p[i - 1] && v[i - 1] == 2) ans += 2;
			else if (i + 1 < n && v[i + 1] == 2) ans += 2, p[i + 1] = true;
			else ans += 1;
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
