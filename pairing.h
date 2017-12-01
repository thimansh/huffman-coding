/*
 * pairing.h
 *
 *  Created on: Apr 2, 2017
 *      Author: Himanshu Taneja
 */
#ifndef PAIRING_H_
#define PAIRING_H_

#include <vector>
#include <cstddef>
#include "hnode.h"

class pnode
{
    public:
        hnode const *huff_node;
        pnode *leftChild;
        pnode *nextSibling;
        pnode *prev;
        pnode(hnode const* huff_node):
		huff_node(huff_node),
		leftChild(NULL),
		nextSibling(NULL),
		prev(NULL)
		{ }
};

class pairing
{
    private:
		long _heapsize;
        pnode *root;
        std::vector<pnode*> pnode_list;
        void reclaimMemory(pnode *t);
        void compareAndLink(pnode * &first, pnode *second);
        pnode *combineSiblings(pnode *firstSibling);

    public:
        pairing();
        pairing(std::vector<hnode const*> & numbers);
        ~pairing();
        bool isEmpty();
        bool isFull();
        pnode *Insert(hnode const* x);
        hnode const *find_Min();
        void delete_Min();
        void makeEmpty();
        void displayheap();
        long size();

};



#endif /* PAIRING_H_ */


