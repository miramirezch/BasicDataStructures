#pragma once
#include<list>

// Miguel Ramirez Chacon
// 22/04/17
// Modern C++ Practice:
// Basic Stack - List Based
// Fluent Interface

namespace datastructures
{
	template<typename T>
	class StackL
	{
	public:
		StackL& Push(T value)
		{
			lista_.push_front(value);
			count_++;
			return *this;
		}

		StackL& Pop()
		{
			if (count_>0)
			{				
				lista_.pop_front();
				count_--;
				return *this;
			}
			else
			{
				return *this;
			}
		}

		T Top()
		{
			return lista_.front();
		}

		int Count()
		{
			return count_;
		}

	private:
		std::list<T> lista_;
		int count_;
	};
}