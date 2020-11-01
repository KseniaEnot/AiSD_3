#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD_3/BinaryHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AiSD3Test
{
	TEST_CLASS(AiSD3Test)
	{
	public:
		BinaryHeap Test;
		Iterator* Test_bft_iterator;
		Iterator* Test_dft_iterator;

		TEST_METHOD(TestInsert1)
		{
			Test.insert(1);
			Test_bft_iterator = Test.create_bft_iterator();
			Assert::AreEqual(Test_bft_iterator->next(), 1);
		}

		TEST_METHOD(TestInsert1To5)
		{
			for (size_t i = 1; i < 6; i++)
				Test.insert(i);
			Test_bft_iterator = Test.create_bft_iterator();
			for (size_t i = 1; i < 6; i++)
				Assert::AreEqual(Test_bft_iterator->next(), (int)i);
		}

		TEST_METHOD(TestInsert5To1)
		{
			for (size_t i = 6; i >0; i--)
				Test.insert(i);
			Test_bft_iterator = Test.create_bft_iterator();
			Assert::AreEqual(Test_bft_iterator->next(), 1);
			Assert::AreEqual(Test_bft_iterator->next(), 3);
			Assert::AreEqual(Test_bft_iterator->next(), 2);
			Assert::AreEqual(Test_bft_iterator->next(), 6);
			Assert::AreEqual(Test_bft_iterator->next(), 4);
			Assert::AreEqual(Test_bft_iterator->next(), 5);
		}

		TEST_METHOD(TestContainsT)
		{
			for (size_t i = 6; i > 0; i--)
				Test.insert(i);
			Assert::AreEqual(Test.contains(4), true);
		}
		TEST_METHOD(TestContainsF)
		{
			for (size_t i = 6; i > 0; i--)
				Test.insert(i);
			Assert::AreEqual(Test.contains(0), false);
		}

		TEST_METHOD(TestRemoveLast)
		{
			for (size_t i = 6; i > 0; i--)
				Test.insert(i);
			Test.remove(5);
			Test_bft_iterator = Test.create_bft_iterator();
			Assert::AreEqual(Test_bft_iterator->next(), 1);
			Assert::AreEqual(Test_bft_iterator->next(), 3);
			Assert::AreEqual(Test_bft_iterator->next(), 2);
			Assert::AreEqual(Test_bft_iterator->next(), 6);
			Assert::AreEqual(Test_bft_iterator->next(), 4);
		}
		TEST_METHOD(TestRemove)
		{
			for (size_t i = 6; i > 0; i--)
				Test.insert(i);
			Test.remove(3);
			Test_bft_iterator = Test.create_bft_iterator();
			Assert::AreEqual(Test_bft_iterator->next(), 1);
			Assert::AreEqual(Test_bft_iterator->next(), 4);
			Assert::AreEqual(Test_bft_iterator->next(), 2);
			Assert::AreEqual(Test_bft_iterator->next(), 6);
			Assert::AreEqual(Test_bft_iterator->next(), 5);
		}

		TEST_METHOD(TestRemoveFirst)
		{
			for (size_t i = 6; i > 0; i--)
				Test.insert(i);
			Test.remove(1);
			Test_bft_iterator = Test.create_bft_iterator();
			Assert::AreEqual(Test_bft_iterator->next(), 2);
			Assert::AreEqual(Test_bft_iterator->next(), 3);
			Assert::AreEqual(Test_bft_iterator->next(), 5);
			Assert::AreEqual(Test_bft_iterator->next(), 6);
			Assert::AreEqual(Test_bft_iterator->next(), 4);
		}

		TEST_METHOD(TestRemoveError)
		{
			Test.insert(1);
			try {
				Test.remove(0);
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("Element doesn't exist", e.what());
			}
		}

		TEST_METHOD(TestBFTError)
		{
			Test.insert(1);
			Test.insert(2);
			Test_bft_iterator = Test.create_bft_iterator();
			try {
				Test_bft_iterator->next();
				Test_bft_iterator->next();
				Test_bft_iterator->next();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("No more elements", e.what());
			}
		}
		TEST_METHOD(TestDFTError)
		{
			Test.insert(1);
			Test.insert(2);
			Test_dft_iterator = Test.create_dft_iterator();
			try {
				Test_dft_iterator->next();
				Test_dft_iterator->next();
				Test_dft_iterator->next();
			}
			catch (std::out_of_range e) {
				Assert::AreEqual("No more elements", e.what());
			}
		}

		TEST_METHOD(TestDFT1)
		{
			for (size_t i = 6; i > 0; i--)
				Test.insert(i);
			Test.remove(1);
			Test_dft_iterator = Test.create_dft_iterator();
			Assert::AreEqual(Test_dft_iterator->next(), 2);
			Assert::AreEqual(Test_dft_iterator->next(), 3);
			Assert::AreEqual(Test_dft_iterator->next(), 6);
			Assert::AreEqual(Test_dft_iterator->next(), 4);
			Assert::AreEqual(Test_dft_iterator->next(), 5);
		}

		TEST_METHOD(TestDFT2)
		{
			for (size_t i = 6; i > 0; i--)
				Test.insert(i);
			Test_dft_iterator = Test.create_dft_iterator();
			Assert::AreEqual(Test_dft_iterator->next(), 1);
			Assert::AreEqual(Test_dft_iterator->next(), 3);
			Assert::AreEqual(Test_dft_iterator->next(), 6);
			Assert::AreEqual(Test_dft_iterator->next(), 4);
			Assert::AreEqual(Test_dft_iterator->next(), 2);
			Assert::AreEqual(Test_dft_iterator->next(), 5);
		}

	};
}
