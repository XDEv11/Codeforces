#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int s{accumulate(v.begin(), v.end(), 0)};

	if (s >= n) cout << s - n << '\n';
	else cout << "1\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
