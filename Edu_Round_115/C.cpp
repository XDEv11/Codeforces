#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <string>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<long long> v(n);
	for (auto& x : v) cin >> x;

	long long s{accumulate(v.begin(), v.end(), 0LL)};

	if (s * 2 % n) return cout << "0\n"s, []{}();
	long long d{s * 2 / n};

	long long ans{0};
	map<long long, int> mp{};
	for (auto& x : v) {
		ans += mp[d - x];
		++mp[x];
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
