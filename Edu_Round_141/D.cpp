//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;
	const ll mod{998244353};
	const int maxv{300 * 300}, mnv{300 * -300};

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> mp(maxv - mnv + 1);
	mp[v[1] - mnv] = 1;
	for (int i{2}; i < n; ++i) {
		vector<ll> mp2(mp.size());
		for (int x{0}; x < mp.size(); ++x) {
			if (!mp[x]) continue;
			int x2{v[i] + x};
			if (x2 >= 0 && x2 < mp.size()) {
				mp2[x2] = (mp2[x2] + mp[x]) % mod;
			}
			x2 = v[i] - (x + mnv) - mnv;
			if ((x + mnv) && x2 >= 0 && x2 < mp.size()) {
				mp2[x2] = (mp2[x2] + mp[x]) % mod;
			}
		}
		mp = move(mp2);
	}

	ll ans{0};
	for (auto& c : mp) ans = (ans + c) % mod;

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
