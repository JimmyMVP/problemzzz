import random
from collections import deque
import cProfile

test = [random.randint(1,1000) for i in range(0,100000)]


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
def highest_product_of_three(l):

	fifo = deque()
	
	fifo.append(1)
	fifo.append(1)
	fifo.append(1)

	fifo2 = deque()
	fifo2.append(-1)
	fifo2.append(-1)



	for i in l:
		if fifo[-1] < i:
			fifo.pop()
			fifo.appendleft(i)
		if fifo2[-1] > i:
			fifo2.pop()
			fifo2.appendleft(i)



	max_product = 1
	max_product_neg = 1
	for i in fifo:
		max_product *= i

	for i in fifo2:
		max_product *= i

	max_product_neg *= fifo[0]

	return max(max_product, max_product_neg)


cProfile.run("highest_product_of_three(test)")