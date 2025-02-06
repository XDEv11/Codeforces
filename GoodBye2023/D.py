n = int(input());
arr = [];
for i in range(n):
	arr.append(int(input()));

for x in arr:
	if x == 1:
		print(1);
	else:
		for i in range(x // 2):
			a, b = 1, 3;
			for j in range(x // 2):
				a *= 10
			for j in range(i):
				b *= 10
			print((a + b) ** 2)

		for i in range(x // 2):
			a, b = 3, 1;
			for j in range(x // 2):
				a *= 10
			for j in range(i):
				b *= 10
			print((a + b) ** 2)

		a = 14;
		for j in range(x // 2 - 1):
			a *= 10;
		print(a ** 2)
				
