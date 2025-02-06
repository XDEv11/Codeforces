#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	long long t;
	cin >> n >> t;
	vector<long long> v{};

	char c;
	for (int i{0}; i < n - 2; ++i)
		cin >> c, v.push_back(1 << (c - 'a'));
	cin >> c, t += (1 << (c - 'a')); // -
	cin >> c, t -= (1 << (c - 'a')); // +

	sort(v.rbegin(), v.rend());
	for (auto& x : v) {
		if (t >= 0) t -= x;
		else t += x;
	}

	cout << (t ? "No" : "Yes") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	// cin >> t;
	while (t--) solve();

	return 0;
}
