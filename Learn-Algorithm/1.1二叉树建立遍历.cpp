#include<stdlib.h>
#include<stdio.h>
#include<queue>
using namespace std;
struct BitNode{
	BitNode *lchild;
	BitNode *rchild;
	char value;
};

queue<BitNode*> Q;

BitNode* createBittree(BitNode* T){

	char nodeValue ;
	scanf("%c",&nodeValue);
	if(nodeValue == '#'){
		T = NULL;
	}else{
		T = (BitNode*)malloc(sizeof(BitNode));
		T->value = nodeValue ;
		T->lchild=createBittree(T->lchild);
		T->rchild=createBittree(T->rchild);
	}
	return T;
}

void preTree(BitNode* T){
	if(T){
		printf("%c ",T->value);
		preTree(T->lchild);
		preTree(T->rchild);
	}
}

void midTree(BitNode* T){
	if(T){
		midTree(T->lchild);
		printf("%c ",T->value);
		midTree(T->rchild);
	}
}

void lastTree(BitNode* T){
	if(T){
		lastTree(T->lchild);
		lastTree(T->rchild);
		printf("%c ",T->value);
	}
}

void travelTree(BitNode* T){
	BitNode* treeNode;
	//clear the queue
	while(!Q.empty()){
		Q.pop();
	}
	if(T){
		Q.push(T);
	}
	if(Q.empty()){
		printf("A empty tree\n");
	}else{
		while(!Q.empty()){
			treeNode = Q.front();
			Q.pop();
			printf("%c ",treeNode->value);
			if(treeNode->lchild)
				Q.push(treeNode->lchild);
			if(treeNode->rchild)
				Q.push(treeNode->rchild);
		}
	}
}
//input a string of char contains empty and end with '/n'
int main(int argc, char const *argv[])
{
	BitNode *root =NULL;

	printf("输入二叉树字符，#表示空节点\n");
	root = createBittree(root);

	printf("输出层序遍历:");
	travelTree(root);
	printf("\n输出先序遍历:");
	preTree(root);
	printf("\n输出中序遍历:");
	midTree(root);
	printf("\n输出后序遍历:");
	lastTree(root);
	printf("\n");

	
	return 0;
}
/*
TEST: AB#C##D##
预期结果：
		层序：ABDC
		先序：ABCD
		中序：BCAD
		后序：CBDA
*/