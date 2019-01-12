#include<stdio.h>
#include<malloc.h>
#include<assert.h>
 
#define ElemType char
 
typedef struct TreeNode
{
	ElemType data;
	struct TreeNode *firstChild;
	struct TreeNode *nextSibling;
}TreeNode;
 
typedef struct Tree
{
	TreeNode *root;
	ElemType refValue;
}Tree;
 
void InitTree(Tree *tree, ElemType ref);
void CreateTree(Tree *tree, char *str);
void CreateTree(Tree *tree, TreeNode *&t, char *&str);
TreeNode* Root(Tree *tree);
TreeNode* FirstChild(Tree *tree);
TreeNode* FirstChild(TreeNode *t);
TreeNode* NextSibling(Tree *tree);
TreeNode* NextSibling(TreeNode *t);
TreeNode* Find(Tree* tree, ElemType key);
TreeNode* Find(TreeNode* t, ElemType key);
TreeNode* Parent(Tree *tree, TreeNode *p);
TreeNode* Parent(TreeNode *t, TreeNode *p);



void InitTree(Tree *tree, ElemType ref)
{
	tree->root = NULL;
	tree->refValue = ref;
}
 
void CreateTree(Tree *tree, char *str)
{
	CreateTree(tree, tree->root, str);
}
void CreateTree(Tree *tree, TreeNode *&t, char *&str)
{
	if (*str == tree->refValue)
		t = NULL;
	else
	{
		t = (TreeNode*)malloc(sizeof(TreeNode));
		assert(t != NULL);
		t->data = *str;
		CreateTree(tree, t->firstChild, ++str);
		CreateTree(tree, t->nextSibling, ++str);
	}
}
 
TreeNode* Root(Tree *tree)
{
	return tree->root;
}
TreeNode* FirstChild(Tree *tree)
{
	return FirstChild(tree->root);
}
TreeNode* FirstChild(TreeNode *t)
{
	if (t == NULL)
		return NULL;
	return t->firstChild;
}
TreeNode* NextSibling(Tree *tree)
{
	return NextSibling(tree->root);
}
TreeNode* NextSibling(TreeNode *t)
{
	if (t == NULL)
		return NULL;
	return t->nextSibling;
}
 
TreeNode* Find(Tree* tree, ElemType key)
{
	return Find(tree->root, key);
}
TreeNode* Find(TreeNode* t, ElemType key)
{
	if (t == NULL)
		return NULL;
	if (t->data == key)
		return t;
 
	TreeNode *p;
	p=Find(t->firstChild, key);
	if (p != NULL)
		return p;
	return Find(t->nextSibling, key);
 
}
 
TreeNode* Parent(Tree *tree, TreeNode *p)
{
	return Parent(tree->root, p);
}
 
//ÓÐµã¸´ÔÓ
TreeNode* Parent(TreeNode *t, TreeNode *p)
{
	if (t == NULL || p == NULL || t == p)
		return NULL;
 
	TreeNode *q = t->firstChild;
	TreeNode *parent;
	while (q != NULL && q != p)
	{
		parent = Parent(q, p);
		if (parent != NULL)
			return parent;
		q = q->nextSibling;
	}
 
	if (q != NULL && q == p)
		return t;
	return NULL;
}


int main()
{
	char *str = "RAD#E##B#CFG#H#K#####";
	Tree mytree;
	InitTree(&mytree,'#');
	CreateTree(&mytree, str);
 
	TreeNode *p = Find(&mytree, 'K');
	TreeNode *parent = Parent(&mytree, p);
	printf("%c\n", parent->data);
	return 0;
}


