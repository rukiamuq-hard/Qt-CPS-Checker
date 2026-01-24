#ifndef CLICKER_H
#define CLICKER_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QVBoxLayout>
#include <QTime>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Clicker; }
QT_END_NAMESPACE

class Clicker : public QMainWindow
{
    Q_OBJECT

public:
    Clicker(QWidget *parent = nullptr);
    ~Clicker();

private slots:
    void on_ClickButton_clicked();
    void startTimer();
    void CPSfunc();

private:
    Ui::Clicker *ui;
    uint16_t CLICKS = 0;
    uint16_t timerTime = 10;
    QTimer* timer = new QTimer(this);
    QTime curTime;
    QString strInptFrLine;
};
#endif // CLICKER_H
