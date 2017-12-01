/*
 * binary.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: Himanshu Taneja
 */
#include "binary.h"

#include <iostream>
#include <algorithm>

int binary::size(){
	return _heap.size();
}

int binary::leftchild(int i){
	return 2*i+1;
}

int binary::rightchild(int i){
	return 2*i+2;
}

int binary::parent(int i){
	return (i-1)/2;
}

void binary::insert(hnode const* ele){

	_heap.push_back(ele);
	percolateup(_heap.size()-1);
}

void binary::delete_min(){
	int length=_heap.size()-1;
	if(length>=0){
		_heap[0]=_heap[length];
		_heap.pop_back();
		percolatedown(0);
	}
}

hnode const* binary::get_min(){
	if(_heap.size()==0){
		return NULL;
	}

	return _heap[0];
}

void binary::percolateup(int i){

	int pr=parent(i);
	if(i<_heap.size() && pr>=0 && (*_heap[i]< *_heap[pr])){
		std::swap(_heap[pr],_heap[i]);
		percolateup(pr);
	}
}

void binary::percolatedown(int i){

	int l=leftchild(i);
	int r=rightchild(i);
	int small=i;
	if(l<_heap.size() && (*(_heap[l])< *(_heap[small]))){
		small=l;
	}
	if(r<_heap.size() && (*(_heap[r]) < *(_heap[small]))){
		small=r;
	}

	if(small!=i){
		std::swap(_heap[i],_heap[small]);
		percolatedown(small);
	}

}

void binary::displayheap(){
	std::cout<<"Binary Heap [frequency: value]\n";
	for(hnode const* ele:_heap){
		std::cout<<"["<<ele->freq<<" : "<<ele->data<<"]\n";
	}
	std::cout<<std::endl;
}

binary::~binary(){
}

binary::binary(std::vector<hnode const*> &hnodes){
	for(hnode const * huff_node:hnodes){
		insert(huff_node);
	}
}






