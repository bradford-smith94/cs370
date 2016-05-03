# Mike Curry, Kareem Mohamed and Bradford Smith
# CS 370 Group Project 2 SPOJ LCMSUM sympy_sol.py
# 05/02/2016
# "We pledge our honor that we have abided by the Stevens Honor System."

from __future__ import division
from sympy import Sum, symbols, floor, Function, simplify, nsimplify, init_printing, ilcm, totient
init_printing()
x, y, z, t = symbols('x y z t')
k, m, n = symbols('k m n', positive=True)
f, g, h = symbols('f g h', cls=Function)

def gcd(m, n):
    return m + n - m*n + 2*Sum(floor(k*n/m), (k, 1, m-1))

def magic_gcd(m, n):
    ans = 0
    for k in xrange(1, n+1):
        if m % k == 0 and n % k == 0:
            print k
            ans += totient(k)
    return ans

def lcm(m, n):
    return m*n/gcd(m, n)

def magic_lcm(m, n):
    return m*n//magic_gcd(m, n)

def lcm_sum(n):
    return Sum(lcm(m, n), (m, 1, n))

def magic_lcm_sum(n):
    return Sum(magic_lcm(m, n), (m, 1, n))

symbolic_lcm_sum = Sum(lcm(m, n), (m, 1, n))
