/*
 * @Author: your name
 * @Date: 2021-12-15 22:46:27
 * @LastEditTime: 2021-12-15 22:58:38
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \vsomeip-masterf:\cpp\leetcode\学习心得\设计模式\观察者模式\self\MainForm.cpp
 */
class Form
{
};
class MainForm : public Form, public IProgress
{
public:
    string m_filepath;
    int m_filenum;
    Progressbar *progressbar;
    virtual void DoProgress(float val)
    {
        progressbar->setValue(val);
    }
    void onProgressbar(float val){};
    MainForm()
    {
        FileSpliter filespliter(m_filepath, m_filenum);
        filespliter.addIProgress(this);
        ConsoleNotifier cn;
        filespliter.addIProgress(&cn);
    }
};
class ConsoleNotifier : public IProgress
{
    virtual void DoProgress(float val)
    {
        cout << "..." << endl;
    }
};