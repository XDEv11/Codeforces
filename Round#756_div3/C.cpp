#pragma GCC optimize ("O3")

#include <iostream>
#include <deque>

using namespace std;

void solve() {
	int n;
	cin >> n;
	deque<int> org(n);
	for (auto& x : org) cin >> x;

	int i{0}, j{n - 1};
	deque<int> dq{};
	if (org[i] > org[j]) dq.push_front(org[i++]);
	else dq.push_front(org[j--]);
	while (i < j) {
		if (org[i] > org[j]) dq.push_front(org[i++]);
		else dq.push_back(org[j--]);
	}
	if (i == j) dq.push_front(org[i]);

	auto ans{dq};

	deque<int> rst{};
	while (dq.size() > 1) {
		if (dq.front() < dq.back()) rst.push_front(dq.front()), dq.pop_front();
		else rst.push_back(dq.back()), dq.pop_back();
	}
	if (dq[0] == org.front()) org.pop_front();
	else if (dq[0] == org.back()) org.pop_back();
	else return cout << "-1\n"s, []{}();

	if (rst == org) {
		for (auto& x : ans) cout << x << ' ';
		cout << '\n';
	} else cout << "-1\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}
