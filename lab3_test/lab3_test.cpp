#include "pch.h"
#include "CppUnitTest.h"
#include "../AiSD_3/BinaryHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab3test
{
	TEST_CLASS(lab3test)
	{
	public:
		BinaryHeap test;
		Iterator dftit;
		TEST_METHOD_INITIALIZE(setup)
		{
			test = BinaryHeap();
			dftit = test.create_dft_iterator();
		}

		TEST_METHOD(TestHeapInsert)
		{
			for (size_t i = 1; i < 8; i++)
				test.insert(i);
			for (int i = 1; i < 8; i++)
				Assert::AreEqual(dftit.next() , i);
		}
	};
}
