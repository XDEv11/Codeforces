//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>

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

const int maxv{1 << 19};
vector<ll> fac{[] {
	vector<ll> v(maxv + 1);
	v[0] = 1;
	for (int i{1}; i <= maxv; ++i) v[i] = MM(v[i - 1], i);
	return v;
}()};

void solve() {
	int k;
	cin >> k;
	int n{1 << k};
	vector<int> a(n);
	for (auto& x : a) cin >> x, x = (x == -1 ? -1 : x - 1);

	ll ans{1};

	vector<int> v(n, -1);
	for (int i{0}; i < n; ++i) {
		if (a[i] == -1) continue;
		v[a[i]] = i;
	}
	for (int i{1}; i <= n; i <<= 1) {
		int c{0};
		for (int j{i >> 1}; j < i; ++j) c += (v[j] == -1);
		ans = MM(ans, fac[c]);
	}

	for (int l{k - 1}; l >= 0; --l) {
		vector<int> t(a.size() / 2, -1);
		for (int i{0}; i < a.size(); i += 2) {
			if (a[i] != -1 && a[i + 1] != -1 && (a[i] < (1 << l)) == (a[i + 1] < (1 << l))) return cout << "0\n", []{}();
			else if (a[i] != -1 && a[i] < (1 << l)) t[i / 2] = a[i];
			else if (a[i + 1] != -1 && a[i + 1] < (1 << l)) t[i / 2] = a[i + 1];
			else if (a[i] == -1 && a[i + 1] == -1) ans = MM(ans, 2);
		}
		a = move(t);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
