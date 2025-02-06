//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> a(n), b(n), c(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;
	for (auto& x : c) cin >> x;

	bool ans{false};
	for (int i{0}; i < n; ++i) {
		if (c[i] != a[i] && c[i] != b[i]) {
			ans = true;
			break;
		}
	}

	cout << (ans ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
