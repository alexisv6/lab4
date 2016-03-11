#include <iostream>
#include <iomanip>
#include "Item.h"
using namespace std;
class BinTree
{
	friend ostream& operator<<(ostream &theStream, BinTree &other);
	struct Node;
public:
	BinTree();
	~BinTree();

	bool Insert(Item *theItem, int amt);
	bool Retrieve(const Item &theItem, Item *&foundItem);
	bool isEmpty() const;
	void makeEmpty();
	void Display() const;

private:
	struct Node
	{
		Item *data;
		Node *leftChild;
		Node *rightChild;
	};
	Node *root;
	
	void display(Node *root) const;
	void chopDownTree(Node *&root);
	void getFromTree(Node *root, const Item &theItem, Item *& foundItem);
};

