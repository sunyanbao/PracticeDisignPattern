// 组合模式
// 使用场景：当需求是部分与整体的层次结构，并希望忽略组合对象与单个对象的不同，统一的使用组合结构的所有对象时

#include <iostream>
#include <set>

using namespace std;

class Node {
public:
    virtual void addChild(Node* n) = 0;
    virtual void removeChild(Node* n) = 0;
    virtual void display() = 0;
};

class GroupNode : public Node
{
public:
    void addChild(Node* n) override
    {
        m_nodes.insert(n);
    }
    void removeChild(Node* n) override
    {
        m_nodes.erase(n);
    }
    void display() override
    {
        cout << "display group node" << endl;
        for (auto&& node : m_nodes)
        {
            node->display();
        }
    }

protected:
    set<Node*> m_nodes;
};

class LeafNode :public Node
{
public:
    void addChild(Node* n) override
    {
        cout << "leaf node can not add child" << endl;
    }
    void removeChild(Node* n) override
    {
        cout << "leaf node can not remove child" << endl;
    }
    void display() override
    {
        cout << "display leaf node" << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
