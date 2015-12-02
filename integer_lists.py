import random
from collections import deque
import cProfile

test = [random.randint(1,10000) for i in range(0,100000)]


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


#Find highest product of three numbers in array
#Implement for negative numbers also?
def highest_product_of_three(l):

	fifo = deque()
	
	fifo.append(0)
	fifo.append(0)
	fifo.append(0)

	for i in l:
		if fifo[-1] < i:
			fifo.appendleft(i)

	max_product = 1
	for i in fifo:

		max_product *= i

	return max_product

cProfile.run("highest_product_of_three(test)")