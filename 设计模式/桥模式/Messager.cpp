/*
 * @Author: your name
 * @Date: 2021-12-16 19:32:12
 * @LastEditTime: 2021-12-16 20:27:35
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \test-asusf:\cpp\leetcode\学习心得\设计模式\桥模式\Messager.cpp
 */
#include <bits/stdc++.h>
using namespace std;
class MessagerImp;
class Messager
{
protected:
    MessagerImp *messagerImp; //...
public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(int image) = 0;
    Messager(MessagerImp *messagerImp) : messagerImp(messagerImp) {}
    virtual ~Messager() {}
};

class MessagerImp
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() {}
};

//平台实现 n
class PCMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //**********
        cout << "PCMessagerImp "
             << "PlaySound()" << endl;
    }
    virtual void DrawShape()
    {
        //**********
        cout << "PCMessagerImp "
             << "DrawShape()" << endl;
    }
    virtual void WriteText()
    {
        //**********
        cout << "PCMessagerImp "
             << "WriteText()" << endl;
    }
    virtual void Connect()
    {
        //**********
        cout << "PCMessagerImp "
             << "Connect()" << endl;
    }
};

class MobileMessagerImp : public MessagerImp
{
public:
    virtual void PlaySound()
    {
        //==========
        cout << "MobileMessagerImp "
             << "PlaySound()" << endl;
    }
    virtual void DrawShape()
    {
        //==========
        cout << "MobileMessagerImp "
             << "DrawShape()" << endl;
    }
    virtual void WriteText()
    {
        //==========
        cout << "MobileMessagerImp "
             << "WriteText()" << endl;
    }
    virtual void Connect()
    {
        //==========
        cout << "MobileMessagerImp "
             << "Connect()" << endl;
    }
};

//业务抽象 m

//类的数目：1+n+m

class MessagerLite : public Messager
{

public:
    MessagerLite(MessagerImp *_messagerImp) : Messager(_messagerImp) {}
    virtual void Login(string username, string password)
    {
        cout << "On MessagerLite ";
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {
        cout << "On MessagerLite ";
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(int image)
    {
        cout << "On MessagerLite ";
        messagerImp->DrawShape();
        //........
    }
};

class MessagerPerfect : public Messager
{

public:
    MessagerPerfect(MessagerImp *_messagerImp) : Messager(_messagerImp) {}
    virtual void Login(string username, string password)
    {
        cout << "On MessagerPerfect ";
        messagerImp->PlaySound();
        //********
        messagerImp->Connect();
        //........
    }
    virtual void SendMessage(string message)
    {
        cout << "On MessagerPerfect ";
        messagerImp->PlaySound();
        //********
        messagerImp->WriteText();
        //........
    }
    virtual void SendPicture(int image)
    {
        cout << "On MessagerPerfect ";
        messagerImp->PlaySound();
        //********
        messagerImp->DrawShape();
        //........
    }
};

void Process()
{
    //运行时装配
    MessagerImp *mImp = new PCMessagerImp();
    Messager *m = new MessagerPerfect(mImp);
    m->Login("a", "b");
    m->SendMessage("a");
    m->SendPicture(1);
}

int main()
{
    Process();
    return 0;
}
