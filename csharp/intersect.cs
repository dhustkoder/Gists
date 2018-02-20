using System.Linq;
using System.Collections.Generic;


public class Solution {
	public int[] Intersection(int[] a, int[] b) {
		System.Array.Sort(b);
		List<int> r = new List<int>();

		for (int i = 0; i < a.Length; ++i) {
			if (b.Count(x => x == a[i]) != 0 && r.Count(x => x == a[i]) == 0)
				r.Add(a[i]);
		}

		return r.ToArray();
	}
};

public class Intersection {
	public static int Main(string[] args) {
		Solution s = new Solution();

		int[] r = s.Intersection(new int[] { 1, 2, 2, 1 }, new int[] { 2, 2 });

		for (int i = 0; i < r.Length; ++i)
			System.Console.WriteLine(r[i]);

		return 0;
	}
};

