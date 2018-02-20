
public class Solution {
	public bool IsValid(string s)
	{
		System.Collections.Generic.Stack<char> stack = 
			new System.Collections.Generic.Stack<char>();
		System.Collections.Generic.Dictionary<char, char> dict = 
			new System.Collections.Generic.Dictionary<char, char>();
		dict.Add('(', ')');
		dict.Add('[', ']');
		dict.Add('{', '}');

		foreach (char c in s) {
			if (dict.ContainsKey(c)) {
				stack.Push(c);
			} else if (stack.Count != 0) {
				char k = stack.Pop();
				if (c != dict[k])
					return false;
			} else {
				return false;
			}
				
		}

		return stack.Count == 0;
	}
};


public class ValidParentheses {
	static int Main(string[] args)
	{
		Solution s = new Solution();
		System.Console.WriteLine(s.IsValid("(){}[]()[]{}"));
		System.Console.WriteLine(s.IsValid("(){}[]()[]{}}{"));
		return 0;
	}
};
