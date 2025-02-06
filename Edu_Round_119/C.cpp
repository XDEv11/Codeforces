//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void solve() {
	long long n, k;
	long long x;
	cin >> n >> k >> x;
	vector<char> v(n);
	for (auto& e : v) cin >> e;

	vector<long long> c(n, 0);
	long long cnt{0};
	for (int i{0}; i < n; ++i) {
		if (v[i] == '*') ++cnt;
		if (i + 1 == n || v[i + 1] == 'a') c[i] = cnt, cnt = 0;
	}

	string ans{};

	x -= 1;
	for (int i{n - 1}; i >= 0; --i) {
		if (v[i] == 'a') ans += 'a';
		else if (c[i]) {
			long long w{c[i] * k + 1};
			long long nb{x % w};
			while (nb--) ans += 'b';
			x /= w;
		}
	}

	reverse(ans.begin(), ans.end()), ans += '\n', cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
