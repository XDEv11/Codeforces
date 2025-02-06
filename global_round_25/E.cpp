//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	int n{s.size()};

	auto check{[&s](int l, int r) {
		for (int i{l}, j{r}; i < j; ++i, --j) {
			if (s[i] != s[j]) return false;
		}
		return true;
	}};
	if (!check(0, n - 1)) return cout << "YES\n1\n" << s << '\n', []{}();

	int k{1};
	while (k < n && s[k] == s[0]) ++k;
	if (k == n || (n % 2 && k == n / 2)) return cout << "NO\n", []{}();

	if (check(k + 1, n - 1)) ++k;
	if (check(0, k)) return cout << "NO\n", []{}(); // only "ababa"

	cout << "YES\n2\n";
	++k, cout << s.substr(0, k) << ' ' << s.substr(k, n - k) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
