#include <QCoreApplication>
#include <iostream>
#include <QDebug>

using namespace std;

typedef class{
public:
    int num;
    string name;
    int core1;
    int core2;
}stu;
void display(QVector<stu> *data)
{
    cout<<"学号"<<"          "<<"姓名"<<"     "<<"课程1"<<"   "<<"课程2"<<endl;
    for(QVector<stu>::iterator m=data->begin();m!=data->end();m++)
    {
        cout<<m->num<<"    "<<m->name<<"     "<<m->core1<<"    "<<m->core2<<endl;
        //qDebug<<*m<<"\0";
    }
    cout<<endl;
}
bool c_name(stu a,stu b)
{
    if(a.name>=b.name)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
bool c_core1(stu a,stu b)
{
    if(a.core1>=b.core1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
bool c_core2(stu a,stu b)
{
    if(a.core2>=b.core2)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    stu stu1,stu2,stu3,stu4;
    stu1.num=1403130209;
    stu1.name="鲁智深";
    stu1.core1=80;
    stu1.core2=72;

    stu2.num=1403140101;
    stu2.name="林冲  ";
    stu2.core1=82;
    stu2.core2=76;

    stu3.num=1403140102;
    stu3.name="宋江  ";
    stu3.core1=76;
    stu3.core2=85;

    stu4.num=140314010;
    stu4.name=" 武松  ";
    stu4.core1=88;
    stu4.core2=80;
    QVector<stu> data;
    data.push_back(stu1);
    data.push_back(stu2);
    data.push_back(stu3);
    data.push_back(stu4);
    cout<<"初始列表为：\n";
    display(&data);
    QVector<stu> s_name=data;
    sort(s_name.begin(),s_name.end(),c_name);
    cout<<"按姓名排序"<<endl;
    display(&s_name);
    QVector<stu> s_core1=data;
    sort(s_core1.begin(),s_core1.end(),c_core1);
    cout<<"按课程1排序"<<endl;
    display(&s_core1);
    QVector<stu> s_core2=data;
    sort(s_core2.begin(),s_core2.end(),c_core2);
    cout<<"按课程2排序"<<endl;
    display(&s_core2);

    return a.exec();
}
