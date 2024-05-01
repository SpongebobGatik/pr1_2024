#include "list.h"

void OneList::PrintList() {
	OneNode* item = head;
	while (item != NULL) {
		cout << item->value << endl;
		item = item->next;
	}
}

OneList* CreateOneList() {
	OneList list;
	return &list;
}

OneList* AddStart(OneList& list, int value) {
	auto NewNode = new OneNode{ value };
	if (list.head == NULL) {
		list.head = NewNode;
		list.tail = NewNode;
		return &list;
	}
	NewNode->next = list.head;
	list.head = NewNode;
	return &list;
}

OneList* AddEnd(OneList& list, int value) {
	auto NewNode = new OneNode{ value };
	if (list.head == NULL) {
		list.head = NewNode;
		list.tail = NewNode;
		return &list;
	}
	list.tail->next = NewNode;
	list.tail = NewNode;
	return &list;
}

OneList* RemoveFirst(OneList& list) {
	if (list.head == NULL) {
		return &list;
	}
	OneNode* temp = list.head;
	list.head = list.head->next;
	delete temp;
	return &list;
}

OneList* RemoveValue(OneList& list, int value) {
	OneNode* current = list.head;
	OneNode* prev = NULL;
	while (current != NULL) {
		if (current->value == value) {
			if (prev == NULL) {
				list.head = current->next;
			}
			else {
				prev->next = current->next;
			}
			OneNode* temp = current;
			current = current->next;
			delete temp;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	return &list;
}

TEST(TestOneList, TestRemoveFirstNode) {
	OneList list = *CreateOneList();
	list = *AddStart(list, 1);
	list = *AddStart(list, 2);
	list = *AddStart(list, 3);
	list = *AddEnd(list, 4);
	EXPECT_EQ(list.head->value, 3);
	list = *RemoveFirst(list);
	EXPECT_EQ(list.head->value, 2);
}

TEST(TestOneList, TestRemoveValue) {
	OneList list = *CreateOneList();
	list = *AddStart(list, 1);
	list = *AddStart(list, 2);
	list = *AddStart(list, 3);
	list = *AddStart(list, 2);
	list = *AddStart(list, 2);
	list = *AddStart(list, 2);
	list = *AddEnd(list, 4);
	list = *RemoveValue(list, 2);
	OneNode* item = list.head;
	while (item != NULL) {
		EXPECT_NE(item->value, 2);
		item = item->next;
	}
}