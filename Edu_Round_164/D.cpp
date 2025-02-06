//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MN(ll a) { return (a % PM + PM) % PM; }
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	ll ans{};
	vector<ll> cnt(5001);
	cnt[0] = 1;
	for (int i{0}; i < n; ++i)
		for (int j{5000 - v[i]}; j >= 0; --j) {
			int k{j + v[i]};
			ans = MA(ans, MM(cnt[j], j >= v[i] ? (k + 1) / 2 : v[i]));
			cnt[k] = MA(cnt[k], cnt[j]);
		}

	cout << ans << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
