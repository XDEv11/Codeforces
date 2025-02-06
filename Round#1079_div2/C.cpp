//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		using ll = long long;

		ll p, q;
		cin >> p >> q;

		cout << (p >= q || p * 3 < q * 2 ? "Alice\n" : "Bob\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
