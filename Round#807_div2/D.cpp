//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> s(n), t(n);
	for (auto& x : s) {
		char c;
		cin >> c;
		x = (c == '1');
	}
	for (auto& x : t) {
		char c;
		cin >> c;
		x = (c == '1');
	}

	if (s.front() != t.front() || s.back() != t.back()) return cout << "-1\n", []{}();

	int ans{0};
	for (int i{1}; i < n - 2; ++i) {
		if (s[i] != t[i]) {
			s[i] = t[i];
			++ans;
			if (s[i - 1] == s[i + 1]) {
				s[i + 1] = !s[i + 1];
				++ans;
			}
		}
	}
	if (s[n - 2] != t[n - 2]) {
		if (s[n - 1] == s[n - 3]) return cout << "-1\n", []{}();
		s[n - 2] = t[n - 2];
		++ans;
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
