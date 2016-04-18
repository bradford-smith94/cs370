# Bradford Smith (bsmith8)
# CS 370 Challenge HackerRank Paint the Tiles tile.py
# 04/18/2016
# "I pledge my honor that I have abided by the Stevens Honor System."

def countStrokes(tiles):
    strokes = 0
    i = 0
    prev = None
    while i < len(tiles):
        if tiles[i] != prev:
            strokes += 1
        prev = tiles[i]
        i += 1
    return strokes

num = int(input())
tiles = list(input())
print(countStrokes(tiles))
