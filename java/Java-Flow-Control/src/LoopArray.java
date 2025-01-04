
public class LoopArray {
	public static void main(String[] args) {
		String[] users = new String[3];
		
        /*
         *  <li>abc0</li>
         *  <li>def00</li>
         *  <li>ghi000</li>
         */
		
		users[0] = "abc0";
		users[1] = "def00";
		users[2] = "ghi000";
		
		for(int i = 0; i < users.length; i++) {
			System.out.println("<li>" + users[i] + "/li");
		}
	}
}
