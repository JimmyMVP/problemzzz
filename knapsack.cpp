#include <iostream>
#include <time.h>
#include <algorithm>
#include <sstream>
#include <unordered_map>

int knapsack(u_int S, int*, int*);
int knapsack_nor(u_int S, int*, int*);


int n;

int main(int argc, char** argv) {

	int S = 10;
	n =  20; 

	srand(time(0));

	int weights[n];
	int sizes[n];

	for(int i = 0; i < n; i ++) {

		weights[i] = rand() % 20 + 1;
		sizes[i] = rand() % S;

	}

	for(int i = 0; i < n; i++) {

		std::cout << "|" << sizes[i];

	}
	std::cout << std::endl;

	for(int i = 0; i < n; i++) {

		std::cout << "|" << weights[i];

	}
	std::cout << std::endl;
	std::cout << knapsack_nor(S, weights, sizes) << std::endl;

}

//Knapsack, with repeat
int knapsack(u_int S, int* weights, int* values) {

	int table[S+1][n];

	for(int i = 0; i < n; i ++) {
		table[0][i] = 0;
	}

	for(int i = 1; i < S+1; i++)
		for(int j = 0; j < n; j++) {

			if(i-weights[j] < 0) {
				table[i][j] = table[i][j-1];
				continue;
			}

			table[i][j] = std::max(table[i][j-1], table[i-weights[j]][j] + values[j]);


		}
	return table[S][n-1];

}

//Knapsack, without repeat
int knapsack_nor(u_int S, int* weights, int* values) {

	int table[S+1][n];

	//Hashmap for remembering values
	std::unordered_map<int, bool> used; 

	for(int i = 0; i < n; i ++) {
		table[0][i] = 0;
	}

	for(int i = 1; i < S+1; i++)
		for(int j = 0; j < n; j++) {

			if(i-weights[j] < 0) {
				table[i][j] = table[i][j-1];
				continue;
			}

			int case2 = table[i-weights[j]][j] + values[j];
			int case1 = table[i][j-1];

			if(used[j]) {
				table[i][j] = case1;
				continue;
			}

			case2 > case1 ? used[j] = true : used[j] = false; 
			table[i][j] = std::max(case1, case2);


		}
	return table[S][n-1];

}