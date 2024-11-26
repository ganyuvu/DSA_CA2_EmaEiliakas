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

		TEST_METHOD(testEqualsOperator)
		{
			MapPair<int, string> pair1(1, "banana");
			MapPair<int, string> pair2(1, "apple");

			Assert::IsTrue(pair1 == pair2);
		}

		TEST_METHOD(testNotEqualsOperator) {

			MapPair<int, string> pair1(1, "banana");
			MapPair<int, string> pair2(2, "apple");

			Assert::IsFalse(pair1 == pair2);
		}


		TEST_METHOD(testLessThanOperator)
		{
			MapPair<int, string> pair1(1, "apple");
			MapPair<int, string> pair2(2, "banana");

			Assert::IsTrue(pair1 < pair2); //pair 1 is less than pair2 so should be true
			Assert::IsFalse(pair2 < pair1); //pair 2 is greater than pair1 so this will turn false
		}

		TEST_METHOD(testGreaterThanOperator)
		{
			MapPair<int, string> pair1(3, "apple");
			MapPair<int, string> pair2(2, "banana");

			Assert::IsTrue(pair1 > pair2); //pair 1 is greater than pair2 so should be true
			Assert::IsFalse(pair2 > pair1); //pair 2 is less than pair1 so this will turn false
		}
	};

	TEST_CLASS(TreeMapUnitTest)
	{
	public:

		TEST_METHOD(testTreeMapClear)
		{
			TreeMap<int, string> tree;

			tree.put(1,"apple");
			tree.put(2, "banana");

			Assert::IsTrue(tree.contains(1));
			Assert::IsTrue(tree.contains(2));

			tree.clear();

			Assert::IsFalse(tree.contains(1));	
		}

		TEST_METHOD(testTreeMapContains)
		{
			TreeMap<int, string> tree;

			tree.put(1, "apple");
			tree.put(2, "banana");

			// should come out as true 
			Assert::IsTrue(tree.contains(1));
			Assert::IsTrue(tree.contains(2));

			// Tshould come out as false as I didnt make a tree with the key 3
			Assert::IsFalse(tree.contains(3));

			tree.removeKey(1);

			Assert::IsFalse(tree.contains(1));
			Assert::IsTrue(tree.contains(2));

			tree.clear();

			Assert::IsFalse(tree.contains(1));
			Assert::IsFalse(tree.contains(2));
		}

		//thhis also tests the operator as it calls this method
		TEST_METHOD(testTreeMapGet)
		{
			TreeMap<int, string> tree;

			tree.put(1, "apple");
			tree.put(2, "banana");

			// Define expected values
			string defaultVal = "";
			string apple = "apple";
			string banana = "banana";

			// gets value based on key then checks if the expected string matches the string in the mapPair
			Assert::AreEqual(tree.get(1), apple);
			Assert::AreEqual(tree.get(2), banana); 

			//checking for a value that doesnt exist, so should return null
			Assert::AreEqual(tree.get(3), defaultVal);
		}

		TEST_METHOD(testTreeMapRemoveKey)
		{
			TreeMap<int, string> tree;

			tree.put(1, "apple");
			tree.put(2, "banana");

			Assert::IsTrue(tree.removeKey(1)); //removed pair with key 1

			Assert::IsFalse(tree.contains(1)); //checking if the map has the pair with key 1
			Assert::IsTrue(tree.contains(2));

			// removing a pair with key 3, which hasnt been made
			Assert::IsFalse(tree.removeKey(3));
		}

		TEST_METHOD(testTreeMapPut)
		{
			TreeMap<int, string> tree;

			// Add items to the tree map
			tree.put(1, "apple");
			tree.put(2, "banana");

			// Assert that the items are in the map
			Assert::IsTrue(tree.contains(1));
			Assert::IsTrue(tree.contains(2));
		}

		TEST_METHOD(TestTreeMapSize)
		{
			TreeMap<int, string> tree;

			// testing size of the tree without adding anything to it
			Assert::AreEqual(0, tree.size());

			tree.put(1, "apple");
			tree.put(2, "banana");

			// testing the size after adding pairs
			Assert::AreEqual(2, tree.size());

			// removing a pair and then testing the sizw
			tree.removeKey(1);
			Assert::AreEqual(1, tree.size());
		}
		
	};
}
