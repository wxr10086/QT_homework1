#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include<cstdio>
#include<climits>
using namespace std;

#define v 0x12345678
#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )
#define LLO(xxx)  ((quint8) ((quint32)(xxx) & 255))
#define HLO(xxx)  ((quint8) ((quint32)(xxx) >> 8))
#define LHI(xxx)  ((quint8) ((quint32)(xxx) >> 16))
#define HHI(xxx)  ((quint8) ((quint32)(xxx) >> 24))
int main(int argc,char *argv[])
{   int new_v;
    QList <quint8> values;
    values.append(HHI(v));
    values.append(LHI(v));
    values.append(HLO(v));
    values.append(LLO(v));
    qDebug()<<values;
    qDebug("最高和次高8位最大值：0x%x",MAX(values.at(0),values.at(1)));
    qDebug("最低和次低8位最小值：0x%x",MIN(values.at(2),values.at(3)));
    new_v=(values.at(2)<<24)+(values.at(0)<<16)+(values.at(3)<<8)+(values.at(1));
    qDebug("合成新的32位无符号整形数位0x%x(%d)",new_v,new_v);
    std::sort(values.begin(),values.end(),greater<quint8>());
    qDebug("排序后(0x%x,0x%x,0x%x,0x%x),(%d,%d,%d,%d)",values.at(0),values.at(1),values.at(2),values.at(3),values.at(0),values.at(1),values.at(2),values.at(3));
}
