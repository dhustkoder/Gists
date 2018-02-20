import os

number = 35

def guess(num):
    if num > number:
        return 1
    elif num < number:
        return -1
    else:
        return 0

class Solution(object):
    def guessNumber(self, n):
    	min = 1
    	max = n
    	while True:
    		i = (max - min) / 2 + min
    		r = guess(i)
    		if r == -1:
    			min = i + 1
    		elif r == 1:
    			max = i - 1
    		else:
    			return i

s = Solution()
print(s.guessNumber(100))

