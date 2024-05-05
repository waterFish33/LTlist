#include "LTlist.h"

ListNode* ListBuyNode(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	return newnode;
}
// �������������ͷ���.
ListNode* ListCreate() {
	ListNode* newnode = ListBuyNode(-1);
	newnode->_next = newnode;
	newnode->_prev = newnode;
	return newnode;

}
// ˫����������
void ListDestory(ListNode* pHead) {
	ListNode* cur = pHead->_next;
	while (cur != pHead) {
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(pHead);
}
// ˫�������ӡ
void ListPrint(ListNode* pHead) {
	ListNode* cur = pHead->_next;
	while (cur != pHead) {
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x) {
	ListInsert(pHead , x);
}
// ˫������βɾ
void ListPopBack(ListNode* pHead) {
	ListErase(pHead->_prev);
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x) {
	ListInsert(pHead->_next, x);
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead) {
	ListErase(pHead->_next);
}
// ˫���������
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
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x) {
	ListNode* newnode = ListBuyNode(x);
	ListNode* pre = pos->_prev;
	pre->_next = newnode;
	newnode->_next = pos;
	pos->_prev = newnode;
	newnode->_prev = pre;

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos) {
	assert(!(pos->_next == pos));

	ListNode* pre = pos->_prev;
	ListNode* next = pos->_next;
	free(pos);
	pre->_next = next;
	next->_prev = pre;
}
