import random
import sys

random.seed(str(sys.argv))

maxN = int(sys.argv[2])
maxM = int(sys.argv[3])
maxA = int(sys.argv[4])
maxB = int(sys.argv[5])

M = random.randint(1, maxM)
N = random.randint(1, maxN)
a = random.randint(1, maxA)
b = random.randint(1, maxB)

print(M, N)
print(a, b)
