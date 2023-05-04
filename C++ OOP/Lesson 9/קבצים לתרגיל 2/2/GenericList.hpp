#pragma once

#include <string>

/////////////////////////////////////////////
//       GenericNode Definition            //
//										   //
// Please note: the definitions and		   //
// implementations are on the same file    //
// because we use templates				   //
//										   //
/////////////////////////////////////////////

/* complete code here */
class GenericNode
{
public:
	GenericNode(/* complete code here */ item);

	// getters
	/* complete code here */ get_next() const;
	/* complete code here */ get_item();

	// setters
	void set_next(/* complete code here */ next);
	void set_item(/* complete code here */ new_item);

private:
	/* complete code here */ _item;
	GenericNode</* complete code here */>* _next;

};

/////////////////////////////////////////////
//       GenericList Definition            //
//										   //
// Please note: the definitions and		   //
// implementations are on the same file    //
// because we use templates				   //
//										   //
/////////////////////////////////////////////

/* complete code here */
class GenericList
{
public:
	GenericList();
	~GenericList();

	// getters

	/* complete code here */ get_first() const;

	// setters
	void set_first(/* complete code here */ first);

	// adds a Device object to the end of the list
	void add(/* complete code here */ device_to_add);

private:
	GenericNode</* complete code here */>* _first;
};

/////////////////////////////////////////////
//       GenericNode implementation        //
//										   //
// Please note: the definitions and		   //
// implementations are on the same file    //
// because we use templates				   //
//										   //
/////////////////////////////////////////////

template<class T>
GenericNode<T>::GenericNode(const T item)
{
	this->_item = item;
	this->_next = nullptr;
}

template<class T>
GenericNode<T>* GenericNode<T>::get_next() const
{
	return this->_next;
}

template<class T>
T& GenericNode<T>::get_item()
{
	return _item;
}

template<class T>
void GenericNode<T>::set_next(GenericNode<T>* next)
{
	this->_next = next;
}

template<class T>
void GenericNode<T>::set_item(const T new_item)
{
	this->_item = new_item;
}

/////////////////////////////////////////////
//       GenericList implementation        //
//										   //
// Please note: the definitions and		   //
// implementations are on the same file    //
// because we use templates				   //
//										   //
/////////////////////////////////////////////

template<class T>
inline GenericList<T>::GenericList()
{
	this->_first = nullptr;
}

template<class T>
inline GenericList<T>::~GenericList()
{
	GenericNode<T>* temp;
	while (this->_first != nullptr) // as long as the list is not empty
	{
		temp = this->_first;    // temp points to the first element
		this->_first = this->_first->get_next();   // the list now starts from the 2nd element
		delete temp;    // deletes the previous first element
	}
}

template<class T>
inline GenericNode<T>* GenericList<T>::get_first() const
{
	return this->_first;
}

template<class T>
inline void GenericList<T>::set_first(GenericNode<T>* first)
{
	this->_first = first;
}

template<class T>
inline void GenericList<T>::add(const T device_to_add)
{
	// create a new node to store the object
	GenericNode<T>* new_node = new GenericNode<T>(device_to_add);

	if (this->_first == nullptr) // list is empty
	{
		this->_first = new_node; // the new node is the first node
	}
	else        // list has at least one element
	{
		GenericNode<T>* curr = this->_first;      // start from first
		while (curr->get_next() != nullptr) // advance to the last element
		{
			curr = curr->get_next();
		}
		curr->set_next(new_node); // add the new node at the end of the list
	}
}


