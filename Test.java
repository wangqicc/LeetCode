import java.util.*;

public class Test {
	public static void main(String[] args) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		map.put(2, 0);
		map.put(7, 1);
		map.put(11, 2);
		map.put(17, 3);

		if (map.containsKey(11)) {
			System.out.println("exist!");
		}
	}
}