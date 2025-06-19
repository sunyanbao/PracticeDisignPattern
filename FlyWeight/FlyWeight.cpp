// 享元模式
// 当程序需要创建大量相似的对象时，考虑用

#include <iostream>
#include <map>

using namespace std;

class TextGlyph {

};

class Text {
public:
    Text(char c) : m_c(c)
    {

    }

    void print()
    {
        cout << m_c << endl;
    }

private:
    char m_c;
    TextGlyph m_glyph;
};

class TextFactory {
public:
    Text* getText(char c)
    {
        auto&& text = m_texts[c];
        if (text == nullptr)
        {
            cout << "create new text:" << c << endl;
            text = new Text(c);
        }
        return text;
    }

private:
    map<char, Text*> m_texts;
};

int main()
{
    TextFactory fac;
    auto text = fac.getText('a');
    text->print();
    text = fac.getText('b');
    text->print();
    text = fac.getText('a');
    text->print();
}
