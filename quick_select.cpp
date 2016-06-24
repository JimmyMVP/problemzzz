
#include <cstdlib>
#include <iostream>
#include <ctime>

int arr[100000];


void s(int &a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


int partition(int &left, int &right) {

	int pivot = left + rand()%(right-left);
	int i = left, j = left;
	s(arr[right], arr[pivot]);

	for (;i < right; ++i)
	{
		if(arr[i] <= arr[right]) {
			s(arr[i], arr[j]);
			j++;
		}
	}
	
	s(arr[right], arr[j]);
	return j;

}

//Returns  the n'th smallest element in O(n logn) time;
int quick_select(int left, int right, int n) 
{	
	if(right == left) return arr[left];

	int p = partition(left, right);

	if(p+1 < n) {
		return quick_select(p+1, right, n);
	} else if(p+1 > n){
		return quick_select(left, p-1, n);
	} else {
		return arr[p];
	}

}


void quick_sort(int left, int right) {

	if(right <= left)return;
	else if(right == left+1) {
		if(arr[right] < arr[left]) 
			s(arr[right], arr[left]);
		return;
	}

	int p = partition(left, right);


	quick_sort(left, p-1);
	quick_sort(p+1, right);

}


int main(int argc, char const *argv[])
{
	
	size_t size = sizeof(arr)/sizeof(arr[0]);
	srand(30);
	int order = 14835;

	for (int i = 0; i < size; ++i)
	{
		arr[i] = rand()%size;
	}	

	clock_t begin = std::clock();
	int res = quick_select(0, size-1, order);
	quick_sort(0, size-1);
	if(arr[order-1] == res) std::cout << "Yes!";
	clock_t end = std::clock();

	std::cout << ((double)end-begin)/CLOCKS_PER_SEC << std::endl;


	//std::cout << quick_select(0, size, 4) << std::endl;



	return 0;
}