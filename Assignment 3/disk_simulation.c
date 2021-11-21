#include <math.h>
#include <stdio.h>

#include "disk_simulation.h"

#define t 10
#define N 20
int **secondaryMemory[N][2 * t] = {0};
int *primaryMemory[4 * t] = {0};
int numberOfBTreeNodes = 0;
int timeForBTree = 0;
int timeForBST = 0;

void allocateNodeBTree(tree_node *treeNodePtr)
{
    // Assign coordinate to node based on existing number of nodes in sec memory
    int maxBTreeNodesInABlock = (int)floor(((double)(2 * t)) / (2 * minDegree - 1));

    int row, column;
    row = numberOfBTreeNodes / maxBTreeNodesInABlock;
    column = (numberOfBTreeNodes % maxBTreeNodesInABlock) * (2 * minDegree - 1);

    numberOfBTreeNodes++;
    treeNodePtr->row = row;
    treeNodePtr->column = column;

    timeForBTree += 1;
}

void diskReadBTree(tree_node *treeNodePtr)
{
    // Add the node values to primary memory
    for (int i = 0; i < 2 * t; i++)
    {
        primaryMemory[i] = secondaryMemory[treeNodePtr->row][i];
    }
    timeForBTree += 10;
}

void diskWriteBTree(tree_node *treeNodePtr)
{
    // Make changes in secondary memory
    for (int i = treeNodePtr->column; i < treeNodePtr->numberOfKeys; i++)
    {
        secondaryMemory[treeNodePtr->row][i] = treeNodePtr->keys[i];
    }
    timeForBTree += 10;
}

void allocateNodeBST(bst_node *treeNodePtr)
{
}

void diskReadBST(bst_node *treeNodePtr)
{
}

void diskWriteBST(bst_node *treeNodePtr)
{
}