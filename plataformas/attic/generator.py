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


def spiral(n, gap):
  grid = [[0 for _ in range(n)] for _ in range(n)]

  for offset in range(0, len(grid) // 2, gap + 1):
    start = offset
    end = len(grid) - 1 - offset
    for i in range(start, end):
      grid[i][offset] = 1
      grid[end][i] = 1
      grid[end + offset - i][end] = 1
      grid[offset][end + offset - i] = 1

    for i in range(offset + 1, offset + 1 + gap):
      grid[i][offset] = 0

    if end - start < 2 * gap + 3:
      break

    for i in range(offset + 1, offset + 1 + gap):
      grid[offset + 1 + gap][i] = 1

  return grid


random.seed(str(sys.argv))

mode = sys.argv[2]
n = int(sys.argv[3])
d = int(sys.argv[4])

if mode == "random_density":
  rho = float(sys.argv[5])

  bitmap = random_bitmap(n, rho)

  start = random_one(bitmap)
  end = random_one(bitmap)

elif mode == "spiral":
  gap = int(sys.argv[5])

  bitmap = spiral(n, gap)

  start = 1, 1
  end = random_one(bitmap)

print(n, d)

print(*start)

print(*end)

for bitline in bitmap:
  print(*bitline)
