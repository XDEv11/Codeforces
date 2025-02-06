//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	array<int, 101> cnt{};
	for (auto& x : v) ++cnt[x];

	int ans{0};
	for (auto& x : cnt) ans += min(x, c);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
