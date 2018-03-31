#include <string>

using namespace std;

class TreeNode
{
  private:
    string value;
    int *count;
    TreeNode *left;
    TreeNode *right;

  public:
    TreeNode() : value(string()), count(0), left(nullptr), right(nullptr) {}
    TreeNode(const TreeNode &node) : value(node.value), count(node.count), left(node.left), right(node.right)
    {
        ++*count;
    }
    TreeNode &operator=(const TreeNode &rhs);
    ~TreeNode()
    {
        if (left)
        {
            delete left;
            left = nullptr;
        }
        if (right)
        {
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
};

TreeNode &TreeNode::operator=(const TreeNode &rhs)
{
    ++*rhs.count;
    if (--*count == 0)
    {
        if (left)
        {
            delete left;
            left = nullptr;
        }
        if (right)
        {
            delete right;
            right = nullptr;
        }
        delete count;
        count = nullptr;
    }
    count = rhs.count;
    value = rhs.value;
    left = rhs.left;
    right = rhs.right;
    return *this;
}

class BinStrTree
{
  private:
    TreeNode *root;

  public:
    BinStrTree() : root(new TreeNode()) {}
    BinStrTree(const BinStrTree &bst) : root(new TreeNode(*bst.root)) {}
    BinStrTree &operator=(const BinStrTree &rhs);
    ~BinStrTree()
    {
        if (root)
        {
            delete root;
            root = nullptr;
        }
    }
};

BinStrTree &BinStrTree::operator=(const BinStrTree &rhs)
{
    TreeNode *newRoot = new TreeNode(*rhs.root);
    if (root)
    {
        delete root;
        root = nullptr;
    }
    root = newRoot;
    return *this;
}