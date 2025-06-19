// 单例模式
// 饿汉与懒汉的区别是：饿汉在程序加载时实例化，懒汉在调用时实例化

#include <iostream>
#include <mutex>

using namespace std;

// 懒汉式（调用时才加载实例）
class Singleton1 {
public:
    static Singleton1& getInstance()
    {
        static Singleton1 ins;
        return ins;
    }
private:
    Singleton1() = default;
    ~Singleton1() = default;
};

// 饿汉式（程序加载时就初始化实例）
class Singleton2 {
public:
    static Singleton2& getInstance()
    {
        return m_ins;
    }
private:
    Singleton2() = default;
    ~Singleton2() = default;

    static Singleton2 m_ins;
};

Singleton2 Singleton2::m_ins;

// 懒汉式
// 线程不安全
class Singleton3 {
public:
    static Singleton3* getInstance()
    {
        static Singleton3* ins = new Singleton3;
        return ins;
    }
private:
    Singleton3() = default;
    ~Singleton3() = default;
};

// 懒汉式
// 线程安全 双重锁定
class Singleton4 {
public:
    static Singleton4* getInstance()
    {
        static Singleton4* ins = nullptr;
        if (ins == nullptr)
        {
            lock_guard<mutex> mtx(m_mtx);
            if (ins == nullptr)
            {
                ins = new Singleton4;
            }
        }
        return ins;
    }
private:
    Singleton4() = default;
    ~Singleton4() = default;

    static mutex m_mtx;
};

mutex Singleton4::m_mtx;

// 饿汉式
// 线程不安全
class Singleton5 {
public:
    Singleton5* getInstance()
    {
        return m_ins;
    }
private:
    Singleton5() = default;
    ~Singleton5() = default;

    static Singleton5* m_ins;
};

Singleton5* Singleton5::m_ins = new Singleton5;

int main()
{
    std::cout << "Hello World!\n";
}
