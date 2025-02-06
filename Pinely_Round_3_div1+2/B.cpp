//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	ll a{2};
	while (true) {
		set<ll> st{};
		for (auto& x : v) st.insert(x % a);
		if (st.size() == 2) return cout << a << '\n', []{}();
		a *= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
