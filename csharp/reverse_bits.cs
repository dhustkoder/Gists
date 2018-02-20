

public class Solution {
	public uint ReverseBits(uint n)
	{
		uint r = 0;
		for (int i = 0; i < 32; ++i) {
			r |= (n&0x01)<<(31 - i);
			n >>= 1;
		}
		return r;
	}

	public static int Main(string[] args)
	{
		Solution s = new Solution();

		uint x = 0xb3;

		for (int i = 0; i < 32; ++i)
			System.Console.Write(((x&(1u<<i)) != 0 ? "1" : "0"));

		System.Console.Write("\n");

		x = s.ReverseBits(x);

		for (int i = 0; i < 32; ++i)
			System.Console.Write(((x&(1u<<i)) != 0 ? "1" : "0"));

		System.Console.Write("\n");

		return 0;
	}
}

