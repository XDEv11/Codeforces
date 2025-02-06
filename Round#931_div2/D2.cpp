//#pragma GCC optimize ("O3")

#include <iostream>
#include <utility>
#include <cstdlib>

using namespace std;

void solve() {
	using ll = long long;

	auto Alice{[](ll _p1, ll _p2) {
		cout << _p1 << ' ' << _p2 << endl;
	}};
	auto Bob{[] {
		ll _p1, _p2;
		cin >> _p1 >> _p2;
		if (_p1 == -1) exit(0);
		return pair<ll, ll>{_p1, _p2};
	}};

	ll n;
	cin >> n;

	if (__builtin_popcountll(n) & 1) {
		cout << "second" << endl;
		auto [p1, p2]{Bob()};
		n = (__builtin_popcountll(p1) & 1 ? p2 : p1);
	} else cout << "first" << endl;

	while (n) {
		int i{62};
		while (!(n & (1ll << i))) --i;
		Alice(1ll << i, n ^ (1ll << i));

		auto [p1, p2]{Bob()};
		n = (__builtin_popcountll(p1) & 1 ? p2 : p1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
