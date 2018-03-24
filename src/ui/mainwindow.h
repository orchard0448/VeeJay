#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QLabel>
#include <QTime>
#include <QMenuBar>
#include <QTimer>
#include "RtMidi.h"
#include "Bridge.h"
#include "abstractfunction.h"
#include "functionmidi.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool eventFilter(QObject *, QEvent *);

    void resizeEvent(QResizeEvent *);


    AbstractFunction *midiControl;// = new FunctionMidi();

//private:
    Ui::MainWindow *ui;
    Bridge *bridge;
    QPixmap pxLedOn;
    QPixmap pxLedOff;
    QThread *workerThread;
    int scrollbackSize;
    double _pitchBend;
    QTimer debugListTimer;
    QStringList debugListMessages;

    void refresh();
    void refreshSerial();
    void refreshMidiIn();
    void refreshMidiOut();
    void refreshMidi(QComboBox *combo, RtMidi *midi);
    void midiSignal(double value);
    AbstractFunction* GetMidiControl(void);



private slots:
    void onValueChanged();
    void onDisplayMessage(QString message);
    void onDebugMessage(QString message);
    void onDebugClicked(bool value);
    void refreshDebugList();
    void showPreferences();
    void showAboutBox();

signals:
    void pitchBend(double value);
};

#endif // MAINWINDOW_H
