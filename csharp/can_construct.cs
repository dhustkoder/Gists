
using System.Collections.Generic;

class CanConstruct {
	static bool Execute(string ransomNote, string magazine)
	{
		var a = new List<char>();
		var b = new List<char>();

		foreach (char x in ransomNote)
			a.Add(x);
		foreach (char x in magazine)
			b.Add(x);

		foreach (char x in b)
			a.Remove(x);

		return a.Count == 0;
	}

	static int Main(string[] args)
	{
		System.Console.WriteLine(Execute("aa", "aab"));
		return 0;
	}
}





