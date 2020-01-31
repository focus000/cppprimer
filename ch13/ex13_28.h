#ifndef EX13_28H
#define EX13_28H

#include <string>

class TreeNode
{
private:
    std::string value;
    int *count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode() : value(), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(std::string const &str) : value(str), count(new int(1)), left(nullptr), right(nullptr) {}
    TreeNode(TreeNode const &tn) : value(tn.value), count(tn.count), left(tn.left), right(tn.right) { ++*count; }
    TreeNode &operator=(TreeNode const &rhs)
    {
        ++*rhs.count;
        if (--*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
        value = rhs.value;
        count = rhs.count;
        left = rhs.left;
        right = rhs.right;
        return *this;
    }
    ~TreeNode()
    {
        if (--*count == 0)
        {
            delete count;
            delete left;
            delete right;
        }
    }
};

class BinStrTree
{
private:
    TreeNode *root;

public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(BinStrTree const &bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree &operator=(BinStrTree const &rhs)
    {
        auto troot = new TreeNode(*rhs.root);
        delete root;
        root = troot;
        return *this;
    }
    ~BinStrTree() { delete root; }
};

#endif