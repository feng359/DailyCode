#include <stdio.h>
#include <stdlib.h>

typedef int data_t;
typedef struct node_t
{
    data_t data;
    struct node_t *left;
    struct node_t *right;
} treeNode;

treeNode *TreeCreate();
void PreOrder(treeNode *node);
void InOrder(treeNode *node);
void PostOrder(treeNode *node);


//AB#CD###E#FGH##K###
//先序：ABCDEFGHK;中序：BDCAEHGKF;后续：DCBHKGFEA
int main()
{
    treeNode *biTree = TreeCreate();

    printf("preOrder:");
    PreOrder(biTree);
    puts("");

    printf("InOrder:");
    InOrder(biTree);
    puts("");
    
    printf("PostOrder:");
    PostOrder(biTree);
    puts("");

    system("pause");
    return 0;
}

treeNode *TreeCreate()
{
    treeNode *p;
    data_t data;

    scanf("%c", &data);
    if (data == '#')
    {
        return NULL;
    }

    if ((p = (treeNode *)malloc(sizeof(treeNode))) == NULL)
    {
        printf("malloc failed");
        return NULL;
    }

    p->data = data;
    p->left = TreeCreate();
    p->right = TreeCreate();
    return p;
}

void PreOrder(treeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    printf("%c ",node->data);
    PreOrder(node->left);
    PreOrder(node->right);
}

void InOrder(treeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    InOrder(node->left);
    printf("%c ",node->data);
    InOrder(node->right);
}

void PostOrder(treeNode *node)
{
    if (node == NULL)
    {
        return;
    }
    PostOrder(node->left);
    PostOrder(node->right);
    printf("%c ",node->data);
}