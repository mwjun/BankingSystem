#ifndef CBST_H
#define CBST_H

#include "CBinaryNodeTree.h"

template<class ItemType>
class CBST : public CBinaryNodeTree<ItemType>
{
public:
    CBST() : CBinaryNodeTree<ItemType>() { }
    CBST(const ItemType& rootItem) : CBinaryNodeTree<ItemType>(rootItem) { }

    bool add(const ItemType& newData);
    bool remove(const ItemType& data);
    ItemType getEntry(const ItemType& anEntry) const;
    bool contains(const ItemType& anEntry) const;

private:
    CBinaryNode<ItemType>* placeNode(CBinaryNode<ItemType>* subTreePtr, CBinaryNode<ItemType>* newNodePtr);
    CBinaryNode<ItemType>* removeValue(CBinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
};


#endif