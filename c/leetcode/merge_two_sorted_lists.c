#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode* next;
};


static struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode head;
	struct ListNode* out = &head;

	while (l1 != NULL && l2 != NULL) {
		if (l1->val < l2->val) {
			out->next = l1;
			l1 = l1->next;
		} else {
			out->next = l2;
			l2 = l2->next;
		}
		out = out->next;
	}

	out->next = l1 != NULL ? l1 : l2;

	return head.next;
}


int main(void)
{
	struct ListNode l1[] = { {0, NULL}, {2, NULL}, {4, NULL}, {6, NULL} };
	struct ListNode l2[] = { {1, NULL}, {3, NULL}, {5, NULL}, {7, NULL} };
	struct ListNode* merged;
	const int lsize = sizeof(l1) / sizeof(struct ListNode);
	int i;

	for (i = 0; i < (lsize - 1); ++i) {
		l1[i].next = &l1[i + 1];
		l2[i].next = &l2[i + 1];
	}

	puts("L1:");

	for (i = 0; i < lsize; ++i)
		printf("%d\n", l1[i].val);

	puts("L2:");

	for (i = 0; i < lsize; ++i)
		printf("%d\n", l2[i].val);

	merged = mergeTwoLists(l1, l2);

	puts("MERGED:");

	for (; merged != NULL; merged = merged->next)
		printf("%d\n", merged->val);

	return 0;
}

