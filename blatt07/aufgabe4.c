#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
	int value;
	struct tnode* left;
	struct tnode* right;
}tnode;

void preorder(tnode* root){
	if(root==NULL) return;
	printf("%i ", root->value);
	preorder(root->left);
	preorder(root->right);
}

void inorder(tnode* root){
	if(root==NULL) return;
	inorder(root->left);
	printf("%i ", root->value);
	inorder(root->right);
}

void postorder(tnode* root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	printf("%i ", root->value);

}

/* printlevel gibt alle values von Knoten der Ebene level aus*/
int printlevel(tnode* root, unsigned level){
	if(root==NULL) return 0;
	if(level==1){ /* Trivialfall: gibt die Wurzel aus*/
		printf("%i ", root->value);
		return 1;
	}
	return (printlevel(root->left, level-1)+ /*Ansonsten: Rekursion mit veringertem level auf linken/rechten Teilbaum bis level==1 (Trivialfall) gilt */
	printlevel(root->right, level-1));
	return 0;
}

void levelorder(tnode* root){
	int i;
	i=1;
	if(NULL==root) return;
	while(printlevel(root,i)) i++; /* Gibt Knoten des level aus solange das level nicht vollständig NULL ist*/
}


int main(){
	tnode* root=malloc(sizeof(tnode));
	if(NULL==root) return EXIT_FAILURE ;
	root->value=3;

	root->left=malloc(sizeof(tnode));
	if(NULL==root->left) return EXIT_FAILURE;
	(root->left)->value=5;


	root->right=malloc(sizeof(tnode));
	if(NULL==root->right) return EXIT_FAILURE;
	(root->right)->value=7;

	(root->right)->left=malloc(sizeof(tnode));
	if(NULL==(root->right)->left) return EXIT_FAILURE;
	((root->right)->left)->value=6;

/*              3
               / \
              5   7
		 /
		6
*/
	printf("preorder:\n");
	preorder(root);
	printf("\n");
	printf("inorder:\n");
	inorder(root);
	printf("\n");
	printf("postorder\n");
	postorder(root);
	printf("\n");
	printf("levelorder\n");
	levelorder(root);
	printf("\n");
	return EXIT_SUCCESS;
}
