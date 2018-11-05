import sys
import random
import argparse

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


def spiral(n, gap, direction):
  for i in range(0, n)


random.seed(str(sys.argv))

mode = sys.argv[2]

if mode is "random_density":
  n = int(sys.argv[3])
  d = int(sys.argv[4])
  rho = float(sys.argv[5])

  bitmap = random_bitmap(n, rho)

  start = random_one(bitmap)
  end = random_one(bitmap)

elif mode is "spiral":
  n = int(sys.argv[3])
  d = int(sys.argv[4])
  g = int(sys.argv[5])
  direction = sys.argv[6]

  bitmap = spiral(n, gap, direction)

  start = 1, 1
  end = random_one(bitmap)

print(n, d)

print(*start)

print(*end)

for bitline in bitmap:
  print(*bitline)
