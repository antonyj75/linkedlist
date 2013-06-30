#pragma once

namespace Ant
{

template<class T>
class AntLinkedList
{
	// Begin: Linked list node that contains the data
	class Node
	{
		T m_strData;
		Node* m_pNext;
		Node() : m_pNext(NULL)
		{}

		static Node* CreateNewNode(const T& strData) {
			Node* pNewNode = new Node();
			pNewNode->m_strData = strData;
			return pNewNode;
		}

		friend class AntLinkedList;
	};
	// End: Linked list node that contains the data

	// Begin: Data members of the linked list class
	Node* m_pHead;
	int m_nCount;
	// End: Data members of the linked list class

	// Begin: Helper functions for add and remove
	bool CreateHeadIfListIsEmpty(Node* pNewNode) {
		if(m_pHead != NULL)
			return false;
		
		m_pHead = pNewNode;
		return true;
	}

	void AddToEndOfList(Node* pNewNode) {
		Node* pNode = m_pHead;
		while(pNode->m_pNext != NULL)
			pNode = pNode->m_pNext;

		pNode->m_pNext = pNewNode;
	}

	bool HeadShouldBeRemoved(const T& strItemToRemove) {
		if( m_pHead->m_strData != strItemToRemove )
			return false;

		Node* pTemp = m_pHead;
		m_pHead = m_pHead->m_pNext;
		delete pTemp;
		m_nCount--;
		return true;
	}

	void HandleOtherItemsRemoval(const T& strItemToRemove) {
		Node* pNode = m_pHead;
		while(pNode != NULL)
		{
			Node* pPrev = pNode;
			pNode = pNode->m_pNext;
		
			if( pNode == NULL )
				break;
		
			if( pNode->m_strData != strItemToRemove )
				continue;

			pPrev->m_pNext = pNode->m_pNext;
			delete pNode;
			m_nCount--;
			break;
		}
	}
	// End: Helper functions for add and remove

public:
	// Begin: Iterator class to help iterate through the linked list
	class iterator
	{
		Node* m_pCurrentNode;
	public:
		iterator() : m_pCurrentNode(NULL) {}
		iterator(const AntLinkedList* lst) : m_pCurrentNode(lst->m_pHead) {}
		const T& operator*() {
			return m_pCurrentNode->m_strData;
		}
		void operator++(int) {
			if(m_pCurrentNode == NULL)
				return;

			m_pCurrentNode = m_pCurrentNode->m_pNext;
		}
		bool operator!=(const iterator& right) {
			return m_pCurrentNode != right.m_pCurrentNode;
		}
	};
	// End: Iterator class to help iterate through the linked list

	// Begin: Public members of the linked list class that are exposed to the outside world
	AntLinkedList(void) : m_nCount(0), m_pHead(NULL) {}

	~AntLinkedList(void) {
		if(m_pHead == NULL)
			return;

		Node* pNode = m_pHead;
		while(pNode != NULL)
		{
			Node* pTempNode = pNode;
			pNode = pNode->m_pNext;
			delete pTempNode;
		}
	}

	void* add(const T& strData) {

		Node* pNewNode = Node::CreateNewNode(strData);

		if( !CreateHeadIfListIsEmpty(pNewNode) )
			AddToEndOfList(pNewNode);
		
		m_nCount++;
		
		return pNewNode;
	}

	int Count() {
		return m_nCount;
	}

	iterator begin(void) {
		return iterator(this);
	}

	iterator end(void) {
		return iterator();
	}

	void remove(const T& strItemToRemove) {
		if( HeadShouldBeRemoved(strItemToRemove) )
			return;
		
		HandleOtherItemsRemoval(strItemToRemove);
	}
	// End: Public members of the linked list class that are exposed to the outside world
};

}
