//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<char> a(n), b(m);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	int ac{0}, bc{0};
	while (!a.empty() && !b.empty()) {
		if (!(bc < k) || (a.back() < b.back() && ac < k)) {
			cout << a.back();
			a.pop_back();
			++ac, bc = 0;
		} else {
			cout << b.back();
			b.pop_back();
			++bc, ac = 0;
		}
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
