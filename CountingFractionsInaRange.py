def stern_brocot_tree(a, b, c, d):
    if b + d > 12000:
        return 0
    return 1 + stern_brocot_tree(a, b, a + c, b + d) + stern_brocot_tree(a + c, b + d, c, d)i

ans = stern_brocot_tree(1, 3, 1, 2)
print(ans)
