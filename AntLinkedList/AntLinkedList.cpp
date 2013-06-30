// AntLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AntLinkedList.h"


int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Hello from linked list app!\n";

	Ant::AntLinkedList<std::string> lst;
	lst.add("Hello");
	lst.add("World");

	int i=0;
	for( auto itr = lst.begin(), end = lst.end(); itr != end; i++, itr++ )
	{
		std::cout << *itr << std::endl;
	}

	return 0;
}