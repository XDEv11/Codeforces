//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

ll power(ll a, ll b) {
    ll res{1};
    while (b > 0) {
        if (b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

void solve() {
	int n;
	cin >> n;

	ll ans{};
	ans += 4 * 2 * power(3, 1) * power(4, n - 3);
	ans += 4 * (n - 3) * power(3, 2) * power(4, n - 4);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}
