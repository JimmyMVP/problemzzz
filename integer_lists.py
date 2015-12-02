import random
from collections import deque
import cProfile

test = [4,1,4,2,5,3,2,1]


#Find product of all numbers in array for index, except the index
def integer_products(l):

	init1 = [1 for i in range(0, len(l))]
	init2 = [1 for i in range(0, len(l))]


	for i in range(1, len(l)):
		init1[i] = l[i-1] * init1[i-1]
		init2[-i-1] = l[-i] * init2[-i]

	for i in range(0, len(l)):
		init1[i] = init1[i] * init2[i]

	return init1


#Find highest product of three numbers in array O(n) time complexity,
#with support for negative numbers
#Do for k items? O(1) space complexity?
#No FIFO, the second biggest element can end up on the end
def highest_product_of_three(l, k):

	l1 = sorted([l[0], l[1], l[2]])
	l2 = []

	for i in range(0, len(l)):
		for j in range(0,k):
			if(l[i] > l1[j]):
				l1[j] = l[i]
				break



	max_product = 1
	max_product_neg = 1
	for i in l1:
		max_product *= i

#	for i in fifo2:
#		max_product *= i

#	max_product_neg *= fifo[0]

	return max_product


print highest_product_of_three(test, 3)

#cProfile.run("highest_product_of_three(test)")