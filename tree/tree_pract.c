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

	return NULL; // Ž���� �������� ��� NULL ��ȯ
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
	// �� ���� �ܸ� ��带 ã���� ������
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
		//������尡 �ܸ���� or �ϳ��� ����Ʈ��
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

		//������尡 �ΰ��� ����Ʈ�� ����
		TreeNode* temp = min_value_node(root->right);

		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}

	return root;
}



void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // ���ʼ���Ʈ�� ��ȸ
		printf("[%d] ", root->key); // ��� �湮
		inorder(root->right); // �����ʼ���Ʈ�� ��ȸ
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

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");

	inorder(root);

	printf("\n\n");

	printf("���� Ž�� Ʈ�� ���� ��ȸ ��� \n");

	postorder(root);

	return 0;
}