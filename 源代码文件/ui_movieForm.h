/********************************************************************************
** Form generated from reading UI file 'movieForm.ui'
**
** Created: Fri Nov 29 20:41:47 2019
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOVIEFORM_H
#define UI_MOVIEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mplayer
{
public:
    QWidget *movieForm;
    QPushButton *addBtn;
    QPushButton *delBtn;
    QPushButton *nextBtn;
    QPushButton *playBtn;
    QPushButton *preBtn;
    QPushButton *speedBtn;
    QPushButton *stopBtn;
    QPushButton *timeBtn;
    QSlider *currentlBar;
    QSlider *volumeSlider;
    QLabel *timeLabel;
    QLabel *view2;
    QListWidget *list;
    QFrame *frame;
    QLabel *view;
    QLabel *label;

    void setupUi(QMainWindow *mplayer)
    {
        if (mplayer->objectName().isEmpty())
            mplayer->setObjectName(QString::fromUtf8("mplayer"));
        mplayer->resize(600, 400);
        movieForm = new QWidget(mplayer);
        movieForm->setObjectName(QString::fromUtf8("movieForm"));
        addBtn = new QPushButton(movieForm);
        addBtn->setObjectName(QString::fromUtf8("addBtn"));
        addBtn->setGeometry(QRect(459, 274, 60, 27));
        delBtn = new QPushButton(movieForm);
        delBtn->setObjectName(QString::fromUtf8("delBtn"));
        delBtn->setGeometry(QRect(528, 274, 60, 27));
        nextBtn = new QPushButton(movieForm);
        nextBtn->setObjectName(QString::fromUtf8("nextBtn"));
        nextBtn->setGeometry(QRect(234, 353, 60, 27));
        playBtn = new QPushButton(movieForm);
        playBtn->setObjectName(QString::fromUtf8("playBtn"));
        playBtn->setGeometry(QRect(17, 353, 60, 27));
        preBtn = new QPushButton(movieForm);
        preBtn->setObjectName(QString::fromUtf8("preBtn"));
        preBtn->setGeometry(QRect(162, 353, 60, 27));
        speedBtn = new QPushButton(movieForm);
        speedBtn->setObjectName(QString::fromUtf8("speedBtn"));
        speedBtn->setGeometry(QRect(491, 369, 92, 27));
        stopBtn = new QPushButton(movieForm);
        stopBtn->setObjectName(QString::fromUtf8("stopBtn"));
        stopBtn->setGeometry(QRect(89, 353, 60, 27));
        timeBtn = new QPushButton(movieForm);
        timeBtn->setObjectName(QString::fromUtf8("timeBtn"));
        timeBtn->setGeometry(QRect(491, 341, 92, 27));
        currentlBar = new QSlider(movieForm);
        currentlBar->setObjectName(QString::fromUtf8("currentlBar"));
        currentlBar->setGeometry(QRect(10, 323, 581, 20));
        currentlBar->setOrientation(Qt::Horizontal);
        volumeSlider = new QSlider(movieForm);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setGeometry(QRect(354, 357, 121, 20));
        volumeSlider->setSingleStep(1);
        volumeSlider->setValue(60);
        volumeSlider->setOrientation(Qt::Horizontal);
        timeLabel = new QLabel(movieForm);
        timeLabel->setObjectName(QString::fromUtf8("timeLabel"));
        timeLabel->setGeometry(QRect(460, 310, 131, 20));
        view2 = new QLabel(movieForm);
        view2->setObjectName(QString::fromUtf8("view2"));
        view2->setGeometry(QRect(312, 358, 41, 17));
        list = new QListWidget(movieForm);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(459, 34, 130, 231));
        frame = new QFrame(movieForm);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(18, 17, 425, 300));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        view = new QLabel(frame);
        view->setObjectName(QString::fromUtf8("view"));
        view->setGeometry(QRect(9, 11, 405, 280));
        label = new QLabel(movieForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(495, 14, 62, 17));
        mplayer->setCentralWidget(movieForm);

        retranslateUi(mplayer);

        QMetaObject::connectSlotsByName(mplayer);
    } // setupUi

    void retranslateUi(QMainWindow *mplayer)
    {
        mplayer->setWindowTitle(QApplication::translate("mplayer", "mplayer", 0, QApplication::UnicodeUTF8));
        addBtn->setText(QApplication::translate("mplayer", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        delBtn->setText(QApplication::translate("mplayer", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        nextBtn->setText(QApplication::translate("mplayer", "\344\270\213\344\270\200\344\270\252", 0, QApplication::UnicodeUTF8));
        playBtn->setText(QApplication::translate("mplayer", "\346\222\255\346\224\276", 0, QApplication::UnicodeUTF8));
        preBtn->setText(QApplication::translate("mplayer", "\344\270\212\344\270\200\344\270\252", 0, QApplication::UnicodeUTF8));
        speedBtn->setText(QApplication::translate("mplayer", "\346\222\255\346\224\276\351\200\237\345\272\246", 0, QApplication::UnicodeUTF8));
        stopBtn->setText(QApplication::translate("mplayer", "\345\201\234\346\255\242", 0, QApplication::UnicodeUTF8));
        timeBtn->setText(QApplication::translate("mplayer", "\346\227\266\351\227\264\350\267\263\350\275\254", 0, QApplication::UnicodeUTF8));
        timeLabel->setText(QString());
        view2->setText(QApplication::translate("mplayer", "\351\237\263\351\207\217\357\274\232", 0, QApplication::UnicodeUTF8));
        view->setText(QString());
        label->setText(QApplication::translate("mplayer", "\346\222\255\346\224\276\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mplayer: public Ui_mplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOVIEFORM_H
