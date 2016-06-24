#include <iostream>


int profit(int*, int);

int maxprofits[1000];


int main(int argc, char ** argv) {


	int prices[] = {0,1,2,8,4,5,6,7,8, 11, 32, 4, 23, 99, 10, 22};
	int length = 4;

	for(int i = 1; i < 5; i++) {

	//	prices[i] = atoi(argv[i]);
	//	std::cout << prices[i] << "\n" ;

	} 

	//int length = atoi(argv[argc-1]);


	std::cout << "The max profit is: " << profit(prices, length) << std::endl;
}


int profit(int* prices, int length) {

	if(length <= 0) return 0;
	if(length == 1) return prices[1];
	int max = prices[length];
	for(int i = 1; i < length; i++) {
		if(maxprofits[length-i] == 0) maxprofits[length-i] = profit(prices, length-i);
		max = std::max(max, maxprofits[length-i]);
	}

	return max;
		

}