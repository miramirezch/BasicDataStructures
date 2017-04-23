#pragma once
#include <memory>

// Miguel Ramirez Chacon
// 22/04/17
// Modern C++ Practice:
// Basic Doubly Linked List
// Smart pointers for resource management
// Move Semantics
// Fluent Interface

namespace datastructures
{

	template<typename T>
	struct DoublyNode
	{
		T data;
		std::unique_ptr<DoublyNode<T>> next = nullptr;
		DoublyNode<T>* previous = nullptr;

		DoublyNode(T data) :data{ data }, next{ nullptr }, previous{ nullptr } {}
	};

	template<typename T>
	class DoublyLinkedList
	{
	public:

		DoublyLinkedList(T data)
		{
			head_ = std::make_unique<DoublyNode<T>>(data);
			tail_ = head_.get();
			counter_++;
		}

		DoublyLinkedList(const DoublyLinkedList& other) = delete;
		DoublyLinkedList& operator=(const DoublyLinkedList& other) = delete;

		DoublyLinkedList(DoublyLinkedList&& other) :counter_{ other.Count() }, head_{ std::move(other.head_) }, tail_{ other.tail_ }
		{
			other.counter_ = 0;
		}

		DoublyLinkedList& operator=(DoublyLinkedList&& other)
		{
			if (this != &other)
			{
				head_ = nullptr;
				counter_ = other.Count();

				head_ = std::move(other.head_);
				tail_ = other.tail_;

				other.counter_ = 0;
				other.tail_ = nullptr;
				other.head_ = nullptr;
			}
			return *this;
		}

		DoublyLinkedList& AddFirst(T data)
		{
			auto temp = std::move(head_);
			head_ = std::make_unique<DoublyNode<T>>(data);

			if (!counter_)
			{
				tail_ = head_.get();
			}
			else
			{
				head_->next = std::move(temp);
				head_->next->previous = head_.get();
			}

			counter_++;
			return *this;
		}

		DoublyLinkedList& AddLast(T data)
		{
			auto temp = std::make_unique<DoublyNode<T>>(data);

			if (!counter_)
			{
				head_ = std::move(temp);
				tail_ = head_.get();				
			}
			else
			{
				tail_->next = std::move(temp);
				tail_->next->previous = tail_;
				tail_ = tail_->next.get();				
			}
			counter_++;
			return *this;
		}

		void Print()
		{
			auto current = head_.get();
			while (current != nullptr)
			{
				std::cout << current->data << std::endl;
				current = current->next.get();
			}
		}

		int Count()
		{
			return counter_;
		}

		bool Find(T value)
		{
			bool result = false;
			auto current = head_.get();

			while (current != nullptr)
			{
				if (current->data == value)
					return true;
				else
					current = current->next.get();
			}

			return false;
		}

		bool Delete(T value)
		{
			if (!counter_)
				return false;

			DoublyNode<T>* previous = nullptr;
			auto current = head_.get();	

			if (current->data == value && current->next == nullptr)
			{
				head_ = nullptr;
				tail_ = nullptr;
				counter_--;
				return true;
			}

			while (current != nullptr)
			{
				if (current->data == value)
				{
					if (current->next == nullptr)
					{
						previous->next = nullptr;
						tail_ = previous;
					}
					else
					{
						if (previous)
						{							
							previous->next = std::move(current->next);
							previous->next->previous = previous;
						}
						else
						{							
							head_ = std::move(current->next);
							head_->next->previous = head_.get();
						}										
					}
					counter_--;
					return true;
				}

				previous = current;
				current = current->next.get();
			}
			return false;
		}

		bool DeleteAt(int position)
		{
			if (position >= counter_ || counter_ == 0)
				return false;

			int iterations{ 0 };
			DoublyNode<T>* previous = nullptr;
			auto current = head_.get();

			while (iterations != position)
			{
				previous = current;
				current = current->next.get();
				iterations++;
			}

			if (current->next == nullptr)
			{
				head_ = nullptr;
				tail_ = nullptr;
			}
			else
			{				
				previous->next = std::move(current->next);
				previous->next->previous = previous;				
			}
			counter_--;
			return true;
		}


	private:
		std::unique_ptr<DoublyNode<T>> head_ = nullptr;
		DoublyNode<T>* tail_ = nullptr;
		int counter_ = 0;
	};
}


