#pragma once
#include <vector>

// Miguel Ramirez Chacon
// 22/04/17
// Modern C++ Practice:
// Basic Stack - Vector Based
// Fluent Interface

template<typename T>
class StackV
{
public:

	StackV& Push(T value)
	{
		data_.push_back(value);
		count_++;
		return *this;
	}

	StackV& Pop()
	{
		if (count_ > 0)
		{
			data_.pop_back();
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
		return data_.back();
	}
	
	int Count()
	{
		return count_;
	}
private:
	std::vector<T> data_;
	int count_;

};
