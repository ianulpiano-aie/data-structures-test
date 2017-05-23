#include <iostream>
#include "DynamicArray.h"

template<typename T>
void printDynamicArray(DynamicArray<T>& a_array);
template<typename T>
void printDynamicArrayContents(DynamicArray<T>& a_array);
template<typename T>
bool compareArray(DynamicArray<T>& a_array, T* compareArr, unsigned int length);
bool runDynamicArrayTests();

void main()
{
	bool result = runDynamicArrayTests();

	if (result == true)
	{
		std::cout << "Dynamic Array Tests Passed Successfully" << std::endl;
	}
	else
	{
		std::cout << "Dynamic Array Tests Failed." << std::endl;
	}
}


bool runDynamicArrayTests()
{
	//create a dynamic array
	DynamicArray<int> numbers;

	///////////////////////////
	// PushBack
	///////////////////////////
	std::cout << "[--- PushBack (1,2,3) to dynamic array ---]" << std::endl;
	
	numbers.PushBack( 1 );
	numbers.PushBack( 2 );
	numbers.PushBack( 3 );
			
	if (numbers[0] != 1 || numbers[1] != 2 || numbers[2] != 3)
	{
		std::cout << "[TEST FAILED] (PUSHBACK) Expected [1][2][3], got [" << numbers[0] << "][" << numbers[1] << "][" << numbers[2] << "]" << std::endl;
		return false;
	}
	
	printDynamicArray(numbers);



	///////////////////////////
	// Resize
	///////////////////////////
	std::cout << "[--- Resizing capacity to 15 ---]" << std::endl;
	numbers.Resize(15);
	
	if (numbers.GetCapacity() != 15)
	{
		std::cout << "[TEST FAILED] (RESIZE) Expected 15, got " << numbers.GetCapacity() << std::endl;
		return false;
	}

	printDynamicArray(numbers);


	///////////////////////////
	// Insert
	///////////////////////////
	std::cout << "[--- Inserting 4 at position 1 ---]" << std::endl;
	numbers.Insert(4, 1);

	int testArr[4]{ 1, 4, 2, 3 };
	if ( compareArray(numbers, testArr, 4) == false )
	{
		std::cout << "[TEST FAILED] (INSERT) Expected 1,4,2,3, got ";
		printDynamicArrayContents(numbers);
		std::cout << std::endl;
		return false;
	}

	printDynamicArray(numbers);


	///////////////////////////
	// Remove
	///////////////////////////
	std::cout << "[--- Remove element at index 2 ---]" << std::endl;
	numbers.Remove(2);

	int testArr2[3] { 1, 4, 3 };
	if (compareArray(numbers, testArr2, 3) == false)
	{
		std::cout << "[TEST FAILED] (REMOVE) Expected 1,4,3, got ";
		printDynamicArrayContents(numbers);
		std::cout << std::endl;
		return false;
	}

	printDynamicArray(numbers);



	///////////////////////////
	// Find (in array)
	///////////////////////////
	std::cout << "[--- Find element with value 3 ---]" << std::endl;
	
	int findElement = numbers.Find(3);
	
	if (findElement != 2)
	{
		std::cout << "[TEST FAILED] (FIND) Expected 2, got " << findElement;
		std::cout << std::endl;
		return false;
	}

	std::cout << "Value 3 found at Index " << findElement << std::endl;
	printDynamicArray(numbers);


	///////////////////////////
	// Find (not in array)
	///////////////////////////
	std::cout << "[--- Find element with value 7 ---]" << std::endl;

	int findElement2 = numbers.Find(7);

	if (findElement2 != -1)
	{
		std::cout << "[TEST FAILED] (FIND) Expected -1, got " << findElement2;
		std::cout << std::endl;
		return false;
	}

	std::cout << "Value 7 found at Index " << findElement2 << std::endl;
	printDynamicArray(numbers);

	///////////////////////////
	// Remove All (and extra removes after end)
	///////////////////////////
	std::cout << "[--- Remove all elements ---]" << std::endl;
	
	for (int i = 0; i < 10; i++)
	{
		numbers.Remove(0);
	}

	if (numbers.GetSize() != 0)
	{
		std::cout << "[TEST FAILED] (REMOVE ALL) Expected Size 0 got Size " << numbers.GetSize() << std::endl;
		return false;
	}

	printDynamicArray(numbers);

	//we made it to end of test, return true
	return true;
}

template< typename T >
void printDynamicArray(DynamicArray<T>& a_array)
{
	for (unsigned int i = 0; i < a_array.GetSize(); i++)
	{
		std::cout << "[" << a_array[i] << "]";
	}

	std::cout << "  [size " << a_array.GetSize() << "] [capacity " << a_array.GetCapacity() << "]" << std::endl << std::endl << std::endl;
}

template<typename T>
void printDynamicArrayContents(DynamicArray<T>& a_array)
{
	for (int i = 0; i < a_array.GetSize(); i++)
	{
		std::cout << a_array[i] << ",";
	}
}

template<typename T>
bool compareArray(DynamicArray<T>& a_array, T * compareArr, unsigned int length)
{
	for (int i = 0; i < length; i++)
	{
		if (compareArr[i] != a_array[i])
			return false;
	}

	return true;
}
