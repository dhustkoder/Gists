public class VersionControl {
	const int _badVer = 10;
	public bool IsBadVersion(int version)
	{
		return version >= _badVer;
	}
};

public class Solution : VersionControl {
	public int FirstBadVersion(int n)
	{
		int low = 1;
		int high = n;
		int mid;
		while (low < high) {
			mid = low + (high - low) / 2;
			if (!IsBadVersion(mid))
				low = mid + 1;
			else
				high = mid;
		}
		return low;
	}
};


public class BadVersion {
	public static int Main(string[] args)
	{
		Solution s = new Solution();
		System.Console.WriteLine(s.FirstBadVersion(150));
		return 0;
	}
};
