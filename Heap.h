#include "Queue.h"
#include <utility>

//This should be the initial arrSize
#define START_SIZE 10

/*
 * This is a priority queue, which means that as items are removed in order
 * of decreasing priority.
 *
 * 
 */
template<class Pri, class T>
class Heap : public Queue<std::pair<Pri, T> > {
public:
  Heap();
  ~Heap();

  //Add a new item
  virtual void add(std::pair<Pri,T> toAdd);

  //Remove the item with lowest priority, and return it
  //If the queue is empty, throw a string exception
  virtual std::pair<Pri,T> remove();

  //Return the number of items currently in the queue
  virtual unsigned long getNumItems();

private:
  int arrSize;
  int numItems;
  std::pair<Pri, T>* backingArray;

  //Grow the backingArray by making a new array of twice the size,
  // and copying over the data
  void grow();

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it up the "tree" of the heap until you find the right
  // place
  void bubbleUp(unsigned long index);

  //Check the item at index, and make sure it is in the right place.
  // If not, swap it down the "tree" of the heap until you find the right
  // place
  void trickleDown(unsigned long index);  
};

/**
* Authored By: Chris Dieter with template from Dr. Brinkman.
* Help for the trickledown and remove functions were garnered 
* from the textbook, Open Data Structures.
* 11/11/2014
*/
#include <string>

template<class Pri, class T>
Heap<Pri,T>::Heap(){
	numItems = 0;
	arrSize = START_SIZE;
	backingArray = new std::pair<Pri, T>[arrSize];
}

template<class Pri, class T>
Heap<Pri,T>::~Heap(){
	delete[] backingArray;
}

template<class Pri, class T>
void Heap<Pri,T>::grow(){
	arrSize = 2 * arrSize;
	std::pair<Pri, T>* u = new std::pair<Pri, T>[arrSize];

	for(int i = 0; i < numItems; i++){
		u[i] = backingArray[i];
	}

	delete[] backingArray;
	backingArray = u;

}

template<class Pri, class T>
void Heap<Pri,T>::add(std::pair<Pri,T> toAdd){
	if(numItems + 1 > arrSize)
		grow();
	backingArray[numItems] = toAdd;
	bubbleUp(numItems);
	numItems++;
}

template<class Pri, class T>
void Heap<Pri,T>::bubbleUp(unsigned long index){
	unsigned long int parent = (index - 1)/2;

	std::pair<Pri, T> temp;
	if(index > 0 && backingArray[index].first < backingArray[parent].first){
		backingArray[parent].swap(backingArray[index]);
		bubbleUp(parent);
	}
}

template<class Pri, class T>
void Heap<Pri,T>::trickleDown(unsigned long index){
	
	bool check;
	do{
		check = false;
		unsigned long int rChild = (2 * index) + 2;
		unsigned long int lChild = (2 * index) + 1;

		if(rChild < numItems && backingArray[index].first > backingArray[rChild].first){
			if(backingArray[lChild].first < backingArray[rChild].first){
				swap(backingArray[index], backingArray[lChild]);
				index = lChild;
				check = true;
			} else{
				swap(backingArray[index], backingArray[rChild]);
				index = rChild;
				check = true;
			}
		} else{
			if(lChild < numItems && backingArray[index].first > backingArray[lChild].first){
				swap(backingArray[index], backingArray[lChild]);
				index = lChild;
				check = true;
			} 
			// Final case where one cannot trickle down anymore. Do not forget or infinite loop results
			else{
				check = true;
			}
		}
	}while(check == false);
}

template<class Pri, class T>
std::pair<Pri,T> Heap<Pri,T>::remove(){
	if(numItems < 1){
		throw std::string("No items to remove!");
	}
	std::pair<Pri, T> retVal = backingArray[0];
	backingArray[0] = backingArray[--numItems];
	trickleDown(0);
	return retVal;
}

template<class Pri, class T>
unsigned long Heap<Pri,T>::getNumItems(){
	return numItems;
}

