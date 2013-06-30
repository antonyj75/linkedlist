// AntLinkedListTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../AntLinkedList/AntLinkedList.h"

using namespace Ant;

// Helper method to add data to the linked list
void InitializeList(AntLinkedList<std::string>& lst)
{
	lst.add("Hello");
	lst.add("World");
}

BOOST_AUTO_TEST_CASE(AddingDataToLinkedList)
{
	AntLinkedList<std::string> lst;
	InitializeList(lst);
	BOOST_CHECK_EQUAL(lst.Count(), 2);
}

BOOST_AUTO_TEST_CASE(ReadingFromLinkedList)
{
	AntLinkedList<std::string> lst;
	InitializeList(lst);

	auto itr = lst.begin();
	BOOST_CHECK_EQUAL(*itr, "Hello");
	itr++;
	BOOST_CHECK_EQUAL(*itr, "World");
}

BOOST_AUTO_TEST_CASE(IteratingLinkedList)
{
	std::string strArray[2];
	strArray[0] = "Hello";
	strArray[1] = "World";

	AntLinkedList<std::string> lst;
	InitializeList(lst);

	int i=0;
	for( auto itr = lst.begin(), end = lst.end(); itr != end; i++, itr++ )
	{
		BOOST_CHECK_EQUAL(strArray[i], *itr);
	}

}

BOOST_AUTO_TEST_CASE(UsingIteratorThruCopyCtor)
{
	AntLinkedList<std::string> lst;
	InitializeList(lst);

	AntLinkedList<std::string>::iterator itr(&lst);
	BOOST_CHECK_EQUAL(*itr, "Hello");
}

BOOST_AUTO_TEST_CASE(DeleteElementsFromLinkedList)
{
	AntLinkedList<std::string> lst;
	lst.add("Hello");
	lst.add("My");
	lst.add("World");

	lst.remove("My");

	BOOST_CHECK_EQUAL(lst.Count(), 2);

	std::string strArray[2];
	strArray[0] = "Hello";
	strArray[1] = "World";

	int i=0;
	for( auto itr = lst.begin(), end = lst.end(); itr != end; i++, itr++ )
	{
		BOOST_CHECK_EQUAL(strArray[i], *itr);
	}
}

BOOST_AUTO_TEST_CASE(DeleteHeadFromLinkedList)
{
	AntLinkedList<std::string> lst;
	lst.add("Hello");
	lst.add("My");
	lst.add("World");

	lst.remove("Hello");

	BOOST_CHECK_EQUAL(lst.Count(), 2);

	std::string strArray[3];
	strArray[0] = "My";
	strArray[1] = "World";

	int i=0;
	for( auto itr = lst.begin(), end = lst.end(); itr != end; i++, itr++ )
	{
		BOOST_CHECK_EQUAL(strArray[i], *itr);
	}
}
