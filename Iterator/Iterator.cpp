// 迭代器模式
// 应用场景：当需要对一个聚合对象的所有元素进行遍历时

#include <iostream>
#include <vector>

using namespace std;

class Element {
public:
    void setVal(int val)
    {
        m_val = val;
    }

    int value() const
    {
        return m_val;
    }

private:
    int m_val = 0;
};

class Iterator {
public:
    virtual Element* begin() = 0;
    virtual Element* next() = 0;
    virtual bool isDone() = 0;
    virtual Element* current() = 0;
};

class Container {
public:
    virtual void add(Element* ele) = 0;
    virtual void erase(Element* ele) = 0;
    virtual Element* at(int i) = 0;
    virtual int size() = 0;

    virtual Iterator* createIterator() = 0;
};

class VecIterator :public Iterator {
public:
    VecIterator(Container* con) : m_con(con)
    {
    }
    Element* begin() override
    {
        return m_con->at(m_cur);
    }
    Element* next() override
    {
        m_cur++;
        return m_con->at(m_cur);
    }
    bool isDone() override
    {
        return m_cur == m_con->size();
    }
    Element* current() override
    {
        return m_con->at(m_cur);
    }

private:
    Container* m_con = nullptr;
    int m_cur = 0;
};

class VecContainer : public Container{
public:
    void add(Element* ele) override
    {
        m_vec.push_back(ele);
    }
    void erase(Element* ele) override
    {
        m_vec.erase(find(m_vec.begin(),m_vec.end(),ele));
    }
    Element* at(int i) override
    {
        return m_vec[i];
    }

    int size() override
    {
        return m_vec.size();
    }

    Iterator* createIterator() override
    {
        return new VecIterator(this);
    }

private:
    vector<Element*> m_vec;
};

int main()
{
    std::cout << "Hello World!\n";
}

