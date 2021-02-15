#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
class Tree
{
private:
    Node* root;
public:
    Tree()
    {
        root = NULL;
    }

    Tree(Node* r)
    {
        root = r;
    }
    Node* getRoot()
    {
        return root;
    }
    void setRoot(Node* newroot)
    {
        root = newroot;
    }
    Node* Insert(struct Node* newroot, int value)
    {
        if (!newroot)
            return new Node(value);

        if (newroot->data < value)
            newroot->right = Insert(newroot->right, value);
        else
            newroot->left = Insert(newroot->left, value);


        return newroot;
    }
    void preorder(Node* root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }




};

int main()
{
    //test1
    Tree b = Tree();
    b.setRoot(new Node(50));
    b.Insert(b.getRoot(), 30);
    b.Insert(b.getRoot(), 20);
    b.Insert(b.getRoot(), 40);
    b.Insert(b.getRoot(), 70);
    b.Insert(b.getRoot(), 60);
    b.Insert(b.getRoot(), 80);
    cout << "test1" << endl;
    b.preorder(b.getRoot());
    cout << endl;

    //test 2
    Tree a = Tree();
    a.setRoot(new Node(50));
    a.Insert(a.getRoot(), 7);
    a.Insert(a.getRoot(), 212);
    a.Insert(a.getRoot(), 68);
    a.Insert(a.getRoot(), 36);
    a.Insert(a.getRoot(), 17);
    a.Insert(a.getRoot(), 97);

    cout << "test2" << endl;
    a.preorder(a.getRoot());
    cout << endl;

    //test3
    Tree c = Tree();
    c.setRoot(new Node(6));
    c.Insert(c.getRoot(), 70);
    c.Insert(c.getRoot(), 0);
    c.Insert(c.getRoot(), 6);
    c.Insert(c.getRoot(), 3);
    c.Insert(c.getRoot(), 7);
    c.Insert(c.getRoot(), 9);

    cout << "test3" << endl;
    c.preorder(c.getRoot());
    cout << endl;
    return 0;
}

