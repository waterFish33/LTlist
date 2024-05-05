#include "LTlist.h"

ListNode* ListBuyNode(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	return newnode;
}
// 创建返回链表的头结点.
ListNode* ListCreate() {
	ListNode* newnode = ListBuyNode(-1);
	newnode->_next = newnode;
	newnode->_prev = newnode;
	return newnode;

}
// 双向链表销毁
void ListDestory(ListNode* pHead) {
	ListNode* cur = pHead->_next;
	while (cur != pHead) {
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
// 双向链表打印
void ListPrint(ListNode* pHead) {
	ListNode* cur = pHead->_next;
	while (cur != pHead) {
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
}
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x) {
	ListInsert(pHead , x);
}
// 双向链表尾删
void ListPopBack(ListNode* pHead) {
	ListErase(pHead->_prev);
}
// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x) {
	ListInsert(pHead->_next, x);
}
// 双向链表头删
void ListPopFront(ListNode* pHead) {
	ListErase(pHead->_next);
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x) {
	ListNode* cur = pHead->_next;
	while (cur != pHead) {
		if (cur->_data == x) {
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* newnode = ListBuyNode(x);
	ListNode* pre = pos->_prev;
	pre->_next = newnode;
	newnode->_next = pos;
	pos->_prev = newnode;
	newnode->_prev = pre;

}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos) {
	assert(!(pos->_next == pos));

	ListNode* pre = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	pre->_next = next;
	next->_prev = pre;
}
