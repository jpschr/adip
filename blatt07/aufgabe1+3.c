#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct dnode
{
	struct dnode *n;
	double d;
}dnode;
typedef dnode stack;

void printlist(dnode *h)
{
	dnode *curr=h;
	printf("( ");
	while (curr!=NULL)
	{
		printf("%f, ", curr->d);
		curr = curr->n;
	}
	printf(")\n");
}

dnode *insert(dnode *h, int i, double c)
{
	dnode *tmp;
	if(h==NULL || i<=1)
	{
		tmp=malloc(sizeof(dnode));
		tmp->d = c;
		tmp->n = (h==NULL) ? NULL : h;
		return tmp;
	}
	h->n = insert(h->n, (i-1), c);
	return h;
}

dnode *insertlst(dnode *head, double c) 
{ 
	int counter = 1;
	dnode *curr;
	if(head == NULL)
	{
		return insert(n, 1, c);
	}
	else
	{
		curr = head;
		while(curr->n != NULL)
		{
			curr = curr->n;
			++counter;
		}
		return insert(head, ++counter, c); 
	}
}

dnode *insertfrst(dnode *n, double c) { return insert(n, 1, c); }

dnode *reversecon(dnode *h)
{
	dnode *rev = NULL, *curr = h;
	while(curr!=NULL)
	{
		rev = insertfrst(rev, curr->d);
		curr = curr->n;
	}
	return rev;
}

dnode *reverse(dnode *h)
{
	dnode *curr = h, *prev = NULL, *nxt = NULL;
	while(1)
	{
		nxt = curr->n;
		curr->n = prev;
		prev = curr;
		if(nxt==NULL) return curr;
		curr = nxt;
	}
}

double get(dnode *h, int i)
{
	if(h==NULL) return 0;
	dnode *curr = h;
	while(1)
	{
		if(i<=1 || curr->n==NULL) return curr->d;
		curr = curr->n;
		--i;
	}
}

dnode *delete(dnode *h, int i)
{
	if(h==NULL) return NULL;
	dnode *tmp = h->n;
	if(i<=1)
	{
		free(h);
		return tmp;
	}
	h->n = delete(h->n, (i-1));
	return h;
}

void push(stack **h, int c) { *h=insertfrst(*h, c); }

int peek(stack *h) { return (int)get(h, 1); }

int pop(stack **h)
{
	int c = peek(*h);
	*h=delete(*h, 1);
	return c;
}

void print(stack *h) { printlist(h); }

int isempty(stack *h) { return h ? 0 : 1; }

int main()
{
	dnode *head[10];
	head[0] = malloc(sizeof(dnode));
	head[0]->n = NULL;
	head[0]->d = 1;
	
	for(int i = 1; i<11; i++){
		head[i] = insertfrst(head[i-1], (1.0/i)*1.25);
	}
	dnode *new;
	new = insertlst(head[10], 20);
	printlist(head[10]);
	
	stack *s=NULL;
	push(&s,4);
	push(&s,2);
	push(&s,1);
	printf("%d\n",peek(s));
	print(s);
	printf("%d\n", pop(&s));
	print(s);
	printf("%s\n", isempty(s) ? ("true") : ("false"));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%s\n", isempty(s) ? ("true") : ("false"));
	return EXIT_SUCCESS;
}




