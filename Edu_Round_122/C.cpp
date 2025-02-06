//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <string>

using namespace std;

void solve() {
	static auto time = [](long long h, long long d) {
		return (h + d - 1) / d;
	};

	long long hc, dc, hm, dm, k, w, a;
	cin >> hc >> dc >> hm >> dm >> k >> w >> a;

	for (int i{0}; i <= k; ++i) {
		if (time(hm, dc + i * w) <= time(hc + (k - i) * a, dm)) return cout << "YES\n"s, []{}();
	}
	cout << "NO\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
