import random

def input():
	n = random.randint(3,100)
	return n

def sol(n):
	ans = 180*(n-2)
	return ans

for i in range(20):
	fi = open(f"GBC/A/in/test{str(i).zfill(2)}.txt","w")
	fo = open(f"GBC/A/out/test{str(i).zfill(2)}.txt","w")
	
	n = input()
	ans = sol(n)
	fi.write(str(n))
	fi.write("\n")

	fo.write(str(ans))
	fo.write("\n")