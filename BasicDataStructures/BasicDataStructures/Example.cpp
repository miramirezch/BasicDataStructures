#include "SinglyLinkedList.h"
#include <iostream>
#include <vector>
using namespace datastructures;

int main()
{
	//Create a Linked List
	LinkedList<int> list(30);	

	//Add some elements at the head of the list
	list.AddFirst(40).AddFirst(50);

	//Add some elements at the tail of the list
	list.AddLast(60).AddLast(70).AddLast(80);
	
	//Get total elements
	list.Count();

	//Find a certaint element
	if (list.Find(40))
		std::cout << "List contain element" << '\n';
	else
		std::cout << "Element not found" << '\n';

	// Print all elements of list
	list.Print();

	// Delete an element with a certain value 
	if (list.Delete(70))
		std::cout << "The element was deleted" << '\n';
	else
		std::cout << "Element not in list" << '\n';

	// Delete an element at certain position
	list.Print();
	list.DeleteAt(1);
	list.Print();

	//Create a vector of list
	std::vector<LinkedList<double>> vector_list;
	
	//Insert a list in a vector - Only throw move
	LinkedList<double> list2(500);
	list2.AddLast(1000).AddFirst(200).AddLast(500);
	vector_list.push_back(std::move(list2));

	//Using emplace back to add a new list
	vector_list.emplace_back(100);
	vector_list[1].AddFirst(200).AddFirst(300);

	std::cout << "Number of elements in vector: " << vector_list.size() << '\n';
	
	return 0;

}
