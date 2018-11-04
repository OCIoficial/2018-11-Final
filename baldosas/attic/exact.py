import random
import sys

random.seed(str(sys.argv))

maxN = int(sys.argv[2])
maxM = int(sys.argv[3])

M = random.randint(1, maxM)
N = random.randint(1, maxN)
a = M // random.randint(1, M)
b = N // random.randint(1, N)

print(M, N)
print(a, b)
