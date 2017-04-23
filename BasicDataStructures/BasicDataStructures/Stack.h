#pragma once
#include<list>

namespace datastructures
{
	template<typename T>
	class Stack
	{
	public:
		Stack& Push(T value)
		{
			lista_.push_front(value);
			count_++;
			return *this;
		}

		Stack& Pop()
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