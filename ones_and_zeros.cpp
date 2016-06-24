
#include <iostream>

int arr[] = {1,1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0 , 1, 1};
int k = 2;


int solution1() {


	int nextBegin = -1;
	int sum = 0; 
	int flipCount = k;
	int maxSum = 0;

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		std::cout << sum << std::endl;
		if(arr[i] == 1) {
			sum++;
			if(nextBegin == -1 && flipCount < k) {
				nextBegin = i;
			}
		} else if(flipCount > 0) {
			flipCount--;
			sum++;
		} else {
			//End streak
			flipCount = k;
			i = nextBegin;
			if(sum > maxSum) maxSum = sum;
			sum = 1;
			nextBegin = -1;

		}

	}

	if(sum > maxSum) maxSum = sum;

	return maxSum;
}



//O(n)
int solution2() {

	int nextBegin = -1;
	int sum = 0; 
	int flipCount = k;
	int maxSum = 0;

	int firstPartSum;
	int firstPartZeros = 0;

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
	{
		if(arr[i] == 1) {
			sum++;
		} else if(flipCount > 0) {
			if(flipCount == k) firstPartSum = sum;
			if(sum == firstPartSum) {
				firstPartSum++; 
				firstPartZeros++;
			}
			sum++;
			flipCount--;
		} else {
			//End streak
			std::cout << firstPartSum << " " << firstPartZeros << std::endl;
			k = firstPartZeros;
			firstPartZeros = 0;
			if(sum > maxSum) maxSum = sum;
			sum = sum - firstPartSum +1;
		}

	}

	if(sum > maxSum) maxSum = sum;
	return maxSum;
}


int main(int argc, char const *argv[])
{

	int res = solution2();
	std::cout << "Result: " << res << std::endl;

	
}

