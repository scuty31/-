#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* search(TreeNode* node, int key){
	while (node != NULL) {
		if (key == node->key) return node;
		else if (key < node->key)
			node = node->left;
		else
			node = node->right;
	}

	return NULL; // 탐색에 실패했을 경우 NULL 반환
}

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key){
	if (node == NULL) return new_node(key);
	
	if (key < node->key)
		node->left = insert_node(node->left, key);
	else if (key > node->key)
		node->right = insert_node(node->right, key);

	return node;
}



TreeNode* min_value_node(TreeNode* node)
{
	TreeNode* current = node;
	// 맨 왼쪽 단말 노드를 찾으러 내려감
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL)	return root;

	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		//삭제노드가 단말노드 or 하나의 서브트리
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}

		//삭제노드가 두개의 서브트리 보유
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}

	return root;
}



void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // 왼쪽서브트리 순회
		printf("[%d] ", root->key); // 노드 방문
		inorder(root->right); // 오른쪽서브트리 순회
	}
}

void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->key);
	}
}

int main(void) {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 38);
	root = insert_node(root, 20);
	root = insert_node(root, 40);
	root = insert_node(root, 10);
	root = insert_node(root, 34);
	root = insert_node(root, 12);
	root = insert_node(root, 50);
	root = insert_node(root, 45);
	root = insert_node(root, 60);
	root = insert_node(root, 66);

	printf("이진 탐색 트리 중위 순회 결과 \n");

	inorder(root);

	printf("\n\n");

	printf("이진 탐색 트리 후위 순회 결과 \n");

	postorder(root);

	return 0;
}