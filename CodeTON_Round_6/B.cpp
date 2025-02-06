//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	if (n & 1) {
		int mn{};
		for (auto& x : a) mn ^= x;
		int mx{mn};
		for (auto& x : b) mx |= x;
		cout << mn << ' ' << mx << '\n';
	} else {
		int mx{};
		for (auto& x : a) mx ^= x;
		int mn{mx};
		for (auto& x : b) mn &= ~x;
		cout << mn << ' ' << mx << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
