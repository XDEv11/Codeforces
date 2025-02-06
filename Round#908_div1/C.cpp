//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int m;
	cin >> m;
	vector<pair<pair<ll, ll>, vector<pair<ll, ll>>>> v(m);
	for (auto& x : v) {
		int n;
		cin >> n >> x.fi.fi >> x.fi.se;
		x.se.resize(n);
		for (auto& [y, z] : x.se) cin >> y;
		for (auto& [y, z] : x.se) cin >> z;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
