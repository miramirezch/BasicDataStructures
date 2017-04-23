#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include <iostream>
#include <vector>
using namespace datastructures;

// Miguel Ramirez Chacon
// 22/04/17
// Modern C++ Practice:
// Test for Singly and Doubly linked lists
// Smart pointers for resource management
// Move Semantics

int main()
{
	//---------------------------------------------------
	// Singly Linked List

	std::cout << "Singly Linked List" << '\n';

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

	//--------------------------------------------------------------------------
	// Doubly Linked List
	std::cout << "Doubly Linked List" << '\n';

	// Create Doubly linked list with one element
	DoublyLinkedList<int> dlist(100);

	//Add some elements at the head of the list
	dlist.AddFirst(110).AddFirst(200).AddFirst(300);
	
	// Print the elements of the list
	dlist.Print();

	std::cout << "-----------------" << '\n';

	//Add some elements at the tail of the list
	dlist.AddLast(500).AddLast(600).AddLast(700);

	// Delete some elements of the list if possible
	dlist.Delete(500);
	dlist.Delete(700);
	dlist.Delete(600);
	dlist.Delete(300);
	dlist.Delete(100);
	dlist.Delete(110);
	dlist.Delete(200);
	dlist.Delete(838383);

	//--------------------------------------------------------------------------
	// Stack

	Stack<double> s;
	s.Push(3).Push(2).Push(1);

	std::cout << s.Top() << std::endl;

	s.Pop().Pop().Pop().Pop().Pop();

	s.Push(10);

	std::cout << s.Top() << std::endl;





	getchar();
	return 0;

}
