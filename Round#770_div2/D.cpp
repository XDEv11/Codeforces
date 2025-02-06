//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

int query(int i, int j, int k) {
	cout << "? " << i + 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
	int r;
	return cin >> r, r;
}

void answer(int i, int j) {
	cout << "! " << i + 1 << ' ' << j + 1 << endl;
}

void solve() {
	int n;
	cin >> n;

	vector<int> v(n); iota(v.begin(), v.end(), 0);
	while (v.size() >= 4) {
		vector<int> t(v.end() - 4, v.end()); v.resize(v.size() - 4);
		int mx{-1}, x1, x2;
		for (int i{0}; i < 4; ++i) {
			int q{query(t[(i + 1) % 4], t[(i + 2) % 4], t[(i + 3) % 4])};
			if (q > mx) mx = q, x1 = t[i];
			else if (q == mx) x2 = t[i];
		}
		for (auto& x : t)
			if (x != x1 && x != x2) v.push_back(x);

		if (v.size() == 3) {
			for (int i{0}; i < n; ++i) {
				bool f{true};
				for (auto& x : v)
					if (i == x) f = false;
				if (f) {
					v.push_back(i);
					break;
				}
			}
		}
	}

	if (v.size() == 1) answer(v[0], v[0]);
	else answer(v[0], v[1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
