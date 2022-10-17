#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T>>
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
	std::vector<T> vh;
	int mTree;
	PComparator comp;
	void heapify(size_t idx);
};

// Add implementation of member functions here
  template<typename T, typename PComparator>
	Heap<T, PComparator>::Heap(int m, PComparator c){
		mTree = m;
		comp = c;
	}


	template<typename T, typename PComparator>
  Heap<T, PComparator>::~Heap(){}


	template<typename T, typename PComparator>
  bool Heap<T, PComparator>::empty() const{
		return vh.empty();
	}

	template<typename T, typename PComparator>
  size_t Heap<T, PComparator>::size() const{
		return vh.size();
	}


	template <typename T, typename PComparator>
	void Heap<T,PComparator>::push(const T& item){
		//if heap is empty, assign item as the first node
		if(empty()){
			vh.push_back(item);
			return;
		}
		else{
			//put item at first free location at bottom of free
			vh.push_back(item);
			//trickle up
			unsigned int loc = size() - 1;
			unsigned int parent = (loc - 1)/mTree;
			//swap parent and child while child is less than parent
			while(loc > 0 && comp(item, vh[parent])){
				//swap parent with child
				T temp = vh[loc];
				vh[loc] = vh[parent];
				vh[parent] = temp;
				loc = parent;
				parent = (loc - 1)/mTree;
			}
		}
	}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
		throw std::underflow_error("Heap is empty");
  }
	else{
		// If we get here we know the heap has at least 1 item
		// Add code to return the top element
		return vh[0];
	}

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is empty");
  }
	else{
		//take the last greatest node and put it to the top position
		vh[0] = vh[size() - 1];
		vh.pop_back();
		//call the heapify recursive function;
		heapify(0);
	}
}

//heapify recursively swaps the value until it's in the right place
template<typename T, typename PComparator>
void Heap<T,PComparator>::heapify(size_t idx){
	unsigned int leafNodes = idx * mTree + 1;
	//if node is a leaf node, do nothing
	if(leafNodes >= size()){
		return;
	}
	else{
		T useThisNode = vh[leafNodes];
		unsigned int nodeIndex = leafNodes;

		//iterate through child nodes and figure which is smallest
		for(unsigned int i = leafNodes; (i <= mTree * (idx + 1) && i < size()); i++){
			//if current node seems like the one to use
			if(comp(vh[i], useThisNode)){
				useThisNode = vh[i];
				nodeIndex = i;
			}
		}

		//recursively swap the nodes
		if(comp(useThisNode, vh[idx])){
			T temp = vh[idx];
			vh[idx] = useThisNode;
			vh[nodeIndex] = temp;
			heapify(nodeIndex);
		}
	}
}


#endif

