using System;


class ReverseVowels {
	static string Reverse(string str)
	{
		Func<char, bool> IsVowel = c => {
			char[] vowels = new char[] {
				'a', 'e', 'i', 'o', 'u',
				'A', 'E', 'I', 'O', 'U'
			};

			return Array.Exists(vowels, x => x == c);
		};

		System.Text.StringBuilder sb = new System.Text.StringBuilder(str);

		int beg = 0;
		int end = sb.Length - 1;
		while (end > beg) {
			if (!IsVowel(sb[beg]))
				++beg;
			if (!IsVowel(sb[end]))
				--end;
			if (IsVowel(sb[beg]) && IsVowel(sb[end])) {
				char aux = sb[beg];
				sb[beg] = sb[end];
				sb[end] = aux;
				++beg;
				--end;
			}
		}

		return sb.ToString();
	}

	static int Main(string[] args)
	{
		Console.WriteLine(Reverse(args[0]));
		return 0;
	}
}







