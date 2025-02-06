//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;
	const ll B{1000000000000};

	string s{};
	cin >> s;
	int n{s.length()};
	vector<char> v(n + 1); v[0] = '0';
	for (int i{1}; i <= n; ++i) v[i] = s[i - 1];

	vector<int> ps(n + 1);
	for (int i{1}; i <= n; ++i) ps[i] = ps[i - 1] + (v[i] == '1');

	ll ans{n * (B + 1)};
	for (int i{0}; i <= n; ++i) {
		int l1{ps[i]}, r0{(n - i) - (ps[n] - ps[i])};
		ans = min(ans, (l1 + r0) * (B + 1));
		if (i != 0 && i != n) {
			l1 -= (v[i] == '1'), r0 -= (v[i + 1] == '0');
			l1 += (v[i + 1] == '1'), r0 += (v[i] == '0');
			ans = min(ans, B + (l1 + r0) * (B + 1));
		}
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
