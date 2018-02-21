
def countTwos(n):
	count = 0
	for m in range(0, n + 1):
		k = m
		while (k > 0):
			if k % 10 == 2:
				count += 1
			k = int(k / 10)			
	return count

print(countTwos(25))