

public class Solution {
	public int IslandPerimeter(int[,] grid)
	{
		int count = 0;
		int repeat = 0;
		int rows = grid.GetLength(0);
		int cols = grid.GetLength(1);

		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (grid[i,j] == 1) {
					++count;
					if (i != 0 && grid[i - 1, j] == 1)
						repeat++;
					if (j != 0 && grid[i, j - 1] == 1)
						repeat++;
				}
			}
		}

		return 4 * count - repeat * 2;
	}
};


public class Perimeter {
	public static int Main(string[] args)
	{
		int[,] grid = new int[4,4] {
			{0, 1, 0, 0},
			{1, 1, 1, 0},
			{0, 1, 0, 0},
			{1, 1, 0, 0}
		};
		Solution s = new Solution();
		System.Console.WriteLine(s.IslandPerimeter(grid));
		return 0;
	}
};
