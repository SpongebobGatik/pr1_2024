#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "gtest/gtest.h"
using namespace std;

struct OneNode {
	int value;
	OneNode* next;
};

struct OneList {
	OneNode* head;
	OneNode* tail;
	OneList() : head(NULL), tail(NULL) {};
	~OneList() {
		while (head != NULL) {
			OneNode* temp = head;
			head = head->next;
			delete temp;
		}
	}
	void PrintList();
};

OneList* CreateOneList();
OneList* AddStart(OneList& list, int value);
OneList* AddEnd(OneList& list, int value);

#endif 
