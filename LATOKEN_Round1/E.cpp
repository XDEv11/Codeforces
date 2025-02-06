#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	if ((n & 1) && !(k & 1)) return cout << "-1\n"s, []{}();

	bool inv{false};
	if (!(n & 1) && (k & 1) && k * 2 > n) {
		inv = true;
		k = n - k;
	}

	int q{(n + k - 1) / k};
	if (q == 2 && q * k > n) ++q;
	if ((q * k - n) & 1) ++q;

	int ans{0}, x{(q * k - n) / 2}, j{0};
	for (int i{0}; i < q; ++i) {
		vector<bool> v(n, false);
		if (i < q - 2) {
			int t{j};
			while (t < j + k) v[t] = true, ++t;
			j = t;
		} else {
			int t{j};
			while (t < j + (k - x)) v[t] = true, ++t;
			j = t;

			t = 0;
			while (t < x) v[t] = true, ++t;
		}

		cout << "? "s;
		for (int t{0}; t < n; ++t)
			if (v[t] ^ inv) cout << t + 1 << ' ';
		cout << endl;

		int r;
		cin >> r;
		ans ^= r;
	}

	cout << "! "s << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}
