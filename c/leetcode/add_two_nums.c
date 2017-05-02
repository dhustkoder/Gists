#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode* next;
};


static struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	struct ListNode head;
	struct ListNode* p = &head;
	int x, y, sum;
	int carry = 0;

	while (l1 || l2) {
		x = l1 != NULL ? l1->val : 0;
		y = l2 != NULL ? l2->val : 0;
		sum = x + y + carry;
		carry = sum / 10;
		p->next = malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = sum % 10;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}

	if (carry != 0) {
		p->next = malloc(sizeof(struct ListNode));
		p = p->next;
		p->val = carry;
	}

	p->next = NULL;
	return head.next;
}


int main(void)
{
	int i;
	struct ListNode* rm;
	struct ListNode* res;
	struct ListNode nodes_a[3] = {{2, NULL}, {4, NULL}, {3, NULL}};
	struct ListNode nodes_b[3] = {{5, NULL}, {6, NULL}, {4, NULL}};

	for (i = 0; i < 2; ++i) {
		nodes_a[i].next = &nodes_a[i + 1];
		nodes_b[i].next = &nodes_b[i + 1];
	}

	nodes_a[i].next = NULL;
	nodes_b[i].next = NULL;

	res = addTwoNumbers(&nodes_a[0], &nodes_b[0]);

	while (res != NULL) {
		printf("%d -> ", res->val);
		rm = res;
		res = res->next;
		free(rm);
	}
	
	printf("NULL\n");
	return 0;
}

