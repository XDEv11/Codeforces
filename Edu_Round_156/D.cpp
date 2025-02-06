//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{998244353};
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
	int n, m;
	if (!(cin >> n >> m)) return false;
	vector<char> v(n - 1);
	for (auto& x : v) cin >> x;

	ll ans{1};
	for (int i{n - 2}; i > 0; --i) {
		if (v[i] == '?') ans = MM(ans, i);
	}

	for (int k{0}; ; ++k) {
		cout << (v[0] != '?' ? ans : 0) << '\n';
		if (k == m) break;

		int i; char x;
		cin >> i >> x, --i;
		if (i && v[i] == '?') ans = MD(ans, i);
		v[i] = x;
		if (i && v[i] == '?') ans = MM(ans, i);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
