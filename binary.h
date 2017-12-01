/*
 * binary.h
 *
 *  Created on: Apr 1, 2017
 *      Author: Himanshu Taneja
 */
#ifndef BINARY_H_
#define BINARY_H_

#include "hnode.h"
#include <vector>

class binary{

	std::vector<hnode const*> 			_heap;

	void 								percolateup(int i);
	void 								percolatedown(int i);
	int 								leftchild(int i);
	int 								rightchild(int i);
	int 								parent(int i);

public:

										binary();
										~binary();
										binary(std::vector<hnode const *> &numbers);
	void 								insert(hnode const* ele);
	hnode const* 						get_min();
	void 								delete_min();
	int 								size();
	void								displayheap();

};

#endif /* BINARY_H_ */
