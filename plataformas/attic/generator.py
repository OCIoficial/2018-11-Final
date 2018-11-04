import sys
import random


def random_bitmap(n, rho):
  return [
    [
      1 if rho > random.random() else 0
      for _ in range(n)]
    for _ in range(n)]


def random_one(bitmap):
  w, h = len(bitmap[0]), len(bitmap)
  while True:
    x, y = random.randrange(w), random.randrange(h)
    if bitmap[y][x]:
      return x + 1, y + 1


random.seed(str(sys.argv))

n = int(sys.argv[2])
d = int(sys.argv[3])
rho = float(sys.argv[4])

bitmap = random_bitmap(n, rho)

start = random_one(bitmap)
end = random_one(bitmap)

print(n, d)

print(*start)

print(*end)

for bitline in bitmap:
  print(*bitline)
