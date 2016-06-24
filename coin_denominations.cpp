
#include <iostream>


int coins[] = {50,10, 2, 1};
int size = sizeof(coins)/sizeof(coins[0]);
const int MAX = ((unsigned int)(~0)) >> 1; 
int* denoms;


int num_coins(int num) {


	if(num == 0) return 0;

	if(denoms[num] != 0) return denoms[num];

	int min = MAX;
	if(denoms[num] == 0)
	for(int i = 0; i < size; i++) {

		//Number is equal to a coin, return 1
		if(num == coins[i]) return 1;
		//Else if the coin is lesser dig deeper
		else if( num > coins[i]){
			min = std::min(min, 1 + num_coins(num - coins[i]));
			
		}

	}
	denoms[num] = min;
	
	return min;

}


int main(int argc, char ** argv) {

	int coin_num = 0;
	int num = 1800;
	denoms = (int*) malloc(sizeof(int)*num);

	std::cout << num_coins(num) << std::endl;

	delete denoms;

}
