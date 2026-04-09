#!/usr/bin/python3
def Unlock(boxes):
    i = len(boxes)
    open = set([0])
    stack = [0]

    while stack:
        current = stack.pop()

        for key in boxes[current]:
            if 0 <= key < i and key not in open:
                open.add(key)
                stack.append(key)

    return len(open) == i
