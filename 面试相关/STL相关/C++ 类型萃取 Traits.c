/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-02 16:50:12
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-02 16:50:13
 */
/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-09-02 16:50:12
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-09-02 16:50:12
 */
template <typename T>
struct TypeTraits
{
    static const int data_type = 0; //这里的static非常关键
};

template <>
struct TypeTraits<char>
{
    static const int data_type = 1;
};

template <>
struct TypeTraits<int>
{
    static const int data_type = 1;
};

template <>
struct TypeTraits<float>
{
    static const int data_type = 2;
};

template <>
struct TypeTraits<double>
{
    static const int data_type = 2;
};

//没有偏特化为1或2的情况走下面的operator
template <int data_type>
class TypeGroup
{
public:
    template <typename T>
    string operator()(T &t)
    {
        cout << "default: " << t << endl;
        return "0";
    }
};

//char 或者 int 走下面的code
template <>
class TypeGroup<1>
{
public:
    template <typename T>
    string operator()(T &t)
    {
        cout << "int/char: " << (int)t << endl;
        return "1";
    }
};

//double走下面的code
template <>
class TypeGroup<2>
{
public:
    template <typename T>
    string operator()(T &t)
    {
        cout << "double: " << setprecision(2) << t << endl;
        return "2";
    }
};

template <typename T>
class Test
{
public:
    void operator()(T t)
    {
        TypeGroup<TypeTraits<T>::data_type> test;
        test(t);
    }
};

int main()
{

    TypeTraits<int> a;
    cout << a.data_type << endl;
    TypeTraits<double> b;
    cout << b.data_type << endl;
    TypeTraits<string> c;
    cout << c.data_type << endl;

    Test<char> d;
    d(10);
    Test<double> e;
    e(3.1415);
    Test<string> f;
    f("hello world!");

    return 0;
}