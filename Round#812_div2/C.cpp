//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;

	auto psub{[](int x){
		int l{-1}, r{500};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (m * m < x) l = m;
			else r = m;
		}
		return r * r;
	}};

	vector<int> p(n); iota(p.begin(), p.end(), 0);
	int i{n - 1};
	while (i >= 0) {
		int d{psub(i) - i};
		reverse(p.begin() + d, p.begin() + i + 1);
		i = d - 1;
	}

	for (auto& x : p) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
