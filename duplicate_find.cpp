#include <iostream>
#define SIZE(array) (sizeof(array) / sizeof(array[0]))


int array[] = {1,2,3,4,5,6,7,3,1,3,4,5,11,15,2,6,3};


/*
	Find duplicate if the sequence is N long and the numbers are between the range 0 .. N-1
*/





//Change numbers of corresponding indexes to negatives and lookup the duplicates on
//the second iteration
void changeArray () {

	for(int i = 0; i < SIZE(array); i++) {
		if(array[abs(array[i])] > 0)
			array[abs(array[i])] = - array[abs(array[i])];
		else
			std::cout << abs(array[i]) << " ";
		
	} 
	std::cout << std::endl;

	


}


//Two pointer solution
void twoPointer() {

	int *first, *second, it = 0;

	

	for(int i = 0; i < SIZE(array); i++) {
	first = &array[i];
	second = &array[i];
		do {

			second = &array[*second];
			if(first == second) break;
			second = &array[*second];
			if(first == second) break;
			first = &array[*first];
			it++;

		} while(first != second && it < SIZE(array));

	it = 0;

	if(second == first && != &array[i])
	std::cout << *first << std::endl;	
	}
	

}



int main(int argc, char** argv) {


	std::cout << "Running..." << std::endl;
	twoPointer();


}



