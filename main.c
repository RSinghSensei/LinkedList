#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define start 0
//#define end 50
//#define step 5
#define pause system("PAUSE");

struct Node {
	int data;
	struct Node* next;
};

struct Node* Head = NULL;
struct Node* ptr2;
struct Node* Head2 = NULL;
struct Node* head2ptr2;


void InsertionFront() {
	int n1;
	printf("Enter a number to place in the first poisiton of your linked list\n");
	scanf_s("%d", &n1);
	ptr2 = (struct Node*)malloc(sizeof(struct Node));
	ptr2->data = n1;
	ptr2->next = Head;
}

void InsertionBack(){
	int n2;
	struct Node* ptr3 = Head;
	struct Node* temp2;
	printf("Enter a number to place in the last positioin of your linked list\n");
	scanf_s("%d", &n2);
	while (ptr3->next != NULL) {
		ptr3 = ptr3->next;
	}
	temp2 = (struct Node*)malloc(sizeof(struct Node));
	temp2->data = n2;
	temp2->next = NULL;
	ptr3->next = temp2;
	ptr3 = ptr3->next;

	}
	
void DeletionFront() {
	struct Node* ptr3 = ptr2;
	printf("Deleting first value of linked list\n");
	pause;
	ptr2 = ptr2->next;
	free(ptr3);

}
void DeletionBack() {
	struct Node* ptr3 = ptr2;
	struct Node* ptr4 = ptr3;
	printf("Deleting last value of linked list\n");
	pause;
	while (ptr3->next->next != NULL) {
		ptr3 = ptr3->next;
		ptr4 = ptr3->next;
	}
	ptr3->next = NULL;
	free(ptr4);
}

void SInsertion() {
	int n4, n5, len = 0;
	struct Node* ptr3 = Head;
	struct Node* temp2;
	printf("Enter a value\n");
	scanf_s("%d", &n4);
	printf("Enter the position (0-based) at which you wish to enter this value\n");
	scanf_s("%d", &n5);
	n5 -= 1;
	while (len != n5) {
		ptr3 = ptr3->next;
		len += 1;
	}
	temp2 = (struct Node*)malloc(sizeof(struct Node));
	temp2->data = n4;
	temp2->next = ptr3->next;
	ptr3->next = temp2;
	printf("\n");
}


void SortedList() {
	int swapped = 1, temp, arr[20], i = 0;
	struct Node* ptr3 = Head;
	printf("Sorting your linked list..\n");
	pause;
	while (ptr3 != NULL) {
		arr[i] = ptr3->data;
		i += 1;
		ptr3 = ptr3->next;
	}
	i -= 1;
	while (swapped == 1) {
		swapped = 0;
		for (int p1 = 1; p1 <= i; p1++) {
			if (arr[p1 - 1] < arr[p1]) {
				temp = arr[p1 - 1];
				arr[p1 - 1] = arr[p1];
				arr[p1] = temp;
				swapped = 1;
			}
		}
	}
	for (i; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void ReverseList() {
	printf("Reversing your linked list..\n");
	pause;
	int arr[20], i = 0;
	struct Node* ptr3 = Head;
	while (ptr3 != NULL) {
		arr[i] = ptr3->data;
		i += 1;
		ptr3 = ptr3->next;
	}
	i -= 1;
	for (i ; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void DisplayLinkedList() {
	struct Node* ptr1 = ptr2;
	while (ptr1 != NULL) {
		printf("%d ", ptr1->data);
		ptr1 = ptr1->next;
	}
	printf("\n");
}

void SecondLinkedList() {
	int n,numbers;
	struct Node* twoptr = NULL;
	struct Node* ptr3 = ptr2;
	printf("Creating a new linked list!\n");
	pause;
	printf("How many values do you want to enter?\n");
	scanf_s("%d", &numbers);
	while (numbers != 0) {
		struct Node* temp1;
		temp1 = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter a number: \n");
		scanf_s("%d", &n);
		temp1->data = n;
		temp1->next = NULL;
		if (Head2 == NULL) {
			Head2 = temp1;
			numbers -= 1;
			twoptr = Head2;
			continue;
		}
		twoptr->next = temp1;
		twoptr = twoptr->next;
		numbers -= 1;
	}
	head2ptr2 = (struct Node*)malloc(sizeof(struct Node));
	head2ptr2->data = NULL;
	head2ptr2->next = Head2;
	head2ptr2 = head2ptr2->next;
	printf("Now printing a concatenated linked list...\n");
	pause;
	while (ptr3->next != NULL) {
		ptr3 = ptr3->next;
	}
	ptr3->next = head2ptr2;

}


int main() {
	int n,numbers;
	struct Node* ptr = NULL;
	printf("Let's create a linked list!\n");
	pause;
	printf("How many values do you want to enter?\n");
	scanf_s("%d", &numbers);
	while (numbers != 0) {
		struct Node* temp1;
		temp1 = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter a number: \n");
		scanf_s("%d", &n);
		temp1->data = n;
		temp1->next = NULL;
		if (Head == NULL) {
			Head = temp1;
			numbers -= 1;
			ptr = Head;
			continue;
		}
		ptr->next = temp1;
		ptr = ptr->next;
		numbers -= 1;
	}
	printf("\n");

	InsertionFront();
	InsertionBack();
	DisplayLinkedList();
	DeletionFront();
	DisplayLinkedList();
	DeletionBack();
	DisplayLinkedList();
	SInsertion();
	DisplayLinkedList();
	ReverseList();
	SortedList();
	SecondLinkedList();
	DisplayLinkedList();

	printf("End of Linked List Demo!\n");

	return 0;
}
