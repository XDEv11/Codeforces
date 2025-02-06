//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<int> p(n);
	p[0] = v[0];
	for (int i{1}; i < n; ++i) p[i] = p[i - 1] ^ v[i];

	int ans{};
	array<bool, 256> ck{};
	ck[0] = true;
	for (int i{0}; i < n; ++i) {
		for (int j{0}; j < 256; ++j) {
			if (!ck[j]) continue;
			ans = max(ans, p[i] ^ j);
		}
		ck[p[i]] = true;
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
