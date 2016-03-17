#include "stdafx.h"
#include "BinTree.h"



BinTree::BinTree()
{
	this->root = NULL;
}


BinTree::~BinTree()
{
	if (this->root != NULL)
	{
		chopDownTree(root);
	}
}

bool BinTree::Insert(Item * theItem, int amt)
{
	Node* itemPtr = new Node;			//allocate
	itemPtr->data = theItem;  
	itemPtr->data->setMaxCopies(amt);	//set item amount
	theItem = NULL;
	itemPtr->leftChild = NULL;
	itemPtr->rightChild = NULL;			// initialize
	if (isEmpty())						// case 1: set to root
	{
		root = itemPtr;  
	}
	else
	{
		Node* curr = root;
		bool done = false;
		while (!done)
		{								//dont insert if equal
			if (*itemPtr->data == *curr->data) 
			{
				int copies = curr->data->getAmountIn() + curr->data->getAmountOut();
				curr->data->setMaxCopies(copies + amt);
				delete itemPtr;  
				itemPtr = NULL;
				return false;
			}							// if less than curr go left
			else if (*itemPtr->data < *curr->data)
			{							// insert when you reach null
				if (curr->leftChild == NULL) 
				{
					curr->leftChild = itemPtr;
					done = true;
				}
				else					// get to leaf
				{
					curr = curr->leftChild;
				}
			}
			else 
			{							// if more go right
				if (curr->rightChild == NULL)
				{
					curr->rightChild = itemPtr;
					done = true;		// inserted right
				}
				else
				{						// find leaf
					curr = curr->rightChild;
				} 
			}
		}
	}
	return true;
}

bool BinTree::Retrieve(const Item &theItem, Item *& foundItem)
{
	getFromTree(root, theItem, foundItem);

	if (foundItem == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool BinTree::isEmpty() const
{
	return (this->root == NULL);
}

void BinTree::makeEmpty()
{
	chopDownTree(root);
}

void BinTree::Display() const
{
	display(root);
}

void BinTree::display(Node * curr) const
{
	if (curr == root)
	{
		curr->data->display();
	}

	if (curr != NULL) //Traverse inorder and print data
	{
		display(curr->leftChild);
		cout << right << setw(3) << curr->data->getAmountIn()
			<< setw(3) << curr->data->getAmountOut() << " ";
		curr->data->display();
		display(curr->rightChild);
	}
}

void BinTree::chopDownTree(Node *& root)
{
	if (root != NULL)
	{
		chopDownTree(root->leftChild);
		chopDownTree(root->rightChild);
		delete root->data;
		root->data = NULL;
		delete root;
		root = NULL;
	}
}

void BinTree::getFromTree(Node *root, const Item &theItem, Item *&foundItem)
{
	if (root == NULL)						// was not found empty
	{
		foundItem = NULL;
	}
	else if (theItem == *root->data)
	{
		foundItem = root->data;				// place found item
	}
	else if (theItem < *root->data)
	{
		getFromTree(root->leftChild, theItem, foundItem);
	}
	else
	{
		getFromTree(root->rightChild, theItem, foundItem);
	}
}

ostream& operator<<(ostream& theStream, const BinTree& tree)
{
	tree.Display(); //call inOrderDisplay
	theStream << endl;
	return theStream;
}