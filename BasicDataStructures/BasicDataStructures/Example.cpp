#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "StackL.h"
#include "StackV.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <string>
using namespace datastructures;

// Miguel Ramirez Chacon
// Modern C++ Practice:
// Test for Basic Data Structures
// Smart pointers for resource management
// Move Semantics and Fluent Interface

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
	// Create a new stack - List based
	StackL<double> s;

	// Push some values
	s.Push(3).Push(2).Push(1);

	// Print element on the top of the stack
	std::cout << s.Top() << std::endl;

	// Pop some values
	s.Pop().Pop().Pop().Pop().Pop();

	//--------------------------------------------------------------------------
	// Stack
	// Create a new stack - Vector based
	StackV<int> s2;

	s2.Push(1).Push(2).Push(3);
	std::cout << s2.Top() << std::endl;
	s2.Pop().Pop().Pop();

	//--------------------------------------------------------------------------
	// Binary Search Tree

	BST<std::string> bst;
	bst.Add("abracadabra").Add("bracadabra").Add("racadabra").Add("acadabra").Add("cadabra");

	BST<int> bst2;
	bst2.Add(4).Add(2).Add(6).Add(1).Add(3).Add(5).Add(7);

	// PreOrder/ InOrder / PostOrder
	std::cout << "-------------------------" << '\n';
	bst.PreOrder();
	std::cout << "-------------------------" << '\n';
	bst.InOrder();
	std::cout << "-------------------------" << '\n';
	bst.PostOrder();

	// Searching Elements
	std::cout<<bst.Search("abracadabra")<<'\n';
	std::cout << bst2.Search(3) << '\n';

	getchar();
	return 0;

}
