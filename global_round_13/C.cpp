#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> s(n), c(n, 0);
	for (auto& x : s) cin >> x;

	long long ans{0}, ps{0};

	for (int i{0}; i < n; ++i) {
		ps += c[i];
		if (ps < s[i] - 1) ans += (s[i] - 1) - ps; // add extra

		if (i + 2 < n) c[i + 2] += 1; // add 1 to [ i+2 : i+s[i]+1 )
		if (i + s[i] + 1 < n) c[i + s[i] + 1] -= 1;

		if (ps > s[i] - 1) {
			if (i + 1 < n) c[i + 1] += ps - (s[i] - 1); // transfer to c[i + 1]
			if (i + 2 < n) c[i + 2] -= ps - (s[i] - 1);
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

	return 0;
}
