import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;



public class Heap {

	private int [] array;
	private int lastIndex;
	private boolean maxH = true;

	public Heap(int [] array) {

		this.array = array;
		buildHeap();
	}

	private int parent(int i) {

		return i >> 1; 

	}

	private int left(int i) {

		return i << 1;

	}

	private int right(int i) {

		return (i << 1)+1;

	}

	public Heap(int [] array, boolean max) {

		this.array = array;
		this.maxH = max;
		buildHeap();

	}

	public void buildHeap() {

		for(int i = array.length/2; i >= 0; i--) {

			heapify(i);

		}

	}

	public void heapify(int i) {

		int left = left(i);
		int right = right(i);
		int max = array[i];

		if(maxH) {

			if(left < array.length && array[max] < array[left]) {
				max = left;
			}
			if(right < array.length && array[max] < array[right]) {
				max = right;
			}

			if(array[max] != array[i]) {

				int tmp = array[i];
				array[i] = array[max];
				array[max] = tmp;
				heapify(max);

			}

		} else {

			if(left < array.length && array[max] < array[left]) {
				max = left;
			}
			if(right < array.length && array[max] < array[right]) {
				max = right;
			}

			if(array[max] != array[i]) {

				int tmp = array[i];
				array[i] = array[max];
				array[max] = tmp;
				heapify(max);

			}

		}


	}




	//READ DATA METHOD
	public static int [] readData() {
	

		File f = new File("/Users/Jimmy/Projects/Topcoder/dataset.txt");

		int [] array = new int[100000];
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
			String line = reader.readLine();
			StringTokenizer tokenizer = new StringTokenizer(line, " ");
			int i = 0;
			while(i < 100000) {
				
				String num = tokenizer.nextToken();
				array[i] = Integer.valueOf(num);
				i++;
				
			}
			return array;
			
			
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return null;
		
	}



	//MAIN TEST METHOD
	public static void main(String [] argv) {

		int [] data = readData();
		Heap heap = new Heap(data);



	}

}