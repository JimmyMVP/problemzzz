
class MySort {


	static int [] arr = {1, 34 , 55, 66, 11, 88, 33, 44 ,55, 90, 1, 60};
	static long start = 1 << 6;

	public static void main(String args[]) {

		System.out.println("Sorting...");

		mySort(0, arr.length-1, start);		

		for(int i = 0; i < arr.length; i++) {

			System.out.print(arr[i] + " ");

		} 

	}


	private static  void mySort(int left, int right, long start) {

		System.out.println(start);

		if(left >= right) return;
		if(start == 0) return;

		int i = left, j = right;
		for( ;i != j && i < arr.length; i++) {

			if((arr[i] & start) == 0) {

				while(j > i) {

					if((arr[j]&start) != 0) {
						System.out.println(arr[j] + " " + arr[i] + " " + start);
						arr[i] ^= arr[j];
						arr[j] ^= arr[i];
						arr[i] ^= arr[j];
						break;
					}
					j--;
				}
				if(j == i) break;
			}
		}

		mySort(left, i,  start >> 1);
		mySort(i, right, start >> 1);





	}


}



