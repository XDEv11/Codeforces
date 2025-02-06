//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <numeric>

using namespace std;

void solve() {
	using ll = long long;

	ll a, b, c, d;
	cin >> a >> b >> c >> d;

	ll x{a * d}, y{b * c};
	if (x == y) cout << "0\n";
	else if (x && y && x % y && y % x) cout << "2\n";
	else cout << "1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
