# Bradford Smith
# CS 370 Project Euler xor.py
# 04/04/2016

import sys
import itertools

# msg is a list of ascii characters and k is a 3 character key
def decrypt(msg, k):
    plaintext = ""
    print("Key " + k[0] + k[1] + k[2])
    for v in range(0, len(msg), 3):
        plaintext += chr(v ^ ord(k[0]))
        plaintext += chr(v ^ ord(k[1]))
        plaintext += chr(v ^ ord(k[2]))
    return plaintext



# main
fname = sys.argv[1]
f = open(fname, "r")
line = f.readline()
words = ["answer", "words", "thing", "solution"]

done = False
for k in itertools.combinations_with_replacement("abcdefghijklmnopqrstuvwxyz", 3):
    print(k)
    dec = decrypt(line.split(","), k)
    for w in words:
        print(w)
        if w in dec.lower():
            print(dec)
            ans = input("y/n? ")
            if ans == "y":
                done = True
            break
    if done:
        break
