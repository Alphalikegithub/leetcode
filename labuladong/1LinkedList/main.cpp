#include <iostream>
#include <vector>

// 单链表节点
class ListNode {
public:
  ListNode(int x) : val(x), next(nullptr) {}
  ~ListNode() {}

public:
  int val;
  ListNode* next;
};

// 输入数组，创建单链表
ListNode* createLinkedList(const std::vector<int>& arr) {
  if (arr.empty()) return nullptr;

  ListNode* head = new ListNode(arr[0]);
  ListNode* cur = head;
  for (size_t i = 1; i < arr.size(); i++) {
    cur->next = new ListNode(arr[i]);
    cur = cur->next;
  }
  return head;
}

// 在链表头部插入节点
void insertAtHead(ListNode*& head, int val) {
  ListNode* newNode = new ListNode(val);
  newNode->next = head;
  head = newNode;
}

// 在链表尾部插入节点
void insertAtTail(ListNode* head, int val) {
  ListNode* p = head;
  while (p->next != nullptr) {
    p = p->next;
  }
  p->next = new ListNode(val);

#if 0
  // 在单链表尾部插入一个新节点 6(for循环)
  ListNode* p = head;
  for (; p->next != nullptr; p = p->next) {}  // 遍历到最后一个节点
  p->next = new ListNode(6);  // 插入新节点
#endif
}

// 在指定位置（0-based）后插入节点
void insertAfterPosition(ListNode* head, int pos, int val) {
  ListNode* p = head;
  //先要找到前驱节点，即第pos个节点
  for (int i = 0; i < pos && p != nullptr; i++) {
    p = p->next;
  }
  if (p == nullptr) return; // 位置超出链表长度，不插入

  ListNode* newNode = new ListNode(val);
  newNode->next = p->next;
  p->next = newNode;
}

//删除某个节点(先不考虑删除头节点）
void deleteSomeNode(ListNode* head, int pos)
{
  ListNode* p = head;
  //找到前驱节点
  for (int i = 0; i < pos - 1 && p != nullptr; i++)
  {
    p = p->next;
  }
  if (p == nullptr)
  {
    return;
  }
  p->next = p->next->next;
}

//删除头部节点
void deleteAtHead(ListNode*& head) {
  if (head == nullptr) return;  // 空链表，直接返回

  ListNode* toDelete = head;
  head = head->next;  // 更新 head
  delete toDelete;    // 释放内存
}

//删除尾部节点，不考虑链表只有一个节点的情况
void deleteAtTail(ListNode* head) {
  if (head == nullptr) return;  // 空链表，直接返回

  // 找到倒数第二个节点
  ListNode* p = head;
  while (p->next->next != nullptr) {
    p = p->next;
  }

  // 删除最后一个节点
  delete p->next;
  p->next = nullptr;
}
// 打印链表
void printLinkedList(ListNode* head) {
  for (ListNode* p = head; p != nullptr; p = p->next) {
    std::cout << p->val;
    if (p->next != nullptr) std::cout << "->";
  }
  std::cout << std::endl;
}

int main() {
  // 创建链表 1->2->3->4->5
  ListNode* head = createLinkedList({ 1, 2, 3, 4, 5 });

  // 在头部插入 0 → 0->1->2->3->4->5
  insertAtHead(head, 0);

  // 在尾部插入 6 → 0->1->2->3->4->5->6
  insertAtTail(head, 6);

  // 在第 3 个节点后插入 66 → 0->1->2->3->66->4->5->6
  insertAfterPosition(head, 3, 66);

  // 打印链表
  printLinkedList(head);

  //删除第三个节点
  deleteSomeNode(head, 3);

  // 打印链表
  printLinkedList(head);

  return 0;
}