/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-23 14:28:21
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-23 14:57:14
 */
#include <iostream>
#include <string>
#include <list>
using namespace std;
class Subject;

class Observer
{
protected:
    Subject *sub;
    string name;

public:
    Observer(Subject *s, string n) : sub(s), name(n)
    {
    }
    virtual void update() = 0;
};

class StockObserver : public Observer
{
public:
    StockObserver(Subject *s, string n) : Observer(s, n) {}
    virtual void update();
};

class NBAObserver : public Observer
{
public:
    NBAObserver(Subject *s, string n) : Observer(s, n) {}
    virtual void update();
};

class Subject
{
protected:
    list<Observer *> list_Observer;

public:
    string action;
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;
};

class Secretary : public Subject
{
public:
    virtual void attach(Observer *ob)
    {
        list_Observer.push_back(ob);
    }
    virtual void detach(Observer *ob)
    {
        list<Observer *>::iterator it = list_Observer.begin();
        while (it != list_Observer.end())
        {
            if (*it == ob)
            {
                list_Observer.erase(it);
                return;
            }
            it++;
        }
    }
    virtual void notify()
    {
        list<Observer *>::iterator it = list_Observer.begin();
        while (it != list_Observer.end())
        {
            (*it)->update();
            it++;
        }
    }
};

void StockObserver::update()
{
    cout << name << " revieve: " << sub->action << endl;
    if (sub->action == "Boss come!")
    {
        cout << "close Stock!" << endl;
    }
}
void NBAObserver::update()
{
    cout << name << " revieve: " << sub->action << endl;
    if (sub->action == "Boss come!")
    {
        cout << "close NBA!" << endl;
    }
}

int main()
{
    Subject *sub = new Secretary();
    Observer *deng = new StockObserver(sub, "deng");
    Observer *luo = new NBAObserver(sub, "luo");

    sub->attach(deng);
    sub->attach(luo);
    sub->action = "eat lunch";
    sub->notify();
    cout << endl;

    sub->action = "Boss come!";
    sub->notify();
    cout << endl;
    return 0;
}