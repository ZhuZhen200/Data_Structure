#include"head.h"
List Read()
{
	List head, end, temp;
	Elementype n, data;

	scanf_s("%d", &n);
	head = (List)malloc(sizeof(struct Node));
	head->Data = n;
	head->Next = NULL;
	end = head;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &data);
		temp = (List)malloc(sizeof(struct Node));
		temp->Data = data;
		temp->Next = NULL;
		end->Next = temp;
		end = end->Next;

	}
	return head;
}