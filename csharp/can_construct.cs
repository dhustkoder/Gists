
using System.Collections.Generic;

class CanConstruct {
	static bool Execute(string ransomNote, string magazine)
	{
		var a = new List<char>(ransomNote);

		foreach (char x in magazine)
			a.Remove(x);

		return a.Count == 0;
	}

	static int Main(string[] args)
	{
		System.Console.WriteLine(Execute("aa", "aab"));
		return 0;
	}
}





