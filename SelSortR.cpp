#include "SelSortR.h"

Iterator getMin (const List& L) {
	Iterator minIter;
	Card lowValue = Card::getHighValue();
	for (Iterator cp = L.begin(); cp!=L.end(); cp++) {
		if (lowValue > *cp){
			minIter = cp;
			lowValue = *cp;
		}
	}
	return minIter;
}

Card removeMin(List& L){
	Iterator minit = getMin(L);
	Card res = *minit;
	L.erase(minit);
	return res;
}

void SelSortR::sort(List& L){
	if (L.size() <= 1)
		return;
	Card minVal = removeMin(L);
	sort(L);
	L.push_front(minVal);
}
