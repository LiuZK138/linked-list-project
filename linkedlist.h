#pragma once
//定义数据结构
typedef struct ListNode {
	int val;
	struct ListNode* next;
}LNode;
//基础操作
LNode* createNode(int val);//创建
LNode* insertAtEnd(LNode** head, int val);//尾插
LNode* insertAtHead(LNode** head, int val);//头插
void printList(LNode* head);//打印链表
int getLength(LNode* head);//获取长度

LNode* searchNode(LNode* head, int value);//查找
void deleteNode(LNode** head, int value);//删除
void reverseList(LNode** head);//反转