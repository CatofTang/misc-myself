//一个能对ASCII编码的URL进行decode的小程序
#include<iostream>
#include<string>
#include<stdexcept>
#include<vector>
using namespace std;
int main(int argc, char *argv[])
{
    cout << endl;
    try
    {
        if(argc != 2)
            throw runtime_error("You have enter more than one arguments or input nothing!");

        string ch = argv[1];
        auto beg = ch.begin(), end = ch.end();
        while(beg != end)
        {
            if(*beg == '%'){
                vector<char> temp;
                //把%后两个字符读进来
                temp.push_back(*(beg+1));
                temp.push_back(*(beg+2));
                //初始化读出字符变量
                char cha = 0;
                /*高位处理*/
                if(temp[0] < 58)
                {
                    //cout << "<" << temp[0] << ">";
                    cha += (temp[0]%48) * 16;
                }
                else
                {
                    switch(temp[0])
                    {
                    case 'A':
                        cha += 10 * 16;
                        break;
                    case 'B':
                        cha += 11 * 16;
                        break;
                    case 'C':
                        cha += 12 * 16;
                        break;
                    case 'D':
                        cha += 13 * 16;
                        break;
                    case 'E':
                        cha += 14 * 16;
                        break;
                    case 'F':
                        cha += 15 * 16;
                        break;
                    }
                }
                /*高位处理结束*/
                /*低位处理*/
                if(temp[1] < 58)
                {
                    cha += (temp[1]%48);
                }
                else
                {
                    switch(temp[1])
                    {
                    case 'A':
                        cha += 10;
                        break;
                    case 'B':
                        cha += 11;
                        break;
                    case 'C':
                        cha += 12;
                        break;
                    case 'D':
                        cha += 13;
                        break;
                    case 'E':
                        cha += 14;
                        break;
                    case 'F':
                        cha += 15;
                        break;
                    }
                }
                /*低位处理结束*/
                cout << cha;//输出对应字符
                beg += 3;//移动至下一字符处，跳过%
            }
            else{
                cout << *beg;
                ++beg;
            }
        }
        cout << endl;
        return 0;
    }
    catch (const runtime_error &err)
    {
        cout << err.what() << endl;
        return -1;
    }
}
