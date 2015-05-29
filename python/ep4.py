#!/bin/python
"""
palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99. Find the largest palindrome made from the product of two 3-digit number
"""

def IsPalindrome(number):
  return str(number) == str(number)[::-1]

lhs = 999
rhs = 999
while not IsPalindrome(lhs * rhs):
  lhs = lhs - 1
  if (lhs == 0):
    lhs = 999
    rhs = rhs - 1

print str(lhs), " * ", str(rhs), " = ", str(lhs * rhs)
m=lhs * rhs

lhs = lhs + 1
wall = lhs
while True:
  if IsPalindrome(lhs * rhs):
    print str(lhs), " * ", str(rhs), " = ", str(lhs * rhs)
    if m < (lhs * rhs):
      m = lhs * rhs
    
  rhs = rhs - 1
  if rhs == wall:
    rhs = 999
    lhs = lhs + 1

  if lhs > 999:
     print "end"
     break

print "max: ", m
