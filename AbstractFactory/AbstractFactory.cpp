// 抽象工厂
// 有多种对象需要创建，且这多种对象又分为多种方式创建

#include <iostream>

using namespace std;

class IUser {

};

class SqlserverUser : public IUser {

};

class OracleUser :public IUser {

};

class IProduct {

};

class SqlserverProduct :public IProduct {

};

class OracleProduct :public IProduct {

};

class Factory {
public:
    virtual IUser* createUser() = 0;
    virtual IProduct* createProduct() = 0;
};

class SqlserverFactory :public Factory {
public:
    IUser* createUser() override
    {
        return new SqlserverUser;
    }
    IProduct* createProduct() override
    {
        return new SqlserverProduct;
    }
};

class OracleFactory : public Factory {
public:
    IUser* createUser() override
    {
        return new OracleUser;
    }
    IProduct* createProduct() override
    {
        return new SqlserverProduct;
    }
};

int main()
{
    Factory* fac = new OracleFactory;
    IUser* user = fac->createUser();
    IProduct* product = fac->createProduct();
}
