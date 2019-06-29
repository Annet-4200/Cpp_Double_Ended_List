// 2SLab5.cpp: определяет точку входа для консольного приложения.
//Агеева Анна, ПЗ-17-1, 3 вариант

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Train {
	int number, kupe, plats, genaral;
};

struct List {
	Train info;
	List *next;
	List *prev;
} * head = NULL, *tail = NULL;

void Add(List *temp, Train elem) {
		List * newElem = new List;
		newElem->info = elem;
		tail = newElem;
		temp = head;
	if (temp != NULL) {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newElem;
		newElem->prev = temp;
		newElem->next = NULL;
	}
	else {
		head = newElem;
		tail = newElem;
		newElem->prev = NULL;
		newElem->next = NULL;
	}
}

void PrintFreeSpots(List * &temp, int num) {
	bool flag = false;
	List * current = temp;
	List * temp2 = head;
	int elements = 0;
	while (temp2 != NULL) {
		temp2 = temp2->next;
		elements++;
	}
	if (temp != NULL) {
		int counter = 1;
		while (current != NULL) {
			if (current->info.number == num) {
				cout << "Kupe: " << current->info.kupe << "\nPlatskart: " << current->info.plats 
					<< "\nGeneral train: " << current->info.genaral << endl;
				flag = true;
				if (counter == 1) {
					temp = current->next;
				}
				else if (counter == 1 && counter == elements) {
					current = NULL;
				}
				else if (counter == elements) {
					current->prev->next = NULL;
				}
				else {
					current->prev->next = current->next;
					current->next->prev = current->prev;
				}
				delete current;
				break;
			}
			counter++;
			current = current->next;
		}
		if (flag == false) cout << "There is no train with this number! Please, choose another." << endl;
	}
	else cout << "The list is empty!"<<endl;
}

void DeteleList(List * temp) {
	List * current = temp->next;
	List * nextptr;
	while (current->next!= NULL) {
		nextptr = current->next;
		delete[] current;
		current = nextptr;
		delete[] current;
	}
}

int main()
{
	List * temp = head;
	Train elem;
	int k;
	cout << "Enter number of the train and free spots on: kupe, platskart and general train" << endl;
	cout << "Enter count of trains: " << endl;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> elem.number >> elem.kupe >> elem.plats >> elem.genaral;
		Add(temp, elem);
	}
	int num;
	cout << "Enter the number of train where you want to know about free spots:";
	while (1) {
		cin >> num;
		PrintFreeSpots(head,num);
	}
	DeteleList(head);
	system("pause");
    return 0;
}

