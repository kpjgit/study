public class Casting {
	public static void main(String[] args) {
		double a = 1.1;
		double b = 1;
		double b2 = (double) 1;

		System.out.println(b);
		
		double d = 1.1;
		int e = (int) d;
		System.out.println(e);
		
		String f = Integer.toString(1);
		System.out.println(f.getClass());
	}
}
