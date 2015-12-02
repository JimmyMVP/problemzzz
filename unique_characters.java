
import java.util.HashMap;


class Main{
	
public static void main(String [] argv) {
	

	System.out.println(argv[0]);
	System.out.println(unique(argv[0]));


}

public static boolean unique(String str) {
		
		HashMap hashMap = new HashMap<Character, Character>();

		for(int i = 0; i < str.length(); i++) {

			Character c = str.charAt(i);
			if(hashMap.containsKey(c)) return false;
			else hashMap.put(c,c);
		}
		return true;

	}

}