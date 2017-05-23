#pragma once
#include <assert.h>

template<typename T>
class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(unsigned int a_capacity);
	~DynamicArray();

	void			PushBack(const T a_value);
	void			Insert(const T a_value, unsigned int a_index);
	void			Remove(unsigned int a_index);
    int				Find(const T a_value) const;
	void			Resize(unsigned int a_newCapacity);
	unsigned int	GetSize() const;
	unsigned int	GetCapacity() const;

	
	T& operator[](unsigned int index);
private:
	T* data;
	unsigned int capacity;
	unsigned int size;

};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	//create a new array of Ts
	data = new T[ 10 ];
	capacity = 10;
	size = 0;
}

template<typename T>
inline DynamicArray<T>::DynamicArray( unsigned int a_capacity )
{
	data = new T[a_capacity];
	capacity = a_capacity;
	size = 0;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
	delete[] data;
}

template<typename T>
inline void DynamicArray<T>::PushBack(const T a_value)
{
	//resize if necessary
	if (size == capacity)
	{
		Resize(capacity + 10);
	}

	//add the value in next free spot
	data[size] = a_value;
	size++;
}

template<typename T>
inline void DynamicArray<T>::Insert(const T a_value, unsigned int a_index)
{
	//if the index specified is greater than size, set it to size - 1
	if (a_index >= size)
	{
		a_index = size - 1;
	}

	//resize if necessary
	if (size == capacity)
	{
		Resize(capacity + 10);
	}

	//shift across elements from end to indexs
	for (int i = size - 1; i >= a_index; i--)
	{
		data[i + 1] = data[i];
	}

	//insert element at a_index
	data[a_index] = a_value;

	//increment size
	++size;

}

template<typename T>
inline void DynamicArray<T>::Remove(unsigned int a_index)
{
	if (size == 0 || a_index >= size)
		return;

	//shift left elements from a_index to end
	for (int i = a_index; i < size-1; i++)
	{
		data[i] = data[i + 1];
	}

	//decrement size
	--size;

}

template<typename T>
inline int DynamicArray<T>::Find(const T a_value) const
{
	//search through the valid elements
	for (int i = 0; i < size; i++)
	{
		//if we find a match, return the index
		if (data[i] == a_value)
			return i;
	}

	//no element found, return -1
	return -1;
}

template<typename T>
inline void DynamicArray<T>::Resize(unsigned int a_newCapacity)
{
	//capacity should not be zero
	assert(a_newCapacity != 0);

	//create a new array of new capacity
	T* newData = new T[a_newCapacity];

	//copy size elements if the capacity is increasing,
	//capacity elements if it's decreasing
	unsigned int elementsToCopy = (size < a_newCapacity) ? size : a_newCapacity;

	//copy those elements
	for (unsigned int i = 0; i < elementsToCopy; i++)
	{
		newData[i] = data[i];
	}

	//delete old data
	delete[] data;

	//point data at the newData on the heap
	data = newData;

	//update capacity to our new capacity
	capacity = a_newCapacity;
}

template<typename T>
inline unsigned int DynamicArray<T>::GetSize() const
{
	return size;
}

template<typename T>
inline unsigned int DynamicArray<T>::GetCapacity() const
{
	return capacity;
}

template<typename T>
inline T & DynamicArray<T>::operator[](unsigned int index)
{
	return data[index];
}


