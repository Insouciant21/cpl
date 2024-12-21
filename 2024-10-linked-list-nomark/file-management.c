#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char name[15];
	struct Node** dirents;
	int size;
} Node;

Node* root;

Node* find(Node* cur, const char* s2)
{
	if (strcmp(s2, cur->name) == 0) return cur;
	for (int i = 0; i < cur->size; i++)
	{
		Node* res = find(cur->dirents[i], s2);
		if (res != NULL) return res;
	}
	return NULL;
}

int count(Node* cur)
{
	int res = 0;
	for (int i = 0; i < cur->size; i++)
		res += count(cur->dirents[i]);
	return res + cur->size;
}

Node* findParent(Node* cur, const Node* target)
{
	for (int i = 0; i < cur->size; i++)
		if (cur->dirents[i] == target) return cur;
	for (int i = 0; i < cur->size; i++)
	{
		Node* p = findParent(cur->dirents[i], target);
		if (p != NULL) return p;
	}
	return NULL;
}

void freeNode(Node* cur)
{
	for (int i = 0; i < cur->size; i++)
		freeNode(cur->dirents[i]);
	free(cur->dirents);

	free(cur);
}

int main()
{
	int n, q; root = (Node*)malloc(sizeof(Node));
	root->dirents = NULL; root->size = 0; strcpy(root->name, "~~~");
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
	{
		char s1[20], s2[20];
		scanf("%s%s", s1, s2);
		Node* cur = find(root, s2);
		Node* newNode = malloc(sizeof(Node));
		cur->dirents = realloc(cur->dirents, (cur->size + 1) * sizeof(Node*));
		cur->dirents[cur->size] = newNode;
		newNode->dirents = NULL; newNode->size = 0;
		strcpy(newNode->name, s1);
		cur->size++;
	}
	while (q--)
	{
		char op[8], str[20];
		scanf("%s%s", op, str);
		if (op[0] == 'q')
		{
			Node* res = find(root, str);
			printf("%d\n", count(res) + 1);
		}
		else
		{
			Node* res = find(root, str); 
		    Node* p = findParent(root, res);
			for (int i = 0; i < p->size; i++)
			{
				if (p->dirents[i] == res)
				{
					memmove(p->dirents + i, p->dirents + i + 1, sizeof(Node*) * (p->size - i));
					p->dirents = realloc(p->dirents, p->size--);
					break;
				}
			}
			freeNode(res);
		}
	}
	return 0;
}