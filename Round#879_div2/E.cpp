//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	const ll mxv{5000000};
	set<ll> st{};
	vector<int> jmp(n); iota(jmp.begin(), jmp.end(), 1);
	for (int l{n - 1}; l >= 0; --l) {
		if (v[l] > mxv) continue;
		ll x{v[l]}; int lst{l};
		st.insert(x);
		for (int r{jmp[l]}; r < n; r = jmp[r]) {
			ll nx{lcm(x, v[r])};
			if (nx == x) continue;
			if (nx > mxv) break;
			x = nx, jmp[lst] = r, lst = r;
			st.insert(x);
		}
		jmp[lst] = n;
	}

	int mex{1};
	while (st.count(mex)) ++mex;

	cout << mex << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
