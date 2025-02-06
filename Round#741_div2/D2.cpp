#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n, q;
	cin >> n >> q;
	vector<char> a(n);
	for (auto& x : a) cin >> x;

	vector<int> ps(n + 1);
	for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + ((i & 1) ^ (a[i - 1] == '+') ? 1 : -1);

	vector<set<int>> v(2 * n + 1);
	for (int i{0}; i <= n; ++i) v[ps[i] + n].insert(i);

	while (q--) {
		int l, r;
		cin >> l >> r;
		
		int s{ps[r] - ps[l - 1]};
		if (s == 0) {
			cout << "0\n";
		} else if (s & 1) {
			cout << "1\n";
			cout << *v[ps[l - 1] + (s / 2 + (s > 0 ? 1 : -1)) + n].lower_bound(l) << '\n';
		} else {
			cout << "2\n";
			cout << *v[ps[l - 1] + (s / 2) + n].lower_bound(l) << ' ';
			cout << *v[ps[l - 1] + (s) + n].lower_bound(l) << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
