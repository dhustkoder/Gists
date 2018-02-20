using System;

class ReverseString {

	static string Reverse(string str)
	{
		char[] arr = str.ToCharArray();
		Array.Reverse(arr);
		return new string(arr);
	}

	static void Main(string[] args)
	{
		Console.WriteLine(Reverse(args[0]));
	}

}


