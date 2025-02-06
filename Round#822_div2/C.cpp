//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn{1000000};

const vector<int> fac{[]() {
	vector<int> v(maxn + 1);
	for (int i{1}; i <= maxn; ++i) {
		if (v[i]) continue;
		for (int j{i}; j <= maxn; j += i) v[j] = i;
	}
	return v;
}};

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int ans{0};
	vector<bool> ck(maxn, true);
	for (int i{1}; i <= n; ++i) {
		if (v[i] == '1') {
			int j{i};
			while (j > 1) {
				fac[j] = false;
				j /= fac[j];
			}
			continue;
		}
		int j{i}, c{j};
		while (j > 1) {
			if (ck[fac[j]]) c = fac[j];
			j /= fac[j];
		}
		if (ck[1]) c = 1;
		ans += c;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
