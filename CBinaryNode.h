#ifndef CBINARYNODE_H
#define CBINARYNODE_H

template<class ItemType>
class CBinaryNode
{
private:
    ItemType item;                   // Data portion
    CBinaryNode<ItemType>* leftChildPtr;   // Pointer to left child
    CBinaryNode<ItemType>* rightChildPtr;  // Pointer to right child

public:
    CBinaryNode() : leftChildPtr(nullptr), rightChildPtr(nullptr) { }
    CBinaryNode(const ItemType& anItem) : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) { }
    CBinaryNode(const ItemType& anItem, CBinaryNode<ItemType>* leftPtr, CBinaryNode<ItemType>* rightPtr) :
        item(anItem), leftChildPtr(leftPtr), rightChildPtr(rightPtr) { }

    void setItem(const ItemType& anItem) { item = anItem; }
    ItemType getItem() const { return item; }

    bool isLeaf() const { return (leftChildPtr == nullptr && rightChildPtr == nullptr); }

    CBinaryNode<ItemType>* getLeftChildPtr() const { return leftChildPtr; }
    CBinaryNode<ItemType>* getRightChildPtr() const { return rightChildPtr; }

    void setLeftChildPtr(CBinaryNode<ItemType>* leftPtr) { leftChildPtr = leftPtr; }
    void setRightChildPtr(CBinaryNode<ItemType>* rightPtr) { rightChildPtr = rightPtr; }
};

#endif