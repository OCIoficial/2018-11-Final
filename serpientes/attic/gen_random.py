import sys
import random

random.seed(str(sys.argv))

"""
    Input format (for the test gen):
        N -- rows
        M -- columns
        E -- serpientes/escaleras
        T -- turns
        S -- Special tests:
            S = 0 -- Random test
            S = 1 -- Sin tomar escaleras/serpientes
            S = 2 -- Solo escaleras/serpientes

        NOTES:
            Assuming E[t_i] = 3.5, T should be something close to N*M/3.5 when S = 1
"""

N = int(sys.argv[2])
M = int(sys.argv[3])
E = int(sys.argv[4])
T = int(sys.argv[5])
S = int(sys.argv[6])

danger_noodles = {}  # Type: Dict[Tuple[int, int], Tuple[int, int]]
real_sneks = {}
turns = []
current = (0, 0)

def get_position(dice):
    # Type: (int) -> List[int]
    # 0: row, 1: col
    global current
    global turns
    global current
    if current == (-1, -1):
        return
    while dice > 0:
        if current[0] % 2 == 0:
            if current[1] + dice < M:
                current = (current[0], current[1] + dice)
                dice = 0
            else:
                if current[0] == N - 1:
                    # We reached the end
                    current = (-1, -1)
                    return
                dice -= (M - current[1])
                current = (current[0] + 1, M - 1)
        else:
            if current[1] - dice >= 0:
                current = (current[0], current[1] - dice)
                dice = 0
            else:
                if current[0] == N - 1:
                    # We reached the end
                    current = (-1, -1)
                    return
                dice -= (current[1] + 1)
                current = (current[0] + 1, 0)
    if current in danger_noodles:
        current = danger_noodles[current]
    if current == (N - 1, M - 1):
        current = (-1, -1)


def get_new_snek(Nlimit=2, Mlimit=0):
    global current
    global turns
    global current
    assert N > 2, 'N tiene que ser mayor que 2 para tener serpientes'
    c = 0
    new_snek = (-1, -1)
    while True:
        # By default we don't create sneks in the last row, this is to avoid reaching the end
        # of the board
        new_snek = (random.randint(0, N - Nlimit), random.randint(0, M - Mlimit))
        if new_snek not in danger_noodles:
            break
        c += 1
        if c == 20:
            # We've tried creating sneks 20 times and they're always used, we
            # should stop and give up. Maybe there are no more spaces available for sneks
            new_snek = (-1, -1)
            break
    return new_snek

def gen_sneks():
    global current
    global turns
    global current
    global real_sneks
    turns = [random.randint(1, 6) for _ in range(T)]
    for turn in turns:
        get_position(turn)
        if current == (-1, -1):
            continue
        if current not in danger_noodles and len(real_sneks) < E:
            # Make a new snek
            new_snek = get_new_snek()
            if new_snek[0] != -1:
                danger_noodles[current] = new_snek
                real_sneks[current] = new_snek
                danger_noodles[new_snek] = new_snek
                current = new_snek
            current = new_snek
        if current == (N - 1, M - 1):
            current = (-1, -1)

def gen_boring():
    global current
    global turns
    global current
    turns = [random.randint(1, 6) for _ in range(T)]
    for turn in turns:
        get_position(turn)
        if current == (-1, -1):
            continue
        danger_noodles[current] = current


def gen_random():
    global current
    global turns
    global current
    global real_sneks
    turns = [random.randint(1, 6) for _ in range(T)]
    for turn in turns:
        get_position(turn)
        if current == (-1, -1):
            continue
        if current not in danger_noodles and len(real_sneks) < E:
            if bool(random.getrandbits(1)):
                # Make a snek here
                new_snek = get_new_snek()
                if new_snek != (-1, -1):
                    danger_noodles[current] = new_snek
                    real_sneks[current] = new_snek
                    danger_noodles[new_snek] = new_snek
                    current = new_snek
            else:
                # We're not taking a snek this turn
                danger_noodles[current] = current


def add_noise():
    global real_sneks
    for _ in range(E - len(real_sneks)):
        for i in range(20):
            start = get_new_snek()
            end = get_new_snek()
            if i == 19:
                # Not gonna happen :(
                return
            if start == (-1, -1) or end == (-1, -1):
                continue
            else:
                break
        real_sneks[start] = end
        danger_noodles[start] = end
        danger_noodles[end] = start


if S == 1:
    gen_boring()
elif S == 2:
    gen_sneks()
else:
    gen_random()
add_noise()

print('{} {}'.format(N, M))
print(len(real_sneks))
for key, val in real_sneks.items():
    print('{} {} {} {}'.format(key[0], key[1], val[0], val[1]))
print(len(turns))
print(*turns)
