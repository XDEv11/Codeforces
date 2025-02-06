//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int d{};
	array<int, 26> cnt{};
	for (auto& x : v) d += (cnt[x - 'a']++ == 0);

	int ans{};
	for (int i{n - 1}; i >= 0; --i) {
		ans += d;
		d -= (--cnt[v[i] - 'a'] == 0);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
