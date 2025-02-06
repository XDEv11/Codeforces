//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print(int i, int j) {
	cout << i + 1 << ' ' << j + 1 << '\n';
}

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int c1{count(v.begin(), v.end(), '1')};
	if (!c1 || (c1 & 1)) return cout << "NO\n", []{}();

	cout << "YES\n";
	int i{0};
	while (v[i] != '1') ++i;
	int j{i + 1};
	while (v[j] != '1') ++j;

	int jn{(j + 1) % n};
	if (jn == i) {
		for (int k = i; k != j; ++k) print(k, k + 1);
		return ;
	}
	print(j, jn);
	int k;
	for (k = jn; k != i; ) {
		int kn{(k + 1) % n};
		if (kn == i) break;
		print(k, kn);
		if (v[k] == '1') {
			int kk{kn}, kkn;
			while (v[kk] != '1') {
				kkn = (kk + 1) % n;
				print(kk, kkn);
				kk = kkn;
			}
			kkn = (kk + 1) % n;
			if (kkn == i) print(k, j - 1);
			else print(k, kkn);
			k = kkn;
		} else k = kn;
	}
	if (v[(i - 1 + n) % n] != '1') print(j - 1, (i - 1 + n) % n);
	for (k = i; k + 1 != j; ++k) print(k, k + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
