/*
 * main.cpp
 *
 *  Created on: 2017. 5. 1.
 *      Author: cskim
 */
#include <string>
#include <iostream>
#include <cassert>

#include "List.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelSort.h"
#include "SelSortR.h"

using namespace std;

const int  LINE_MAX = 13;

void printList(List& L)
{
	int i = 0;
	for (Iterator cp = L.begin(); cp!=L.end(); cp.next()) {
		cout << cp.get() << " ";
		i++;
		if (i % LINE_MAX == 0) cout << endl;
	}
	cout << endl;
}
void sortTest(ListSort& sorter ){
	List deck;

	// Make a Card Deck
	for (int s=CLUB; s<=SPADE; s++)
		for (int r=ACE; r<=KING; r++){
			deck.push_back(Card(s,r));
		}
	// Display the Deck
	printList(deck);
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();
	cout << endl;

	sorter.sort(deck);

	printList(deck);
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();
	cout << endl;
}
int main()
{
	cout << "Merge Sort" << endl;
	MergeSort msort;
	sortTest(msort);
	cout << endl;

	cout << "Quick Sort" << endl;
	QuickSort qsort;
	sortTest(qsort);
	cout << endl;

	cout << "Selection Sort" << endl;
	SelSort ssort;
	sortTest(ssort);
	cout << endl;

	cout << "Selection Sort using Recursive function" << endl;
	SelSortR ssortr;
	sortTest(ssortr);

	cout << endl;
	cout << "Node Cur Count = " << Node::getCurCount();
	cout << endl;
	cout << "Node Max Count = " << Node::getMaxCount();

	return 0;
}





