#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct TreeNode{
  int val;
  TreeNode *left,*right;
  TreeNode(){
    left = right = NULL;
  }
};
//插入二叉搜索树
void insert(TreeNode *&node,int &key){
  if(node == NULL){
    node = new TreeNode;
    node->val = key;
    return;
  }
  else{
    if(key>node->val){
      insert(node->right,key);
    }
    else if(key<node->val){
      insert(node->left,key);
    }
  }
}
//先根遍历
void prt_tree(TreeNode *&root){
	if(root == NULL){
		return;
	}
	cout << root->val<<" ";
	prt_tree(root->left);
	prt_tree(root->right);
}
//查找
TreeNode *search(TreeNode *&node,int key){
  if(node!=NULL){
    if(node->val == key){
      return node;
    }
    else if(node->val > key){
      TreeNode *temp1 = search(node->left,key);
      if(temp1!=NULL){
        return temp1;
      }
    }
    else if(node->val < key){
      TreeNode *temp2 = search(node->right,key);
      if(temp2!=NULL){
        return temp2;
      }
    }
  }
  return NULL;
}
//寻找右树中的最小值
TreeNode *minVal_tree(TreeNode *&node){
  if(node == NULL){
    return NULL;
  }
  //如果左子树为空，就直接返回当前节点，因为右子树中不可能还有比key小的值
  if(node->left == NULL){
    return node;
  }
  //左右两树都为空，所以直接返回
  if(node->right == NULL && node->left == NULL){
    return node;
  }
  //如果以上条件都不满足，就往当前节点的左子树找
  return minVal_tree(node->left);
}
//删除一个元素
TreeNode *erase(TreeNode *&node,int key){
  if(node == NULL){
    return NULL;
  }
  //如果当前值小于key，说明要找的key在右子树
  if(key > node->val){
    //当前节点的右子树就等于删除key节点以后的右子树
    node->right = erase(node->right,key);
    return node;
  }
  else if(key < node->val){
    node->left = erase(node->left,key);
    return node;
  }
  else if(key == node->val){
    //如果左右子树都为NULL，就把当前节点删除，然后返回一个空节点
    if(node->left == NULL&&node->right == NULL){
      node = NULL;
      return NULL;
    }
    //如果左节点为空，右节点不为空，当前节点就等于它的右子树（删除掉了当前节点），然后返回删除后的子树
    else if(node->left == NULL&&node->right != NULL){
      node = node->right;
      return node;
    }
    else if(node->left != NULL&&node->right == NULL){
      node = node->left;
      return node;
    }
    //左右子树都不为空的时候
    else if(node->left!=NULL&&node->right!=NULL){
      //寻找左子树中最大的或右子树中最小的，这里是右子树中最小的
      //给当前节点赋值为右子树中最小的那个节点的值
      node->val = minVal_tree(node->right)->val;
      //当前节点的右节点等于删除最小节点后的子树，并返回
      node->right = erase(node->right,node->val);
      return node;
    }
  }
  return NULL;
}


int main(){
  TreeNode* root = new TreeNode();
  root = NULL;
  int nums[4] = {3,1,4,2};
  for(int i = 0;i<4;++i){
    insert(root,nums[i]);
  }
  prt_tree(root);
  cout << endl;
  TreeNode *temp = search(root,4);
  if(temp!=NULL){
    cout << temp->val;
  }
  cout << endl;
  erase(root,3);
  prt_tree(root);
  return 0;
}
