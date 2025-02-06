#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	array<int, 31> cnt; cnt.fill(0);
	for (auto& x : v)
		for (int i{0}; i <= 30; ++i) {
			if (x & (1 << i)) ++cnt[i];
		}

	for (int i{1}; i <= n; ++i) {
		bool flag{true};
		for (auto& x : cnt) {
			if (x % i) flag = false;
		}
		if (flag) cout << i << ' ';
	}
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
