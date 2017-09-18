#include <stdio.h>


typedef struct TreeNode {
	int val;
	const struct TreeNode* left;
	const struct TreeNode* right;
} TreeNode;


static int sum_of_left_leaves(const struct TreeNode* const root)
{
	if (root == NULL)
		return 0;
	else if (root->left != NULL &&
		 root->left->left == NULL &&
		 root->left->right == NULL)
		return root->left->val + sum_of_left_leaves(root->right);
	else
		return sum_of_left_leaves(root->left) + sum_of_left_leaves(root->right);
}


int main(void)
{
	const TreeNode a = { 9, NULL, NULL };
	const TreeNode b = { 15, NULL, NULL };
	const TreeNode c = { 7, NULL, NULL };
	const TreeNode d = { 20, &b, &c };
	const TreeNode e = { 3, &a, &d };


	printf("%d\n", sum_of_left_leaves(&e));

	return 0;
}

