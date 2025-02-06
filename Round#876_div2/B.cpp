//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <map>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<pair<ll, ll>> v(n);
	for (auto& [a, b] : v) cin >> a >> b;

	map<ll, vector<ll>> mp{};
	for (auto& [a, b] : v) mp[a].push_back(b);

	ll ans{0};
	for (auto& [a, b] : mp) {
		sort(b.rbegin(), b.rend());
		for (int i{0}; i < a && i < b.size(); ++i) ans += b[i];
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
