#include <iostream>
#include "Item.h"
using namespace std;
class BinTree
{
	friend ostream& operator<<(ostream &theStream, BinTree &other);
	struct Node;
public:
	BinTree();
	~BinTree();

	bool Insert(Item *theItem, int maxCopies);
	bool Retrieve(const Item *theItem, Item *&foundItem);
	bool isEmpty() const;
	void makeEmpty();

private:
	struct Node
	{
		Item *data;
		Node *leftChild;
		Node *rightChild;
	};
	Node *root;
};

