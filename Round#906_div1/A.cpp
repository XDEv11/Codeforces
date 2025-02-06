//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	deque<char> dq(n);
	for (auto& x : dq) cin >> x;

	if (2 * count(dq.begin(), dq.end(), '0') != n) return cout << "-1\n", []{}();

	vector<int> ans{};
	int i{0}, j{n};
	while (!dq.empty()) {
		if (dq.front() == dq.back()) {
			if (dq.front() == '0') dq.push_back('0'), dq.push_back('1'), ans.push_back(j);
			else dq.push_front('1'), dq.push_front('0'), ans.push_back(i);
			j += 2;
		}
		dq.pop_front(), dq.pop_back(), ++i, --j;
	}

	cout << ans.size() << '\n';
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}
