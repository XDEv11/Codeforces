//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	int i{0}, j{0};
	multiset<int> ms{};
	while (j < n) {
		if (i < n && a[i] == b[j]) ++i, ++j;
		else if (j - 1 >= 0 && b[j - 1] == b[j] && ms.count(b[j])) {
			ms.erase(ms.find(b[j]));
			++j;
		} else {
			if (i >= n) return cout << "NO\n", []{}();
			while (a[i] != b[j]) {
				ms.insert(a[i++]);
				if (i >= n) return cout << "NO\n", []{}();
			}
			++i, ++j;
		}
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
