//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
const ll mod{1000000007};
const ll maxv{100000};
const vector<ll> fac{[](){
	vector<ll> v(maxv + 1);
	v[0] = 1;
	for (ll i{1}; i <= maxv; ++i) v[i] = (v[i - 1] * i) % mod;
	return v;
}()};

void solve() {
	ll n;
	cin >> n;

	cout << (n * (n - 1) % mod * fac[n] % mod) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
