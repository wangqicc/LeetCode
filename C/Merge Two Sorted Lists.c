#include <stdio.h>	//基本输入输出函数
#include <stdlib.h>	//用于分配内存 malloc

struct ListNode {
	int val;
	struct ListNode* next;
};

/*
	功能：递归方式归并两个已排序的链表
	传入参数：两个已排序的链表
	返回值：合并的已排序链表
*/
struct ListNode* mergeTwoListsRecursive(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL) {
		return l2;
	}
	if (l2 == NULL) {
		return l1;
	}
	if (l1 -> val < l2 -> val) {
		l1 -> next = mergeTwoListsRecursive(l1 -> next, l2);
		return l1;
	} else {
		l2 -> next = mergeTwoListsRecursive(l1, l2 -> next);
		return l2;
	}
}

/*
	功能：非递归方式归并两个已排序的链表
	传入参数：两个已排序的链表
	返回值：合并的已排序链表
*/
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) {
        return l2;
    }
    if(l2 == NULL) {
        return l1;
    }
    struct ListNode* head;
    struct ListNode* p;
    if(l1 -> val < l2 -> val) {
        head = l1;
        l1 = l1 -> next;
    } else {
        head = l2;
        l2 = l2 -> next;
    }
    p = head;
    while(l1 != NULL && l2 != NULL) {
        if(l1 -> val < l2 -> val) {
            p -> next = l1;
            l1 = l1 -> next;
        } else {
            p -> next = l2;
            l2 = l2 -> next;
        }
        p = p -> next;
    }
    if(l1 != NULL) {
        p -> next = l1;
    }
    if(l2 != NULL) {
        p -> next = l2;
    }
    return head;
}

/*输出链表*/
/*
	传入参数1：不带头结点的链表 printList(l);
	传入参数2：带头结点的链表 printList(l -> next);
*/
void printList(struct ListNode* l) {
	struct ListNode* p = l;

	while (p -> next != NULL) {
		printf("%d->", p -> val);
		p = p -> next;
	}

	printf("%d\n", p -> val);
}

/*
	功能：尾插法创建含头结点的链表
*/
void CreateListRH(struct ListNode* &L, int a[], int n) {
	L = (struct ListNode *)malloc(sizeof(struct ListNode));
	L -> next = NULL;

	struct ListNode *p;//指针 p 来进行操作
	p = L;

	struct ListNode *s;
	int i;
	for(i = 0; i < n; ++i) {
		s = (struct ListNode *)malloc(sizeof(struct ListNode));
		s -> val = a[i];
		p -> next = s;
		p = s;
	}
	p -> next = NULL;
}

/*
	功能：尾插法创建不含头结点的链表
*/
void CreateListR(struct ListNode* &L, int a[], int n) {
	struct ListNode *p;//指针 p 来进行操作
	struct ListNode *s;
	//reset list
	if (n > 0) {
		s = (struct ListNode *)malloc(sizeof(struct ListNode));
		s -> val = a[0];
		L = s;
		p = L;
	} else {
		L -> next = NULL;
		return;
	}
	int i;
	for(i = 1; i < n; ++i) {
		s = (struct ListNode *)malloc(sizeof(struct ListNode));
		s -> val = a[i];
		p -> next = s;
		p = s;
	}
	p -> next = NULL;
}

int main(int argc, char const *argv[]) {
	int a[3] = {1, 2, 4};
	int b[3] = {1, 3, 4};

	struct ListNode* l1;
	CreateListR(l1, a, 3);
	printList(l1);

	struct ListNode* l2;
	CreateListR(l2, b, 3);
	printList(l2);

	printList(mergeTwoListsRecursive(l1, l2));
	return 0;
}