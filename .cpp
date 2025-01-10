#include <iostream>
#include <cstring>
using namespace std;

//设置phone类
class phone {
private:
    char number[12];
    char city[5];
    double fee;

public:

    phone()
    {
        strcpy_s(number, "08600000000");
        strcpy_s(city, "***");
        fee = 0;
    }
    void recharge(double input);
    void insertcard(const char number[], const char city[]);
    double getfee() { return fee; };
    char* getno() { return number; };
    char* getcity() { return city; };
    int call(phone& other, int m);

};

int phone::call(phone& other, int m)
{
    int t = 0;
    double sfee, ofee;
    if (strcmp(city, other.getcity()) == 0)
    {
        sfee = 0.7;
        
        for (t = 0; t < m; t++)
        {

            if (fee < 0.7) return t - 1;
            fee-=sfee;
        }

    }
    else
    {
        sfee = 1.2, ofee = 0.7;
        
        for (t = 0; t < m; t++)
        {

            if ( fee<1.2 ||  other.fee<0.7) return t-1;
            fee -= sfee;
            other.fee -= ofee;
        }

    }
    return m;
}

void phone::recharge(double input)
{
    fee += input;
}
void phone::insertcard(const char numberin[], const char cityin[])
{
    strcpy_s(number, numberin);
    strcpy_s(city, cityin);
}
void display(phone& t)
{
    cout << "手机号码：" << t.getno()
        << "；归属地：" << t.getcity()
        << "；话费余额：" << t.getfee()
        << endl;
}

int main()
{
    phone p1;
    display(p1);
    p1.insertcard("13458901211", "027");      p1.recharge(40);
    phone p2, p3;
    p2.insertcard("13652901219", "021");      p2.recharge(30);
    p3.insertcard("15651004523", "027");      p3.recharge(50);
    int talk, m;
    m = 35;
    talk = p1.call(p2, m);
    const char* line = "*-------------------------------------------------*";
    cout << line << endl;
    cout << "p1主叫p2......." << endl;
    if (talk == m)
        cout << "通话时长" << talk << "分钟。通话结束,祝您愉快" << endl;
    else
        cout << "通话时长" << talk << "分钟。余额不足,请尽快预存话费" << endl;
    display(p1);
    display(p2);
    cout << line << endl;
    p1.recharge(30);
    m = 40;
    talk = p3.call(p1, 40);
    cout << line << endl;
    cout << "p3主叫p1......." << endl;
    if (talk == m)
        cout << "通话时长" << talk << "分钟。通话结束,祝您愉快........" << endl;

    else

        cout << "通话时长" << talk << "分钟。电话余额不足.......请尽快预存话费." << endl;;

    display(p3); display(p1);

    cout << line << endl;

    return 0;

}
