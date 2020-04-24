#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode{
	char val;
	TreeNode* left,* right;
};
void create_tree(TreeNode* &root){
	char temp;
	cin >> temp;
	if(temp == '*'){
		root = NULL;
		return;
	}
	root = new TreeNode;
	root->val = temp;
	create_tree(root->left);
	create_tree(root->right);
}
//先根遍历
void prt_tree(TreeNode* &root){
	if(root == NULL){
		//cout << '*'<<" "<<endl;
		return;
	}
	cout << root->val<<" ";
	prt_tree(root->left);
	prt_tree(root->right);
}
//中根遍历
void prt_tree2(TreeNode* &root){
	if(root == NULL){
		return;
	}
	prt_tree(root->left);
	cout << root->val<<" ";
	prt_tree(root->right);
}
//后根遍历
void prt_tree3(TreeNode* &root){
	if(root == NULL){
		return;
	}
	prt_tree(root->left);
	prt_tree(root->right);
	cout << root->val<<" ";
}
//search,在二叉树中找一个key，找不到返回NULL，找到了返回节点
TreeNode* search(TreeNode* &root,char key){
	if(root != NULL){
		if(root->val == key){
			return root;
		}
		else{
			TreeNode* temp1 = search(root->left,key);
			if(temp1 != NULL&&temp1->val == key){
				return temp1;
			}
			TreeNode* temp2 = search(root->right,key);
			if(temp2 != NULL&&temp2->val == key){
				return temp2;
			}
		}
	}
	return NULL;
}

int main(){
	TreeNode* root;
	create_tree(root);
	prt_tree(root);
	cout << endl;
	TreeNode* temp = search(root,'6');
	if(temp!=NULL){
		cout << temp->val;
	}
	return 0;
}
