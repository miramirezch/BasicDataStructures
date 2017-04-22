#pragma once
#include <memory>

// Miguel Ramirez Chacon
// 22/04/17
// Modern C++ Practice:
// Basic Simply Linked List
// Smart pointers for resource management
// Move Semantics


namespace datastructures
{
	
	template<typename T>
	struct SinglyNode
	{
		T data;
		std::unique_ptr<SinglyNode<T>> next;

		SinglyNode(T data) :data{ data } {}
	};

	template<typename T>
	class LinkedList
	{
	public:		

		LinkedList(T data)
		{
			head_ = std::make_unique<SinglyNode<T>>(data);
			tail_ = head_.get();
			counter_++;
		}

		LinkedList(const LinkedList& other) = delete;
		LinkedList& operator=(const LinkedList& other) = delete;

		LinkedList(LinkedList&& other) :counter_{ other.Count() }, head_{ std::move(other.head_) }, tail_{ other.tail_ }
		{
			other.counter_ = 0;
			other.tail_ = nullptr;
		}

		LinkedList& operator=(LinkedList&& other)
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

		LinkedList& AddFirst(T data)
		{
			auto temp = std::move(head_);			
			head_ = std::make_unique<SinglyNode<T>>(data);
			head_->next = std::move(temp);

			if (!counter_)
			{
				tail_ = head_.get();
			}			

			counter_++;
			return *this;
		}

		LinkedList& AddLast(T data)
		{
			auto temp = std::make_unique<SinglyNode<T>>(data);

			if (!counter_)
			{
				head_ = std::move(temp);
				tail_ = head_.get();				
			}
			else
			{
				tail_->next = std::move(temp);
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

			SinglyNode<T>* previous = nullptr;
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

						}
						else
						{
							head_ = std::move(current->next);
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

		bool DeleteAt(unsigned position)
		{
			if (position >= counter_ || counter_ == 0)
				return false;

			int iterations{ 0 };
			SinglyNode<T>* previous = nullptr;
			auto current = head_.get();

			if (current->next == nullptr)
			{
				head_ = nullptr;
				tail_ = nullptr;
				counter_--;
				return true;
			}

			while (iterations != position)
			{
				previous = current;
				current = current->next.get();
				iterations++;
			}

			if (current->next == nullptr)
			{
				previous->next = nullptr;
				tail_ = previous;				
			}
			else
			{				
				auto next_pointer = current->next.release();
				previous->next = nullptr;
				previous->next = std::unique_ptr<SinglyNode<T>>(next_pointer);
			}
			counter_--;
			return true;
		}


	private:
		std::unique_ptr<SinglyNode<T>> head_ = nullptr;
		SinglyNode<T>* tail_ = nullptr;
		int counter_ = 0;
	};
}

