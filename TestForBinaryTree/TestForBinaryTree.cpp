#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3/ClassTree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestForBinaryTree
{
	TEST_CLASS(TestForBinaryTree)
	{
	public:
		int n = 10;
		int array[10] = { 4, 0, 2, 5, 4, 0, 8, 9, 3, 8 };
		BinarySearchTree berezka;
		TEST_METHOD(insert)
		{
			for (int i = 0; i < n; ++i) berezka.insert(array[i]);
			Iterator* elem = berezka.create_dft_Iterator(berezka.Root);
			bool flag = true;
			int index = 0;
			while (elem->has_next())
			{
				if (array[index] != elem->next())
				{
					flag = false;
					break;
				}
				index++;
			}
		}
		TEST_METHOD(contains_2)
		{
			for (int i = 0; i < n; ++i) berezka.insert(array[i]);
			Assert::AreEqual(true, berezka.contains(array[4]));
		}
		TEST_METHOD(remove)
		{
			for (int i = 0; i < n; ++i) berezka.insert(array[i]);
			berezka.remove(berezka.Root, array[7]);
			Iterator* elem = berezka.create_bft_Iterator(berezka.Root);
			bool flag = true;
			int index = 0;
			while (elem->has_next())
			{
				if (array[index] != elem->next())
				{
					flag = false;
					break;
				}
				index++;
			}
		}
		TEST_METHOD(remove_2)
		{
			for (int i = 0; i < n; ++i) berezka.insert(array[i]);
			berezka.remove(berezka.Root, array[3]);
			Iterator* elem = berezka.create_bft_Iterator(berezka.Root);
			bool flag = true;
			int index = 0;
			while (elem->has_next())
			{
				if (array[index] != elem->next())
				{
					flag = false;
					break;
				}
				index++;
			}
		}
		TEST_METHOD(create_DFT_Iterator)
		{
			for (int i = 0; i < n; ++i) berezka.insert(array[i]);
			Iterator* elem = berezka.create_dft_Iterator(berezka.Root);
			bool flag = true;
			int index = 0;
			while (elem->has_next())
			{
				if (array[index] != elem->next())
				{
					flag = false;
					break;
				}
				index++;
			}
		}
		TEST_METHOD(create_BFT_Iterator)
		{
			for (int i = 0; i < n; ++i) berezka.insert(array[i]);
			Iterator* elem = berezka.create_bft_Iterator(berezka.Root);
			bool flag = true;
			int index = 0;
			while (elem->has_next())
			{
				if (array[index] != elem->next())
				{
					flag = false;
					break;
				}
				index++;
			}
		}
	};
}