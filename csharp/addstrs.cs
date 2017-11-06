using System;
using System.Collections.Generic;


public class AddStrs {

	public static string AddStrings(string a, string b)
	{
		int i = a.Length - 1;
		int j = b.Length - 1;
		int c = 0;

		var res = new String('-', 0);

		while (i >= 0 || j >= 0 || c != 0) {
			int sum = 0;

			if (i >= 0)
				sum += a[i--] - '0';
			if (j >= 0)
				sum += b[j--] - '0';
			sum += c;
			c = sum / 10;
			sum = sum % 10;
			res += sum.ToString();
		}

		var tmp = res.ToCharArray();
		Array.Reverse(tmp);
		return new string(tmp);
	}

	static int Main(string[] args)
	{
		Console.WriteLine(AddStrings("11","88"));
		return 0;
	}
}




