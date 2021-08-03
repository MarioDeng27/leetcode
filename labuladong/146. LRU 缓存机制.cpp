/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-03 21:14:51
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-03 21:15:11
 */
struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key, int value) : key(key), value(value) {}
};

class DoubleList
{
private:
    int size;
    Node *head;
    Node *tail;

public:
    DoubleList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addLast(Node *node)
    {
        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
        size++;
    }
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    Node *removeBegin()
    {
        Node *node = head->next;
        remove(node);
        return node;
    }
    int getSize()
    {
        return size;
    }
};

class LRUCache
{
private:
    DoubleList *doubleList;
    map<int, Node *> mp;
    int capacity;

public:
    LRUCache(int size)
    {
        doubleList = new DoubleList();
        capacity = size;
    }
    /*makeRecently，addRecently，deleteKey，deleteLeastRecently四个函数封装了对DoubleList以及map的增删改，让get和set不需要在函数体里以Node为数据去创建和删除记录*/
    //LRU里一定存在该node
    void makeRecently(int key)
    {
        Node *node = mp[key];
        doubleList->remove(node);
        doubleList->addLast(node);
    }
    void addRecently(int key, int value)
    {
        Node *node = new Node(key, value);
        doubleList->addLast(node);
        mp[node->key] = node;
    }
    void deleteKey(int key)
    {
        Node *node = mp[key];
        doubleList->remove(node);
        mp.erase(node->key);
    }
    void deleteLeastRecently()
    {
        Node *node = doubleList->removeBegin();
        mp.erase(node->key);
    }
    /*makeRecently，addRecently，deleteKey，deleteLeastRecently四个函数封装了对DoubleList以及map的增删改，让get和set不需要在函数体里以Node为数据去创建和删除记录*/
    int get(int key)
    {
        if (mp.count(key) == 1)
        {
            makeRecently(key);
            return mp[key]->value;
        }
        return -1;
    }
    void put(int key, int value)
    {
        if (mp.count(key) == 1)
        {
            deleteKey(key);
        }
        if (capacity == doubleList->getSize())
        {
            deleteLeastRecently();
        }
        addRecently(key, value);
    }
};