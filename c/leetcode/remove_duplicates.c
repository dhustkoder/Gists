#include <stdio.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* deleteDuplicates(struct ListNode* const head)
{
	struct ListNode* rm;
	struct ListNode* p = head;

	while (p != NULL && p->next != NULL) {
		if (p->val == p->next->val) {
			rm = p->next;
			p->next = p->next->next;
			free(rm);
		} else {
			p = p->next;
		}
	}

	return head;
}




int main(void)
{
	int i, j;
	struct ListNode* rm;
	struct ListNode* head = malloc(sizeof(struct ListNode));
	struct ListNode* p = head;

	for (i = 0; i < 10; ++i) {
		p->next = malloc(sizeof(struct ListNode));
		p = p->next;
	}

	p->next = NULL;
	
	for (p = head, i = 0, j = 0; p != NULL; p = p->next) {
		if (i == 2) {
			++j;
			i = 0;
		}
		p->val = j;
		++i;
	}

	printf("LIST:\n");
	for (p = head; p != NULL; p = p->next)
		printf("%d\n", p->val);

	head = deleteDuplicates(head);

	printf("REMOVED DUPLICATES: \n");
	for (p = head; p != NULL;) {
		printf("%d\n", p->val);
		rm = p;
		p = p->next;
		free(rm);
	}

	return 0;
}




