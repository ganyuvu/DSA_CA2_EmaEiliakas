#include "pch.h"
#include "CppUnitTest.h"
#include "../MapPair.h"
#include "../TreeMap.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DSACA2UnitTest
{
	TEST_CLASS(MapPairUnitTest)
	{
	public:

		TEST_METHOD(equalsOperator)
		{
			MapPair<int, std::string> pair1(1, "banana");
			MapPair<int, std::string> pair2(1, "apple");

			Assert::IsTrue(pair1 == pair2);
		}

		TEST_METHOD(notEqualsOperator) {

			MapPair<int, std::string> pair1(1, "banana");
			MapPair<int, std::string> pair2(2, "apple");

			Assert::IsFalse(pair1 == pair2);
		}

		TEST_METHOD(lessThanOperator)
		{
			MapPair<int, std::string> pair1(1, "apple");
			MapPair<int, std::string> pair2(2, "banana");

			Assert::IsTrue(pair1 < pair2); //pair 1 is less than pair2 so should be true
			Assert::IsFalse(pair2 < pair1); //pair 2 is greater than pair1 so this will turn false
		}

		TEST_METHOD(greaterThanOperator)
		{
			MapPair<int, std::string> pair1(3, "apple");
			MapPair<int, std::string> pair2(2, "banana");

			Assert::IsTrue(pair1 > pair2); //pair 1 is greater than pair2 so should be true
			Assert::IsFalse(pair2 > pair1); //pair 2 is less than pair1 so this will turn false
		}
	};

	TEST_CLASS(TreeMapUnitTest)
	{
	public:

		TEST_METHOD(TestTreeMapClear)
		{
			TreeMap<int, string> tree;

			tree.put(1,"apple");
			tree.put(2, "banana");

			Assert::IsTrue(tree.contains(1));
			Assert::IsTrue(tree.contains(2));

			tree.clear();

			Assert::IsFalse(tree.contains(1));	
		}
	};
}
