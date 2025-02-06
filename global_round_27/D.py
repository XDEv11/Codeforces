#!/usr/bin/env python

M = 1000000007


def solve():
	n = int(input())
	a = [int(x) for x in input().split()]

	b = [0] * n
	l = [-1] * n
	for i in range(n):
		while a[i] % 2 == 0:
			a[i] //= 2
			b[i] += 1
		if i:
			l[i] = i - 1 if b[i - 1] else l[i - 1]
	pa = a.copy()
	for i in range(1, n):
		pa[i] += pa[i - 1]

	dp = [0] * n
	s = 0
	p = 0
	for i in range(n):
		dp[i] = s + a[i] * pow(2, b[i] + p)

		j = i
		q = 0
		while j > 0:
			q += b[j]
			dp[i] = max(dp[i], dp[j - 1] + (pa[i - 1] - pa[j - 1]) + a[i] * pow(2, q))

			j = l[j]

		s += a[i]
		p += b[i]

	for x in dp:
		print(x % M, end=' ')
	print()
	

if __name__ == '__main__':
	t = int(input())
	while t:
		solve()
		t -= 1

