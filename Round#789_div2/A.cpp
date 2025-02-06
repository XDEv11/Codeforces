//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	array<int, 101> cnt{};
	bool same{false};
	for (auto& x : v) {
		if (cnt[x]) same = true;
		++cnt[x];
	}

	if (cnt[0]) cout << n - cnt[0] << '\n';
	else if (same) cout << n << '\n';
	else cout << n + 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
