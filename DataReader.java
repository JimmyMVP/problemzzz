package application;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class DataReader {
	
	
	public int [] readData() {
		

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
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		return null;
		
	}
	
	
}
