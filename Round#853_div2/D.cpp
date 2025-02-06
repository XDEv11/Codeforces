//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i{0}; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = (c == '1');
	}
	for (int i{0}; i < n; ++i) {
		char c;
		cin >> c;
		b[i] = (c == '1');
	}

	bool a1{count(a.begin(), a.end(), 1)}, b1{count(b.begin(), b.end(), 1)};
	if (!a1 && !b1) return cout << "0\n", []{}();
	else if (!a1 || !b1) return cout << "-1\n", []{}();

	vector<int> ans{};
	auto change{[&a, &ans](int k) {
		ans.push_back(k);
		if (k > 0) {
			for (int i{0}; i + k < a.size(); ++i) a[i] ^= a[i + k];
		} else {
			for (int i{a.size() - 1}; i + k >= 0; --i) a[i] ^= a[i + k];
		}
	}};

	int al{0}, ar{n - 1}; while (a[al] != 1) ++al; while (a[ar] != 1) --ar;
	int bl{0}, br{n - 1}; while (b[bl] != 1) ++bl; while (b[br] != 1) --br;

	if (ar < bl) change(-(bl - ar)), ar = bl;

	for (int i{bl - 1}; i >= 0; --i) {
		if (a[i] == 0) continue;
		change(ar - i);
	}
	al = 0; while (a[al] != 1) ++al;

	if (al > bl) change(al - bl);
	for (int i{bl + 1}; i < n; ++i) {
		if (a[i] == b[i]) continue;
		change(-(i - bl));
	}

	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
