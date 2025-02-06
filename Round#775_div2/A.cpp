//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int f{0}, l{n - 1};
	while (f < n && v[f]) ++f;
	while (l >= 0 && v[l]) --l;

	cout << (f <= l ? l + 1 - (f - 1) : 0) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
