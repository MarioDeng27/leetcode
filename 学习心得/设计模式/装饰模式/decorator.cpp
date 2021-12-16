// #include <iostream>
// using namespace std;
//业务操作
class Stream
{
public:
    virtual void Read(int number) = 0;
    virtual void Seek(int position) = 0;
    virtual void Write(char data) = 0;

    virtual ~Stream() {}
};

//主体类
class FileStream : public Stream
{
public:
    virtual void Read(int number)
    {
        //读文件流
        cout << "FileStream "
             << "Read" << endl;
    }
    virtual void Seek(int position)
    {
        //定位文件流
        cout << "FileStream "
             << "Seek" << endl;
    }
    virtual void Write(char data)
    {
        //写文件流
        cout << "FileStream "
             << "Write" << endl;
    }
};

class NetworkStream : public Stream
{
public:
    virtual void Read(int number)
    {
        //读网络流
        cout << "NetworkStream "
             << "Read" << endl;
    }
    virtual void Seek(int position)
    {
        //定位网络流
        cout << "NetworkStream "
             << "Seek" << endl;
    }
    virtual void Write(char data)
    {
        //写网络流
        cout << "NetworkStream "
             << "Write" << endl;
    }
};

class MemoryStream : public Stream
{
public:
    virtual void Read(int number)
    {
        //读内存流
        cout << "MemoryStream "
             << "Read" << endl;
    }
    virtual void Seek(int position)
    {
        //定位内存流
        cout << "MemoryStream "
             << "Seek" << endl;
    }
    virtual void Write(char data)
    {
        //写内存流
        cout << "MemoryStream "
             << "Write" << endl;
    }
};

//扩展操作

class DecoratorStream : public Stream
{
protected:
    Stream *stream; //...

    DecoratorStream(Stream *stm) : stream(stm)
    {
    }
};

class CryptoStream : public DecoratorStream
{

public:
    CryptoStream(Stream *stm) : DecoratorStream(stm)
    {
    }

    virtual void Read(int number)
    {

        //额外的加密操作...
        cout << "with Crypto ";
        stream->Read(number); //读文件流
    }
    virtual void Seek(int position)
    {
        //额外的加密操作..
        cout << "with Crypto ";
        stream->Seek(position); //定位文件流
        //额外的加密操作...
    }
    virtual void Write(char data)
    {
        //额外的加密操作...
        cout << "with Crypto ";
        stream->Write(data); //写文件流
        //额外的加密操作...
    }
};

class BufferedStream : public DecoratorStream
{

public:
    BufferedStream(Stream *stm) : DecoratorStream(stm)
    {
    }
    //...
    virtual void Read(int number)
    {

        //额外的加密操作...
        cout << "with Buffer ";
        stream->Read(number); //读文件流
    }
    virtual void Seek(int position)
    {
        //额外的加密操作..
        cout << "with Buffer ";
        stream->Seek(position); //定位文件流
        //额外的加密操作...
    }
    virtual void Write(char data)
    {
        //额外的加密操作...
        cout << "with Buffer ";
        stream->Write(data); //写文件流
        //额外的加密操作...
    }
};

void Process()
{

    //运行时装配
    FileStream *s1 = new FileStream();

    CryptoStream *s2 = new CryptoStream(s1);

    BufferedStream *s3 = new BufferedStream(s1);

    BufferedStream *s4 = new BufferedStream(s2);

    CryptoStream *s5 = new CryptoStream(s4);

    s1->Read(1);
    s2->Seek(2);
    s2->Write('a');
    s3->Write('a');
    s4->Read(2);
    s5->Read(3);
}
int main()
{
    Process();
    return 0;
}