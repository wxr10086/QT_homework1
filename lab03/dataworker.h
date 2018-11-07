#ifndef DATAWORKER_H
#define DATAWORKER_H

#include <QObject>
#include <QDateTime>

class QNetworkAccessManager;
class QNetworkReply;

class dataWorker : public QObject
{
    Q_OBJECT
public:
    explicit dataWorker(QObject *parent = nullptr);
    explicit dataWorker(QString date, QObject *parent = 0);
    void setRequestDate(QString newDate);
    void setRequestCity(QString newCity);

    void setSwitchNum(int num);
    int switch_Num;
    QString requestDate();
    QString requestCity();
    void doRequest();
protected:
    QString requestUrl();
    void httpGet(QString url);
    void initNetwork();
    void parseHTML(const QString sourceText);
    void parseData(const QString sourceText);
    void exportDataToFile(const QString dataText);
protected slots:
   void httpsFinished(QNetworkReply *reply);
private:
   QNetworkAccessManager *manager;         //!< 网络访问管理类对象
   QString _requestDate;                   //!< 请求年月
   QString _requestCity;                   //!<请求城市

   QList<QDateTime> dataDate;              //!< 日期
   QList<qreal> dataHigh;                  //!< 最高温度
   QList<qreal> dataLow;                   //!< 最低温度
   QList<qreal> dataAQI;
   QList<qreal> dataPM25;

   const QString splitter;                 //!< 数据分隔符
   const QString dataPath;                 //!< 数据保存路径



signals:
    void dataParseFinished(QList<QDateTime> date ,QList<qreal> high, QList<qreal> low);
    //void dataParseError(QString error);
    //void httpRequestError(QString error);
public slots:


};

#endif // DATAWORKER_H
