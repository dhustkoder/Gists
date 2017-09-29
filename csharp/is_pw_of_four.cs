
public class Solution {
	public bool IsPowerOfFour(int num)
	{
		return ((num - 1) & num) == 0 && ((num - 1) % 3) == 0;
	}
};




public class Program {
	public static int Main(string[] args)
	{
		Solution s = new Solution();

		for (int i = 0; i < 1000000; ++i)
			System.Console.WriteLine(s.IsPowerOfFour(i));

		return 0;
	}
};

