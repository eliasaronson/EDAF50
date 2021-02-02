#include <iostream>
#include "list.h"


List::List() {
	first = nullptr;
}

List::~List() {
		while (first->next != nullptr) {
      Node *tmp = first;
      first = first->next;
      delete(tmp);
  	}
    delete(first);
}

bool List::exists(int d) const {
	Node *tmp = first;
	bool exsists = false;
	while (tmp->next != nullptr) {
		if (tmp->value == d) {
			exsists = true;
		}
		tmp = tmp->next;
	}
	return exsists;
}

int List::size() const {
	Node *tmp = first;
	int size = 0;
	size = 0;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
		size++;
	}
	delete(tmp);
	return size;
}

bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {
	Node *temp = new Node(d, first);
  first=temp;
}

void List::remove(int d, DeleteFlag df) {
        if (first == NULL){
                return;
        }
        switch(df) {
        case DeleteFlag::LESS:
                if (d < first->value){
                        Node* tmp = first->next;
                        delete first;
                        first = tmp;
                }else{
                        Node* tmp = first;
                        Node* tmp2 = first->next;
                        while (tmp2->next != nullptr){
                                tmp = tmp->next;
                                tmp2 = tmp2->next;
                                if (d > tmp2->value){
                                        tmp->next=tmp->next->next;
                                        delete tmp2;
                                        break;
                                }
                        }
                }
                break;
        case DeleteFlag::EQUAL:
                if (d == first->value){
                         Node* tmp = first->next;
                         delete first;
                         first = tmp;
                }else{
                        Node* tmp = first;
                        Node* tmp2 = first->next;
                        while (tmp2->next != nullptr){
                                tmp = tmp->next;
                                tmp2 = tmp2->next;
                                if (d == tmp2->value){
                                        tmp->next=tmp->next->next;
                                        delete tmp2;
                                        break;
                                }
                        }
                }
                break;
        case DeleteFlag::GREATER:
                if (d > first->value){
                         Node* tmp = first->next;
                         delete first;
                         first = tmp;
                 }else{
                        Node* tmp = first;
                        Node* tmp2 = first->next;
                        while (tmp2->next != nullptr){
                                tmp = tmp->next;
                                tmp2 = tmp2->next;
                                if (d > tmp2->value){
                                        tmp->next=tmp->next->next;
                                        delete tmp2;
                                        break;
                                }
                        }
                }
                break;
        }
}

void List::print() const {
	Node *temp = first;
  while(temp!=NULL){
    std::cout<<temp->value<<"\t";
    temp=temp->next;
  }
}
