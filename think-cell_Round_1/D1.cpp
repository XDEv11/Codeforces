//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	ll ans{};
	for (int i{0}; i < n; ++i)
		for (int j{i}; j < n; ++j)
			for (int k{i}; k <= j; ++k) {
				if (v[k] == '0') continue;
				++ans, k += 2;
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
