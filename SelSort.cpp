#include "SelSort.h"

void swapNode (List& L, Iterator it1, Iterator it2){
	if (it1 == L.end() || it2 == L.end())
		return;
	if (it1 == it2)
		return;
	Card val1 = *it1;
	Card val2 = *it2;
	*it1 = val2;
	*it2 = val1;

}

Iterator getMin (const List& L, Iterator pos) {
	Iterator minIter;
	Card lowValue = Card::getHighValue();
	for (Iterator cp = pos; cp!=L.end(); cp++) {
		if (lowValue > *cp){
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}

Iterator nPos(List& L, int n){
	Iterator cp;
	int count = 0;
	for (cp = L.begin(); cp!=L.end(); cp++) {
		if (count == n){
			break;
		}
		count ++;
	}
	return cp;
}

void SelSort::sort(List& L){
	int lsize = L.size();
	for (int i=0; i<lsize; ++i){
		for (int j=i; j<lsize; ++j){
			Iterator rest = nPos(L, j);
			Iterator minit = getMin(L, rest);
			swapNode(L, rest, minit);
		}
	}
}
