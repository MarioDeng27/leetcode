/*
 * @Author: your name
 * @Date: 2021-12-15 22:32:22
 * @LastEditTime: 2021-12-15 22:56:42
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \vsomeip-masterf:\cpp\leetcode\学习心得\设计模式\观察者模式\self\FileSpliter.cpp
 */

class IProgress
{
public:
    virtual void DoProgress(float val) = 0;
    virtual ~IProgress(){}
};
class FileSpliter
{
public:
    string m_filePath;
    int m_fileNum;
    List<IProgress *> IProgressList;
    FileSpliter(string filepath, int filenum) : m_filePath(filepath), m_fileNum(filenum) {}
    void DoWork()
    {
        //1.读取大文件

        //2.分批向小文件中写入
        for (int i = 0; i < m_fileNum; i++)
        {
            //...
            float m_val = m_fileNum;
            onProgress((i + 1) / m_val);
        }
    }
    void addIProgress(IProgress *iprogress)
    {
        IProgressList.push_back(iprogress);
    }
    void removeIProgress(IProgress *iprogress)
    {
        IProgressList.remove(iprogress);
    }

protected:
    virtual void onProgress(float val)
    {
        for (auto itor = IProgressList.begin(); itor != IProgressList.end(); itor++)
        {
            itor->DoProgress(val);
        }
    }
};