#ifndef MOVIEFORM_H
#define MOVIEFORM_H

#include <QMainWindow>
#include <QProcess>
#include <QtGui>

namespace Ui {
    class mplayer;
}

class mplayer : public QMainWindow {
    Q_OBJECT
public:
    mplayer(QWidget *parent = 0);
    ~mplayer();
    void play(QString fileName);

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_nextBtn_clicked();

    void on_preBtn_clicked();

    void on_addBtn_clicked();

    void on_delBtn_clicked();

    void on_playBtn_clicked();

    void on_stopBtn_clicked();

    void on_timeBtn_clicked();

    void on_speedBtn_clicked();

    void on_list_itemDoubleClicked(QListWidgetItem *item);

    void on_currentlBar_sliderMoved(int value);

    void on_volumeSlider_sliderMoved(int v);

    void dataRecieve();

    void sureBtnClicked();

private:
        Ui::mplayer *ui;
        QSpinBox *minBox;
        QSpinBox *secBox;
        QString currentPercent;
        QProcess *p;
        QString currentStr;
        QString totalTime;
};

#endif // MOVIEFORM_H
