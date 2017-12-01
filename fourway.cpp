/*
 * fourway.cpp
 *
 *  Created on: Apr 2, 2017
 *      Author: Himanshu Taneja
 */
#include "fourway.h"

#include <iostream>
#include <algorithm>

int fourway::kthChild(int i, int k){
		return (4 * (i-2) + (k-1));
}

int fourway::parent(int i){

	return i/4+2;
}

void fourway::percolateup(int i){

    hnode const* tmp = _heap[i];
    for (; i > 3 && *tmp < *(_heap[parent(i)]); i = parent(i))
        _heap[i] = _heap[parent(i)];
    _heap[i] = tmp;
}


int fourway::smallestChild(int i)
{
    int smallest_child = kthChild(i, 1);
    int k = 2;
    int candidate_child = kthChild(i, k);
    while ((k <= 4) && (candidate_child < _heap.size()))
    {
        if (*(_heap[candidate_child]) < *(_heap[smallest_child]))
        	smallest_child = candidate_child;
        k++;
        candidate_child = kthChild(i, k);
    }
    return smallest_child;
}

void fourway::percolatedown(int i){

	int ch;
	hnode const* tmp = _heap[i];
	for ( ; kthChild(i, 1) < _heap.size(); i = ch)
	{
		ch = smallestChild( i );
		if (*(_heap[ch]) < *tmp)
			_heap[i] = _heap[ch];
		else
			break;
	}
	_heap[i] = tmp;

}

void fourway::insert(hnode const* ele){

	_heap.push_back(ele);
	percolateup(_heap.size()-1);
}

void fourway::delete_min(){
	int length=_heap.size()-1;
	if(length >=3){
		_heap[3]=_heap[length];
		_heap.pop_back();
		percolatedown(3);
	}
}

hnode const* fourway::get_min(){
	if(_heap.size()==3){
		return NULL;
	}

	return _heap[3];
}

void fourway::displayheap(){
	std::cout<<"4 way heap [frequency: value]\n";
	for(hnode const* ele:_heap){
		if(ele){
			std::cout<<"["<<ele->freq<<" : "<<ele->data<<"]\n";
		}
	}
	std::cout<<std::endl;
}

size_t fourway::size(){
	return _heap.size();
}

fourway::fourway(std::vector<hnode const*> &hnodes){
	//insert 3 dummy values
	for(int i=0;i<3;i++){
		insert(NULL);
	}

	for(hnode const * huff_node:hnodes){
		insert(huff_node);
	}
}

fourway::~fourway(){
}




