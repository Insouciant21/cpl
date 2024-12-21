#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
	MODN = 200000
};

long long hash(const char* s)
{
	int len = strlen(s);
	long long ret = 0;
	for (int i = 0; i < len; i++)  ret = (ret + s[i] * (i + 1LL)) % MODN;
	return ret;
}

typedef struct Node
{
	char* s;
	struct Node* next;
}Node;

typedef struct List
{
	Node* head;
} List;

List list[MODN];
char str[50000007];

void append(List* l, Node* n)
{
	n->next = l->head;
	l->head = n;
}

int main()
{
	int m, q, c = 0;
	scanf("%d %d", &m, &q);
	for (int i = 0; i < m; i++)
	{
		scanf("%s", str + c);
		long long h = hash(str + c);
		Node* n = malloc(sizeof(Node));
		n->s = str + c;
		append(&list[h], n);
		c += strlen(str + c) + 1;
	}
	while (q--)
	{
		char s[1002];
		scanf("%s", s);
		long long h = hash(s);
		Node* cur = list[h].head;
		while (cur)
		{
			if (strcmp(cur->s, s) == 0)
			{
				puts("Yes");
				break;
			}
			cur = cur->next;
		}
		if (!cur) puts("No");
	}
	return 0;
}