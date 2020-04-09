def find_idx(l, start, val):
    for i, v in enumerate(l[start:]):
        if v == val:
            return i + start
    return -1


def solution(l):
    n = len(l)
    cur_max = 0

    beg, end = -1, -1
    prev_beg, prev_end = -1, -1

    idx = 0

    while True:
        beg = find_idx(l, idx, 1)
        if beg == -1:
            if end == -1:
                return 1
            return cur_max
        end = find_idx(l, beg, 0)
        if end == -1:
            if prev_beg != -1:
                return max(cur_max, n - prev_beg)
            elif beg > 0:
                return max(cur_max, n - beg + 1)
            else:
                return max(cur_max, n - beg)

        if prev_beg != -1:
            cur_max = max(cur_max, end - prev_beg)

        if beg > 0 or end < n:
            cur_max = max(cur_max, end - beg + 1)
        else:
            cur_max = max(cur_max, end - beg)

        idx = end
        if end + 1 < n and l[end + 1] == 1:
            prev_beg = beg
        else:
            prev_beg = -1
