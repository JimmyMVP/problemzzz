#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <time.h>

const int n = 1000;

int longest_increasing(int*);

int main(int argc, char** argv) {

	int array[n];
	srand(time(0));
	for(int i = 0; i < n; i++) {

		array[i] = rand()%40;
		std::cout << array[i] <<  "|";

	}

	std::cout << std::endl << longest_increasing(array) << std::endl;

	return 0;
}


int longest_increasing(int* array) {

	u_int left=0, right=0, longest = 0, lengthRunning = 1, start, end; 
	for(int i = 1; i < n; i++) {

		if(lengthRunning > longest) {

			longest = lengthRunning;
			start = left;
			end = right;

		}
		if(array[i] > array[i-1]) {

			right+=1;
			lengthRunning++;

		} else {

			left = right = i;
			lengthRunning = 1;

		}

	}

	std::cout << start << " " << end << std::endl;

	return longest;

}

