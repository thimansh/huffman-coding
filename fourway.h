/*
 * fourway.h
 *
 *  Created on: Apr 2, 2017
 *      Author: Himanshu Taneja
 */
#ifndef FHEAP_H
#define FHEAP_H_

#include "hnode.h"
#include <vector>

class fourway{

	std::vector<hnode const*> 			_heap;

	void 								percolateup(int i);
	void 								percolatedown(int i);
	int 								smallestChild(int i);
	int 								kthChild(int i, int k);
	int 								parent(int i);

public:

										fourway();
										~fourway();
										fourway(std::vector<hnode const *> &numbers);
	void 								insert(hnode const* ele);
	hnode const* 						get_min();
	void 								delete_min();
	//void								heapify(vector<int> &a);
	size_t 								size();
	void								displayheap();

};
#endif /*FHEAP_H_*/




