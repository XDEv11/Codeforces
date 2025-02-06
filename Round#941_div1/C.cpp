//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

static void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int l{1}, r{0};
	for (int i{1}; i < v.size(); ++i) {
		if (v[i] == v[i - 1]) swap(l, r);
		if (r) --r;
		++l;
	}

	cout << (l + r) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
