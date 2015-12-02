#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>

const int n = 10000;

int max_cont_seq_rec(int*, u_int);
int max_cont_seq_rec(int*);

int max_cont_seq_dyn(int*);

int main(int argc, char** argv) {

	int array[n];
	srand(time(0));
	for(int i = 0; i < n; i++) {

		array[i] = rand()%n - n/2;
		std::cout << array[i] <<  "|";

	}

	std::cout << std::endl << max_cont_seq_rec(array);

	return 0;
}


int max_cont_seq_dyn(int* array) {


	int m = array[0], m_i = 0;
	//Find minimum
	for(int i = 0; i < n; i++){

		if(array[i] < m) {
			m = array[i];
			m_i = i;
		}
	}

	//Dynamicly calculate
	int runningSum = array[0], left = 0, right = 0, maxSum = m,
	start = 0, finish = -1;
	for(int i = 1; i < n; i++) {


		if(runningSum < m) {
			runningSum = array[i];
			left = i;
			right = i;
		} else {
			runningSum += array[i];
			right = i;
		}
		if(runningSum >= maxSum) {
			maxSum = runningSum;
			start = left;
			finish = right;
		}

	}

	std::cout << start << " " << finish << std::endl;
	return maxSum;

}

int max_cont_seq_rec(int* array) {

	int maxSum = -n;
	for(int i = 0; i < n; i++) {
		int res = max_cont_seq_rec(array, i);
		if(res > maxSum) {
			maxSum = res;
		}

	}
	return maxSum;
}
 
int max_cont_seq_rec(int* array, u_int element) {
	if(element == n) {

		return 0;
	}

	int case1 = max_cont_seq_rec(array, element + 1) + array[element];
	int case2 = array[element];

	return std::max(case1,case2);


}