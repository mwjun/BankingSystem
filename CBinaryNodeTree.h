#ifndef CBINARYNODETREE_H
#define CBINARYNODETREE_H

#include "CBinaryTreeInterface.h"
#include "CBinaryNode.h"

template<class ItemType>
class CBinaryNodeTree : public CBinaryTreeInterface<ItemType>
{
protected:
    CBinaryNode<ItemType>* rootPtr;

public:
    CBinaryNodeTree() : rootPtr(nullptr) { }
    CBinaryNodeTree(const ItemType& rootItem) { rootPtr = new CBinaryNode<ItemType>(rootItem); }
    CBinaryNodeTree(const CBinaryNodeTree<ItemType>& tree) { /* Copy constructor logic */ }

    bool isEmpty() const { return rootPtr == nullptr; }
    int getHeight() const { return getHeightHelper(rootPtr); }
    int getNumberOfNodes() const { return getNumberOfNodesHelper(rootPtr); }
    ItemType getRootData() const { return rootPtr->getItem(); }

    void clear() { destroyTree(rootPtr); rootPtr = nullptr; }
    bool add(const ItemType& newData) { return insertInorder(rootPtr, newData); }
    bool remove(const ItemType& data) { /* Removal logic */ return true; }
    ItemType getEntry(const ItemType& anEntry) const { /* Retrieval logic */ }
    bool contains(const ItemType& anEntry) const { /* Contains logic */ }

    virtual ~CBinaryNodeTree() { clear(); }

private:
    int getHeightHelper(CBinaryNode<ItemType>* subTreePtr) const;
    int getNumberOfNodesHelper(CBinaryNode<ItemType>* subTreePtr) const;

    // Recursively deletes all nodes from the tree
    void destroyTree(CBinaryNode<ItemType>* subTreePtr);

    // Recursively adds a new node to the tree in a left/right fashion to keep tree balanced
    CBinaryNode<ItemType>* balancedAdd(CBinaryNode<ItemType>* subTreePtr, CBinaryNode<ItemType>* newNodePtr);

    // Recursively finds where the given node should be placed and inserts it
    CBinaryNode<ItemType>* insertInorder(CBinaryNode<ItemType>* subTreePtr, const ItemType& newData);
};


#endif