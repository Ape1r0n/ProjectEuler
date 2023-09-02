import itertools as it


def is_valid(inner_circle, outer_circle):
    return len(set(inner_circle[i] + inner_circle[(i + 1) % 5] + outer_circle[i] for i in range(5))) == 1

def toString(inner_circle, outer_circle):
    iindex = outer_circle.index(min(outer_circle))
    return "".join((str(outer_circle[i % 5]) + str(inner_circle[i % 5]) + str(inner_circle[(i + 1) % 5]) for i in range(iindex, iindex + 5)))

all_gons = it.permutations(range(1, 11))
valids = filter(lambda v: is_valid(v[:5], v[5:]), all_gons)
strings = filter(lambda sequence: len(sequence) == 16, map(lambda s: toString(s[:5], s[5:]), valids))
ans = max(strings)

print(ans)
