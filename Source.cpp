#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack					// A structure to represent a stack 
{
	int top;
	int capacity;
	int *array;
};

struct Stack* createStack(int cap)	// function to create a stack of given capacity.
{
	struct Stack *st = (struct Stack*)malloc(sizeof(struct Stack));
	st->top = -1;
	st->capacity = cap;
	st->array = (int*)malloc(st->capacity*sizeof(int));
	return st;
}

int isFull(struct Stack *st)  // Stack is full when top is equal to the last index 
{
	return (st->top == st->capacity - 1);
}

int isEmpty(struct Stack *st)  // Stack is empty when top is equal to -1 
{
	return (st->top == -1);
}

void push(struct Stack *st, int item)  // Function to add an item to stack.  It increases top by 1 
{
	if (isFull(st))
	{
		printf("\nStack is full \n");
		return;
	}
	st->top ++;
	st->array[st->top] = item;
	printf("%d pushed to stack\n", item);
}

int pop(struct Stack *st)    // Function to remove an item from stack.  It decreases top by 1 
{
	if (isEmpty(st))
		return INT_MIN;
	int temp = st->array[st->top];
	st->top--;
	return temp;
}

int peek(struct Stack *st)    // Function to return the top from stack without removing it
{
	if (isEmpty(st))
		return INT_MIN;
	return st->array[st->top];
}

void display(struct Stack *st)
{
	if (isEmpty(st))
		printf("Empty stack \n");
	else {
			printf("Stack elements are : \n");
			for (int i = st->top; i >= 0; i--)
				printf("%d \n", st->array[i]);
		  }
}

void disposeStack(struct Stack *st)
{
	if (st != NULL)
	{
		free(st->array);
		free(st);
	}
}

void main()
{
	int n, x, ch, i;
	struct Stack *s;
	printf("Enter the maximum number of elements in the stack : ");
	scanf("%d", &n);
	s = createStack(n);
	printf("ARRAY IMPLEMENTATION OF STACK ADT\n");
	do
	{
		printf("\n1. PUSH\t 2. POP\t 3. TOP\t 4. DISPLAY\t 5. QUIT \n\nEnter your choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter the element to be pushed : ");
			scanf("%d", &x);
			push(s, x);							//while (1)		- stack overflow
								        		//push(s, 2);	- stack overflow
			
			break;

		case 2:
			printf("Popped element is %d \n",pop(s));
			break;

		case 3:
			printf("The Top element in the stack : %d\n\n", peek(s));
			break;

		case 4:
			display(s);
			break;
		}
	} while (ch>0 && ch<5);
disposeStack(s);
	_getch();
}