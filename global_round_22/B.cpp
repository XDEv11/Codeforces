//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> ps(k);
	for (auto& x : ps) cin >> x;

	vector<int> v(k);
	v[0] = ps[0];
	for (int i{1}; i < k; ++i) v[i] = ps[i] - ps[i - 1];

	if (!(is_sorted(v.begin() + 1, v.end()))) return cout << "NO\n", []{}();
	auto aux{[](int a, int b) {
		if (a >= 0) return (a + b - 1) / b;
		else return a / b;
	}};
	if (!(k == 1 || aux(v[0], n - k + 1) <= v[1])) return cout << "NO\n", []{}();
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
