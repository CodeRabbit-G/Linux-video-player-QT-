#include "movieForm.h"
#include "ui_movieForm.h"
#include <QtGui>

mplayer::mplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mplayer)
{
    ui->setupUi(this);
    setWindowTitle("视频播放器");
    p=new QProcess(this);
    connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
    ui->timeLabel->setAlignment(Qt::AlignRight);
}

mplayer::~mplayer()
{
    delete ui;
}

void mplayer::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void mplayer::on_nextBtn_clicked()
{
    if(ui->list->currentRow()==ui->list->count()-1)
        ui->list->setCurrentRow(0);
    else
        ui->list->setCurrentRow(ui->list->currentRow()+1);
        play(ui->list->currentItem()->text());
        ui->playBtn->setText("暂停");
}

void mplayer::on_preBtn_clicked()
{
    if(ui->list->currentRow()==0)
        ui->list->setCurrentRow(ui->list->count()-1);
    else
        ui->list->setCurrentRow(ui->list->currentRow()-1);
        play(ui->list->currentItem()->text());
        ui->playBtn->setText("暂停");
}

void mplayer::on_addBtn_clicked()
{
    QStringList fileNames=QFileDialog::getOpenFileNames(this,"choose movies","/","Movie (*.m4v *.mp4 *.avi *.wmv *.mpg)");
    if(fileNames.count()!=0)
        ui->list->addItems(fileNames);
}

void mplayer::on_delBtn_clicked()
{
    if(ui->list->currentRow()==-1)
       QMessageBox::warning(this,"提示","未选中项目或列表为空",QMessageBox::Yes);
    else
     ui->list->takeItem(ui->list->currentRow());
}

void mplayer::on_list_itemDoubleClicked(QListWidgetItem *item)
{
    play(item->text());
    ui->playBtn->setText("暂停");
}

void mplayer::play(QString fileName)
{
    QStringList args;
    p->kill();
    p=new QProcess(this);
    connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
    args<<"-slave";
    args<<"-quiet";
    args<<"-wid"<<QString::number(ui->view->winId(),10);
    args<<"-zoom";
    args<<"-x";
    args<<"370";
    args<<"-y";
    args<<"335";
    args<<"-vo";
    args<<"x11";
    args<<fileName;
    p->start("mplayer",args);
    ui->playBtn->setEnabled(true);
    ui->stopBtn->setEnabled(true);
}

void mplayer::on_playBtn_clicked()
{

    p->write("pause\n");
    if(ui->playBtn->text()=="播放")
    {
        connect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
        p->write("get_time_length\n");
        p->write("get_time_pos\n");
        p->write("get_percent_pos\n");
        ui->playBtn->setText("暂停");
    }
    else
    {
        disconnect(p,SIGNAL(readyReadStandardOutput()),this,SLOT(dataRecieve()));
        ui->playBtn->setText("播放");
    }
}

void mplayer::on_stopBtn_clicked()
{
    p->write("quit\n");
    ui->timeLabel->clear();
}

void mplayer::on_volumeSlider_sliderMoved(int v)
{
    p->write(QString("volume "+QString::number(v)+" 2\n").toUtf8());
}

void mplayer::on_speedBtn_clicked()
{
    double speed=QInputDialog::getDouble(this,"播放速度设置","相对于正常速度倍数:");
    if(speed>0)
    p->write(QString("speed_set "+QString::number(speed)+" 2\n").toUtf8());
}

void mplayer::dataRecieve()
{
    p->write("get_time_length\n");
    p->write("get_time_pos\n");
    p->write("get_percent_pos\n");
    while(p->canReadLine())
    {
        QByteArray b=p->readLine();
        if(b.startsWith("ANS_TIME_POSITION"))
        {
            b.replace(QByteArray("\n"),QByteArray(""));
            QString s(b);
            currentStr=s.mid(18);
            ui->currentlBar->setValue(s.mid(18).toFloat());    //更新进度条
        }
        else if((b.startsWith("ANS_LENGTH")))
        {
            b.replace(QByteArray("\n"),QByteArray(""));
            QString s(b);
            totalTime=s.mid(11);
            ui->timeLabel->setText(currentStr+"s/"+totalTime+"s"); //显示时间进度
            ui->currentlBar->setRange(0,s.mid(11).toFloat());
        }
        else if((b.startsWith("ANS_PERCENT_POSITION")))
        {
            b.replace(QByteArray("\n"),QByteArray(""));
            QString s(b);
            currentPercent=s.mid(21);
        }
    }
}

void mplayer::on_currentlBar_sliderMoved(int value)
{
    p->write(QString("seek "+QString::number(value)+" 2\n").toUtf8());

}

void mplayer::on_timeBtn_clicked()
{
    QDialog *timeDialog=new QDialog(this);
    timeDialog->resize(300,100);
    minBox=new QSpinBox(timeDialog);
    minBox->setGeometry(QRect(20,20,50,30));
    QLabel *minLabel=new QLabel("分",timeDialog);
    minLabel->setGeometry(QRect(80,20,20,30));

    secBox=new QSpinBox(timeDialog);
    secBox->setGeometry(QRect(100,20,50,30));
    QLabel *secLabel=new QLabel("秒",timeDialog);
    secLabel->setGeometry(QRect(150,20,30,30));

    QPushButton *sureBtn=new QPushButton("确定",timeDialog);
    sureBtn->setGeometry(QRect(180,20,70,30));
    connect(sureBtn,SIGNAL(clicked()),this,SLOT(sureBtnClicked()));
    timeDialog->show();
}

void mplayer::sureBtnClicked()
{
    int jumpTime=minBox->value()*60+secBox->value();
    p->write(QString("seek "+QString::number(jumpTime)+" 2\n").toUtf8());
}

