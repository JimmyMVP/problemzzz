#include <iostream>



int array1[] = {1,3,5,6,8,9,11,56,77};
int array2[] = {4, 6, 8, 10};

int size1 = sizeof(array1)/sizeof(int);
int size2 = sizeof(array2)/sizeof(int);


int main(int argc, char** argv) {


	int result[size1 + size2];

	int j = 0,k = 0;
	for(int i = 0; i < size1 + size2; i++) {

		if(j >= size1) result[i] = array2[k++];
		else if(k >= size2) result[i] = array1[j++];
		else {
			if(array1[j] <= array2[k]) {
				result[i] = array1[j++];
			} else {
				result[i] = array2[k++];
			}

		}

		std::cout << result[i] << " | ";

	}

	std::cout << std::endl;

}