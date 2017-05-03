#pragma once
#include <memory>
#include<iostream>

namespace datastructures
{
	template<typename T>
	struct BSTNode
	{
		BSTNode(T value) :data{ value } {}

		~BSTNode()
		{
			std::cout << "Destructing data: " << data << '\n';
		}

		T data;
		std::unique_ptr<BSTNode<T>> left = nullptr;
		std::unique_ptr<BSTNode<T>> right = nullptr;
	};

	template<typename T>
	class BST
	{
	public:
		BST() {}
		BST(const BST& other) = delete;
		BST& operator=(const BST& other) = delete;

		void Add(T value)
		{
			auto current = root_.get();

			if (current)
			{
				Add(current, value);
			}
			else
			{
				root_ = std::make_unique<BSTNode<T>>(value);
				count_++;
			}
		}

		void Add(BSTNode<T>* current, T value)
		{
			if (value < current->data)
			{
				if (current->left)
				{
					Add(current->left.get(), value);
				}
				else
				{
					current->left = std::make_unique<BSTNode<T>>(value);
					count_++;
				}
			}

			else
			{
				if (current->right)
				{
					Add(current->right.get(), value);
				}
				else
				{
					current->right = std::make_unique<BSTNode<T>>(value);
					count_++;
				}
			}
		}

		void PreOrder()
		{
			if (root_.get())
			{
				PreOrder(root_.get());
			}
			else
			{
				std::cout << "No hay elementos en el arbol" << '\n';
			}
		}

		void PreOrder(BSTNode<T>* current)
		{
			if (current)
			{
				std::cout << current->data << '\n';
				PreOrder(current->left.get());
				PreOrder(current->right.get());
			}			
		}

		void InOrder()
		{
			if (root_.get())
			{
				InOrder(root_.get());
			}
			else
			{
				std::cout << "No hay elementos en el arbol" << '\n';
			}
		}

		void InOrder(BSTNode<T>* current)
		{
			if (current)
			{				
				InOrder(current->left.get());
				std::cout << current->data << '\n';
				InOrder(current->right.get());
			}
		}

		void PostOrder()
		{
			if (root_.get())
			{
				PostOrder(root_.get());
			}
			else
			{
				std::cout << "No hay elementos en el arbol" << '\n';
			}
		}

		void PostOrder(BSTNode<T>* current)
		{
			if (current)
			{
				PostOrder(current->left.get());				
				PostOrder(current->right.get());
				std::cout << current->data << '\n';
			}
		}		

	private:
		int count_ = 0;
		std::unique_ptr<BSTNode<T>> root_ = nullptr;

	};


}