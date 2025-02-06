//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> a(n), b(n);
	for (auto& x : a) cin >> x;
	for (auto& x : b) cin >> x;

	sort(a.begin(), a.end()), sort(b.begin(), b.end());

	int ans{0};
	for (int i{0}, j{0}; i < n; ++i) {
		while (j + 1 < n && b[j + 1] < a[i]) ++j;
		ans = max(ans, min(abs(a[i] - b[j]), j + 1 < n ? b[j + 1] - a[i] : numeric_limits<int>::max()));
	}

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}
