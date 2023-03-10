//210229017 Rümeysa YAŞAR
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* root =NULL;

struct node *newNode(int key)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    return temp;
};

void inorder(struct  node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }    
}

struct node* insert(struct node* node, int key)
{
    if(node  == NULL)
    {
        return newNode(key);
    }
    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    
    return node;
};

void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
void printCurrentLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

int height(struct node* node)
{
    if (node == NULL)
        return 0;
    else 
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        if (lheight > rheight)
        {
            return (lheight + 1);
        }
            
        else
        {
            return (rheight + 1);
        }
    }
}



int listMinMax(struct node* root)
{
    struct node *prev = (struct node*)malloc(sizeof(struct node));
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = root;
    int ata_max = 0, kardes_max = 0;
    int ata_min = 0, kardes_min = 0;

    while (root->right != NULL)
    {
        prev = root;
        root = root->right;
    }
    if (prev != NULL)
    {
        ata_max = prev->data;
        printf("ata_max: %d\n", ata_max);
        if (prev->left != NULL)
        {
            kardes_max = prev->left->data;
            printf("kardes_max: %d\n", kardes_max);
        }
    }
    
    root = temp;
    while (root->left != NULL)
    {
        prev = root;
        root = root->left;
    }
    if (prev != NULL)
    {
        ata_min = prev->data;
        printf("ata_min: %d\n", ata_min);

        if (prev->right != NULL)
        {
            kardes_min = prev->right->data;
            printf("kardes_min: %d\n", kardes_min);
        }
    }
}



int main()
{
    int secim;

    insert(root, 12);
    insert(root, 3);
    insert(root, 5);
    insert(root, 16);
    insert(root, 7);
    insert(root, 53);
    insert(root, 24);
    insert(root, 72);
    insert(root, 19);
    insert(root, 1);
    insert(root, 62);
    inorder(root);

    printf("\n Level Order traversal of binary tree is \n");
    printLevelOrder(root);
    printf("\n ListMinMax: \n");
    listMinMax(root);

    return 0;
}