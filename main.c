#include"linkedlist.h"
#include<stdio.h>


int main() {
	printf("===链表管理器测试===\n");
	 
	LNode* head = NULL;

	//test1：尾插法
	printf("测试1：尾插法插入1，2，3，4，5\n");
	head = insertAtEnd(&head, 1);
	head = insertAtEnd(&head, 2);
	head = insertAtEnd(&head, 3);
	head = insertAtEnd(&head, 4);
	head = insertAtEnd(&head, 5);
	printf("当前链表状态为：");
	printList(head);
	//现在链表：1->2->3->4->5->NULL

	//text2 ：头插法
	printf("测试2：头插法插入6、7、8\n");
	head = insertAtHead(&head, 6);
	head = insertAtHead(&head, 7);
	head = insertAtHead(&head, 8);
	printf("当前链表状态为：");
	printList(head);
	//现在链表：8->7->6->1->2->3->4->5->NULL

	//text3 : 获取链表长度
	printf("测试3：获取链表长度\n");
	int length = getLength(head);
	printf("当前链表长度为%d\n",length);

	//text4:按值查找
	printf("测试4：按值查找\n");
	printf("请输入需要查找的数字：\n");
	int searchNum; 
	scanf("%d", &searchNum);
	LNode* result=searchNode(head, searchNum);
	if (result != NULL) 
		printf("“%d”查找成功！\n", result->val);
	else
		printf("查找失败！\n");
	
	//text5:删除节点
	printf("测试5：按值删除\n");
	printf("请输入需要删除的数字：\n");
	int deleteNum;
	scanf("%d", &deleteNum);
	deleteNode(&head, deleteNum);
	printf("当前链表状态为：");
	printList(head);

	//text6:反转链表
	printf("测试6：反转链表\n");
	reverseList(&head);
	printf("当前链表状态为：");
	printList(head);

	return 0;
}