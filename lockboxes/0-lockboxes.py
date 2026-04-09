#!/usr/bin/python3
"""Vérifie si toutes les boîtes peuvent être ouvertes."""


def Unlock(boxes):
    """Retourne True si on peut ouvrir toutes les boîtes à partir de la boîte 0.

    Args:
        boxes (list[list[int]]): Liste des clés présentes dans chaque boîte.

    Returns:
        bool: True si toutes les boîtes sont accessibles, sinon False.
    """
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
