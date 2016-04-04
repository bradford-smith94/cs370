/*******************************************************************************
 * Name        : median.c
 * Author      : Bradford Smith, Justin Tsang, and Keyur Ved
 * Version     : 1.0
 * Date        : 4/4/2016
 * Description : Find median after every input of integer
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// Struct of Heap
typedef struct heapArr {
	unsigned int size_;
	long* heap_;
} Heap;

/* pre:    takes in a long 'lim'
 * post:   allocates a new Heap* of size 'lim'
 * return: a pointer to a Heap that has been newly allocated with size 'lim'
 */
Heap* initHeap(long size) {
	Heap* h = (Heap *)calloc(1, sizeof(Heap));
	h->heap_ = (long *)calloc(ceil(size / 2) + 1, sizeof(long));
    return h;
}

/* pre:  takes in a Heap* 'heap', unsigned int 'child', and unsigned int 'parent'
 * 		 'heap' should be a valid Heap* and 'child' and 'parent' should be between
 *		 zero and the size of the heap
 * post: swaps the values in 'heap' at indexes 'child' and 'parent'
 */
void swap(Heap* heap, unsigned int child, unsigned int parent) {
	long temp = heap->heap_[parent];
	heap->heap_[parent] = heap->heap_[child];
	heap->heap_[child] = temp;
}

/* pre:    takes in a Heap* 'heap', unsigned int 'index' and an int 'isMaxHeap'
 * 		   'heap' should be a valid Heap* and 'index' should be between zero and
 * 		   the size of the heap, 'isMaxHeap' should be either 0 or 1
 * post:   shifts up when adding a new node to 'heap'
 * return: an integer that is the index of the parent element of the heap, or
 * 		   zero on error
 */
int shiftUp(Heap* heap, unsigned int index, int isMaxHeap) {
	// If not root
	if (index > 0) {
		unsigned int parent = (index - 1) / 2;
		// If heap is min heap
		if (!isMaxHeap) {
			// If child < parent, swap
		  	if (heap->heap_[index] < heap->heap_[parent]) {
		    	swap(heap, index, parent);
		    	return parent;
		  	}
		// If heap is max heap
		} else {
			// If child is greater than parent, swap
			if (heap->heap_[index] > heap->heap_[parent]) {
				swap(heap, index, parent);
				return parent;
			}
		}
	}
	return 0;
}

/* pre:    takes in a Heap* 'heap', unsigned int 'index' and an int 'isMaxHeap'
 * 		   'heap' should be a valid Heap* and 'index' should be between zero and
 * 		   the size of the heap, 'isMaxHeap' should be either 0 or 1
 * post:   shift down when removing root and switching last node to root
 * return: an integer that is the index of ..., or zero on error
 */
int shiftDown(Heap* heap, unsigned int index, int isMaxHeap) {
	// If node at index has at least one child
	if (index < heap->size_ / 2) {
		unsigned int lc = 2 * index + 1;
		// If is min heap
		if (!isMaxHeap) {
			// Change value of lc if right child < left child
		  	if ((lc + 1 < heap->size_) && (heap->heap_[lc + 1] < heap->heap_[lc])) {
		  		++lc;
		  	}
		  	// Swap child and parent if child < parent
		  	if (heap->heap_[index] > heap->heap_[lc]) {
		    	swap(heap, index, lc);
		    	return lc;
		  	}
		// If is max heap
		} else {
			// Change value of lc if right child is > left child
			if ((lc + 1 < heap->size_) && (heap->heap_[lc + 1] > heap->heap_[lc])) {
		  		++lc;
		  	}
		  	// If child is greater than parent, swap
		  	if (heap->heap_[index] < heap->heap_[lc]) {
		    	swap(heap, index, lc);
		    	return lc;
		  	}
		}
	}
  	return 0;
}

/* pre:  takes in a Heap* 'heap', a long 'nodeVal' and an int 'isMaxHeap'
 * 		 'heap' should be a valid Heap* and 'isMaxHeap' should be either 0 or 1
 * post: add 'nodeVal' to 'heap' and shift up if necessary
 */
void addHeap(Heap* heap, long nodeVal, int isMaxHeap) {
	unsigned int index = heap->size_;
	// Set node to last index in heap
	heap->heap_[heap->size_++] = nodeVal;
	// While node added can be shifted up in the heap
	while ((index = shiftUp(heap, index, isMaxHeap)) != 0) {}
}

/* pre:  takes in a Heap* 'fromHeap', a Heap* 'toHeap' and an int 'isMaxHeap'
 * post: removes the root from 'fromHeap' and adds it to 'toHeap'
 */
void removeHeap(Heap* fromHeap, Heap* toHeap, int isMaxHeap) {
	// Add the value at root to other heap
	addHeap(toHeap, fromHeap->heap_[0], !isMaxHeap);
	// Set root of origin heap to last node in respective heap
	fromHeap->heap_[0] = fromHeap->heap_[--fromHeap->size_];
	unsigned int index = 0;
	// Shift down while node at index can be shifted
	while ((index = shiftDown(fromHeap, index, isMaxHeap)) != 0) {}
}

/* pre:  takes in a Heap* 'minHeap' and a Heap* 'maxHeap'
 * post: frees memory associated with 'minHeap' and 'maxHeap'
 */
void clearMemmory(Heap* minHeap, Heap* maxHeap) {
	free(minHeap->heap_);
	free(maxHeap->heap_);
	free(minHeap);
	free(maxHeap);
	minHeap = NULL;
	maxHeap = NULL;
}

/* pre:    none
 * post:   runs the main method to solve HackerRank Find Median
 * return: 0 always
 */
int main() {
	long numInputs = 0;
	scanf("%li", &numInputs);
	if (numInputs >= 1 && numInputs <= 100000) {
		Heap* minHeap = initHeap(numInputs);
		Heap* maxHeap = initHeap(numInputs);
		// Allow input while numInput > 0
		while (numInputs > 0) {
			long nodeValue;
			scanf("%li", &nodeValue);
			if (nodeValue >= 0 && nodeValue <= 100000) {
				// If current input is greater than root at minHeap
				if (nodeValue > minHeap->heap_[0]) {
					addHeap(minHeap, nodeValue, 0);
				} else {
					addHeap(maxHeap, nodeValue, 1);
				}
				// Adjust the difference in size > 1 of heaps
				int diff = minHeap->size_ - maxHeap->size_;
				// If minHeap heap has more nodes than maxHeap heap by > 1
				if (diff > 1) {
					removeHeap(minHeap, maxHeap, 0);
				// If maxHeap heap has more nodes than mion heap by > 1
				} else if (diff < -1) {
					removeHeap(maxHeap, minHeap, 1);
				}
				// Print median
				diff = minHeap->size_ - maxHeap->size_;
				// If even number of inputs
				if (diff == 0) {
					printf("%.1f\n", (float)(minHeap->heap_[0] + maxHeap->heap_[0]) / 2);
				} else {
					// If max heap has more nodes
					if (diff <= -1) {
						printf("%li\n", maxHeap->heap_[0]);
					// If min heap has more nodes
					} else {
						printf("%li\n", minHeap->heap_[0]);
					}
				}
			}
			--numInputs;
		}
		// Free memory in heap
		clearMemmory(minHeap, maxHeap);
	}
	return 0;
}
