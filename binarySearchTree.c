#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void create_tree (struct node *);
struct node *insertElement(struct node *, int);
void preorderTraversal(struct node *);
void inorderTraversal(struct node *);
void postorderTraversal(struct node *);
struct node *findSmallestElement(struct node *);
struct node *findLargestElement(struct node *);
struct node *deleteElement(struct node *, int);
struct node *mirrorImage(struct node *);
int totalNode(struct node *);
int totalExternalNodes(struct node *);
int totalInternalNodes(struct node *);
int height(struct node *);
struct node *deleteTree(struct node *);
int main(){
    int option, val;
    struct node *ptr;
    create_tree(tree);
    do{
        printf("\n ----MAIN MENU----");
        printf("\n 1. insert element\n 2. preorder reaversal\n 3. inorder traversal\n 4. postorder traversal");
       /* printf("\n 5. find the smallest element\n 6. find the largest element\n 7. delete an element");
        printf("\n 8. count the total number of nodes\n 9. count the total number of external nodes");
        printf("\n 10. count the total number of internal nodes\n 11. determine the hight of the tree");*/
        printf("\n 12. find the mirror image of the tree\n 13. delete the tree\n 14. exit");
        printf("\n\n Enter the option : ");
        scanf("%d", &option);
        switch(option){
            case 1: printf("\n Entre the value of the new node : ");
                scanf("%d", &val);
                tree=insertElement(tree, val);
                break;
            case 2: printf("\n The elements of the tree are : \n");
                inorderTraversal(tree);
                break;
            case 3: printf("\n The elements of the tree are : \n");
                preorderTraversal(tree);
                break;
            case 4: printf("\n The elements of the tree are : \n");
                postorderTraversal(tree);
                break;
            case 5: ptr=findSmallestElement(tree);
                printf("\n The smallest element is : %d", ptr->data);
                break;
            case 6: ptr=findLargestElement(tree);
                printf("\n The largest element is : %d", ptr->data);
                break;
            case 7: printf("\n Enter the element to be deleted : ");
                scanf("%d", &val);
                tree=deleteElement(tree, val);
                break;
            case 8: printf("\n Total number of node = %d", totalNode(tree));
                break;
           /* case 9: printf("\n Total number of external node = %d", totalExternalNodes(tree));
                break;
            case 10: printf("\n Total number of internal node = %d", totalInternalNodes(tree));
                break;
            case 11: printf("\n The hight of the tree = %d", height(tree));
                break;
            case 12: tree=mirrorImage(tree);
                break;
            case 13: tree=deleteTree(tree);
                break;*/
        }
    }while(option!=14);
    return 0;
}//----------------------total no. of nodes
int totalNode(struct node *tree){
    if(tree==NULL)
        return 0;
    else
        return (totalNode(tree->left)+totalNode(tree->right)+1);
}
//-----------------------delete an element
struct node *deleteElement(struct node *tree, int val){
    // first find whether the tree is empty or not
    struct node *cur, *parent, *suc, *psuc, *ptr;
    int hold;
    if(tree==NULL){
        printf("\n empty tree");
        return tree;
    }
    //if not then find the position
    parent=tree;
    cur=tree->left;
    while(cur!=NULL && val!=cur->data){
        parent=cur;
        cur=(val<cur->data)?cur->left:cur->right;
    }
    if(cur==NULL){
        printf("\n value is not present");
        return tree;
    }
    if(cur->left==NULL)
        ptr=cur->right;
    else if(cur->right==NULL)
        ptr=cur->left;
    else{
        // find the inorder successor and its parent
        psuc=cur;
        cur=cur->left;
        while(suc->left!=NULL){
            psuc=suc;
            suc=suc->left;
        }
        if(cur==psuc){
            // situation 1
            suc->left=cur->right;
        }
        else{
            // situation 2
            suc->left=cur->left;
            psuc->left=suc->left;
            suc->right=cur->right;
        }
        ptr=suc;
    }// attach ptr to the parent node
    if(parent->left==cur)
        parent->left=ptr;
    else
        parent->right=ptr;
    free(cur);
    return tree;
}
//-----------------------find largest element
struct node *findLargestElement(struct node *tree){
    if((tree==NULL)||(tree->right==NULL))
        return tree;
    else
        return findLargestElement(tree->right);
}//------------------------find smallest element
struct node *findSmallestElement(struct node *tree){
    if((tree==NULL)||(tree->left==NULL))
        return tree;
    else
        return findSmallestElement(tree->left);
}//--------------------------postorder traversal
void postorderTraversal(struct node *tree){
    if(tree!=NULL){
        postorderTraversal(tree->left);
        postorderTraversal(tree->right);
        printf(" %d\t", tree->data);
    }
}//----------------------------inorder traversal
void inorderTraversal(struct node *tree){
    if(tree!=NULL){
        inorderTraversal(tree->left);
        printf(" %d\t", tree->data);
        inorderTraversal(tree->right);
    }
}//-----------------------------preorder traversal
void preorderTraversal(struct node *tree){
    if(tree!=NULL){
        printf(" %d\t", tree->data);
        preorderTraversal(tree->left);
        preorderTraversal(tree->right);
    }
}//--------------------------------- insert element
struct node *insertElement(struct node *tree, int val){
    struct node *p, *pp, *nn;              // *p=pointer, *pp=pre pointer, *nn=new node
    nn=(struct node *)malloc(sizeof(struct node));
    nn->data=val;
    nn->left=nn->right=NULL;
    if(tree==NULL){
        tree=nn;
        tree->left=tree->right=NULL;
    }
    else{
        p=tree;
        pp=NULL;
        while(p!=NULL){
            pp=p;
            if(val<p->data)
                p=p->left;
            else
                p=p->right;
        }
        if(val<pp->data)
            pp->left=nn;
        else
            pp->right=nn;
    }
    return tree;
}
void create_tree(struct node *tree){
    tree=NULL;
}