#include <iostream>
#include <vector>
class DoublyListNode
{
public:
	DoublyListNode(int x)
		:val(x), next(NULL), prev(NULL)
	{

	}

public:
	int val;
	DoublyListNode* next, * prev;
	

};

DoublyListNode* createDoublyLinkedList(const std::vector<int>& arr)
{
	if (arr.empty())
	{
		return NULL;
	}
	DoublyListNode* head = new DoublyListNode(arr[0]);
	DoublyListNode* cur = head;
	//for循环迭代创建双链表
	for (int i = 1; i < arr.size(); i++)
	{
		DoublyListNode* newNode = new DoublyListNode(arr[i]);
		cur->next = newNode;
		newNode->prev = cur;
		cur = cur->next;
	}
	return head;
}

void print_arr(const DoublyListNode* head)
{
	//从头节点向后遍历双链表
	const DoublyListNode* p = head;
	while (p != nullptr)
	{
		std::cout << p->val ;
		if (p->next != nullptr)
		{
			std::cout << "->";
		}
		p = p->next;
	}
	std::cout << std::endl;
}

void print_arr1(const DoublyListNode* tail)
{
	//从尾节点向前遍历双链表
	for (const DoublyListNode* p = tail; p != nullptr; p = p->prev)
	{
		std::cout << p->val << " ";
	}

}

void insertAtHead(DoublyListNode*& head, int val)
{
	DoublyListNode* newHead = new DoublyListNode(val);
	newHead->next = head;
	head->prev = newHead;
	head = newHead;
}

void insertAtTail(DoublyListNode* head, int val)
{
	DoublyListNode* tail = head;
	//先走到链表的最后一个节点
	while (tail->next != nullptr)
	{
		tail = tail->next;
	}

	//在双链表尾部插入新节点
	DoublyListNode* newNode = new DoublyListNode(val);
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
}

void insertAt(DoublyListNode*& head, DoublyListNode*& tail, int index, int value) {
	DoublyListNode* newNode = new DoublyListNode(value);

	// 情况 1：链表为空，直接插入
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		return;
	}

	// 情况 2：插入在头部（index = 0）
	if (index == 0) {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
		return;
	}

	// 遍历到第 index-1 个节点
	DoublyListNode* current = head;
	for (int i = 0; i < index - 1 && current != nullptr; i++) {
		current = current->next;
	}

	// 情况 3：插入位置超出链表长度，默认插入到尾部
	if (current == nullptr || current->next == nullptr) {
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		return;
	}

	// 情况 4：正常情况（插入在中间）
	/*DoublyListNode* nextNode = current->next;保留了原后续节点的指针，避免丢失
	current->next = newNode;
	newNode->prev = current;
	newNode->next = nextNode;
	nextNode->prev = newNode;*/


	//组装新节点
	newNode->next = current->next;// 先设置新节点的 next
	newNode->prev = current;			// 再设置新节点的 prev
	//插入新节点
	current->next->prev = newNode;// 修改 nextNode 的 prev
	current->next = newNode;			// 最后修改 current 的 next
}

void insertAfterPosition(DoublyListNode* head, int pos, int val)
{

}

//删除值为 value 的节点
void deleteNode(DoublyListNode*& head, DoublyListNode*& tail, int value) {
	if (head == nullptr) {
		return; // 空链表，直接返回
	}

	DoublyListNode* current = head;

	// 遍历查找值为 value 的节点
	while (current != nullptr && current->val != value) {
		current = current->next;
	}

	// 未找到节点
	if (current == nullptr) {
		return;
	}

	// 情况 1：删除头节点
	if (current == head) {
		head = head->next;
		if (head != nullptr) {
			head->prev = nullptr; // 新头节点的 prev 置空
		}
		else {
			tail = nullptr; // 链表为空，尾指针也置空
		}
	}
	// 情况 2：删除尾节点
	else if (current == tail) {
		tail = tail->prev;
		tail->next = nullptr;
	}
	// 情况 3：删除中间节点
	else {
		current->prev->next = current->next;
		current->next->prev = current->prev;
	}

	delete current; // 释放内存
}

//不考虑头尾特殊情况
void deleteNodeAt(DoublyListNode*& head, DoublyListNode*& tail, int index)
{
	if (head == nullptr || index < 0)
	{
		return;
	}

	DoublyListNode* current = head;
	for(int i = 0; i < index - 1; i++)
	{
		current = current->next;
	}

	if (current == nullptr || current->next == nullptr || current->next->next == nullptr)
	{
		return;//超出范围
	}
	DoublyListNode* toDelete = current->next; // 要删除的节点
	// 调整指针
	current->next = toDelete->next;
	toDelete->next->prev = current;

	delete toDelete; // 释放正确的节点
}
int main()
{
	DoublyListNode* head =  createDoublyLinkedList({ 2,3,4,5,6 });
	DoublyListNode* tail = nullptr;
	print_arr(head);

	insertAtHead(head, 1);
	print_arr(head);

	insertAtTail(head, 7);
	print_arr(head);

	insertAt(head, tail, 3, 66);
	print_arr(head);

	deleteNodeAt(head, tail, 3);
	print_arr(head);
	return 0;
}