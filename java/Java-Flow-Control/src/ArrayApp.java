
public class ArrayApp {

	public static void main(String[] args) {
		String[] users = new String[3];
		
		users[0] = "abc0";
		users[1] = "def00";
		users[2] = "ghi000";

		System.out.println(users[1]);
		System.out.println(users[1].length());
		
		int[] scores = {1, 100, 1000};
		System.out.println(scores[1]);
		System.out.println(scores.length);
	}

}
