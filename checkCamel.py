def checkCamel(s: List[str]) -> List[bool]:
    count_upper = 0
    for c in s:
        if c.isupper():
            count_upper += 1
    return count_upper <= 1