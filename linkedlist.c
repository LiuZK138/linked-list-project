#include"linkedlist.h"
#include<stdio.h>
#include<stdlib.h>


//创建
LNode* createNode(int val) {
	//动态分配内存
	LNode* newNode = (LNode*)malloc(sizeof(LNode));
	//检查内存是否成功分配
	if (newNode == NULL) {
		printf("错误：内存分配失败！\n");
		return NULL;
	}
	//初始化节点
	newNode->val = val;
	newNode->next = NULL;

	return newNode;
}


//尾插
LNode* insertAtEnd(LNode** head, int val) {
	//创建新节点
	LNode* newNode = createNode(val);
	if (newNode == NULL) {
		return *head;//创建失败，返回原链表
	}

	//如果原链表为空，则新节点为头节点
	if (*head == NULL) {
		return newNode;
	}

	//找到链表末尾
	LNode* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}

	//链接新节点
	current->next= newNode;
	return *head;//头节点没变
}


//头插
LNode* insertAtHead(LNode** head, int val) {
	//创建新节点
	LNode* newNode = createNode(val);
	if (newNode == NULL) {
		return *head;//创建失败，返回原链表
	}

	newNode->next = *head;//新节点指向原头节点
	*head = newNode;
	return *head;//新节点成为头节点
}

//打印链表
void printList(LNode* head) {
	LNode* current = head;
	while (current != NULL) {
		printf("%d ->", current-> val);
		current = current-> next;
	}
	printf("NULL\n");
}

//获取链表长度
int getLength(LNode* head) {
	int count = 0;
	LNode* current = head;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

//查找
LNode* searchNode(LNode* head, int value) {
	LNode* current = head;
	while (current != NULL) {
		if (current->val == value)
			return current;
		else
		current = current->next;
	}
	return NULL;
}

//删除对应节点
void deleteNode(LNode** head, int value) {
	//处理空链表
	if (*head == NULL) return;
	//处理头节点
	if ((*head)->val == value) {
		LNode* temp = *head;
		*head = (*head)->next;
		free(temp);
		return ;
	}
	//处理非头节点
	LNode* current = *head;
	while (current->next != NULL) {
		if (current->next->val == value) {
			LNode* temp = current->next;
			current->next = temp->next;
			free(temp);
			return;
		}
		current = current->next;
	}
}

//反转
void reverseList(LNode** head) {
	LNode* prev = NULL;
	LNode* current = *head;
	LNode* next = NULL;
	while (current != NULL) {
		next = current->next;//保存下一个节点
		current->next = prev;//反转当前节点指向
		prev = current;//prev前移
		current = next;//current前移
	}
	*head = prev;//更换头节点
}