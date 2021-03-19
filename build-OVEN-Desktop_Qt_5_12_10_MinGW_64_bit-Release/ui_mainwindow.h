/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupbox_connection;
    QPushButton *button_connect;
    QLineEdit *lineedit_comport;
    QLabel *label_comport;
    QComboBox *combobox_baudrate;
    QLabel *label_baudrate;
    QLineEdit *lineedit_slaveid;
    QLabel *label_slaveid;
    QPushButton *button_disconnect;
    QLabel *label_comerror;
    QLabel *label_iderror;
    QLabel *label_status;
    QLabel *label_connectionstatus;
    QPushButton *pushbutton_themechange;
    QGroupBox *groupbox_mode1;
    QGroupBox *groupbox_setpoints;
    QLabel *label_mode1setpoint;
    QLineEdit *lineedit_mode1setpoint;
    QPushButton *pushbutton_mode1setpoint;
    QPushButton *pushbutton_stopmode1;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkbox_mode1write;
    QLineEdit *lineedit_mode1filename;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineedit_mode1picname;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushbutton_mode1saveplot;
    QFrame *horizontalframe_plot1;
    QHBoxLayout *horizontallayout_plot1;
    QLabel *label_relay1;
    QLabel *label_relay2;
    QLCDNumber *lcdnumber_currentval1;
    QLCDNumber *lcdnumber_currentval2;
    QLabel *label_relay1status;
    QLabel *label_relay2status;
    QGroupBox *groupbox_mode2;
    QGroupBox *groupbox_mode2setpoints;
    QLabel *label_7;
    QLabel *label_8;
    QCheckBox *checkbox_mode2write;
    QLineEdit *lineedit_mode2filename;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *lineedit_mode2picname;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushbutton_mode2saveplot;
    QPushButton *pushbutton_mode2setcontrolpoints;
    QPushButton *pushbutton_mode2stop;
    QLineEdit *lineedit_mode2addtime;
    QLineEdit *lineedit_mode2addtemperature;
    QPushButton *pushbutton_mode2clear;
    QPushButton *pushbutton_mode2addpoint;
    QPushButton *pushbutton_mode2removepoint;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *lineedit_mode2startingtemperature;
    QPushButton *pushbutton_mode2setstartingtemperature;
    QLabel *label_24;
    QFrame *horizontalframe_plot2;
    QHBoxLayout *horizontallayout_plot1_2;
    QLabel *label_relay1_2;
    QLabel *label_relay2_2;
    QLCDNumber *lcdnumber_mode2currentval1;
    QLCDNumber *lcdnumber_mode2currentval2;
    QLabel *label_mode2relay1status;
    QLabel *label_mode2relay2status;
    QFrame *horizontalframe_trendplot2;
    QHBoxLayout *horizontallayout_plot1_3;
    QLabel *label_13;
    QGroupBox *groupbox_controlmode;
    QRadioButton *radiobutton_mode2;
    QRadioButton *radiobutton_mode1;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1252, 520);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1252, 520));
        MainWindow->setMaximumSize(QSize(1252, 520));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupbox_connection = new QGroupBox(centralwidget);
        groupbox_connection->setObjectName(QString::fromUtf8("groupbox_connection"));
        groupbox_connection->setGeometry(QRect(1060, 10, 171, 351));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        groupbox_connection->setFont(font);
        button_connect = new QPushButton(groupbox_connection);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        button_connect->setGeometry(QRect(10, 210, 75, 23));
        QFont font1;
        font1.setPointSize(8);
        font1.setBold(false);
        font1.setWeight(50);
        button_connect->setFont(font1);
        lineedit_comport = new QLineEdit(groupbox_connection);
        lineedit_comport->setObjectName(QString::fromUtf8("lineedit_comport"));
        lineedit_comport->setGeometry(QRect(10, 50, 151, 20));
        lineedit_comport->setFont(font1);
        label_comport = new QLabel(groupbox_connection);
        label_comport->setObjectName(QString::fromUtf8("label_comport"));
        label_comport->setGeometry(QRect(10, 30, 91, 16));
        QFont font2;
        font2.setPointSize(8);
        font2.setBold(true);
        font2.setWeight(75);
        label_comport->setFont(font2);
        combobox_baudrate = new QComboBox(groupbox_connection);
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->addItem(QString());
        combobox_baudrate->setObjectName(QString::fromUtf8("combobox_baudrate"));
        combobox_baudrate->setGeometry(QRect(10, 110, 151, 22));
        combobox_baudrate->setFont(font1);
        label_baudrate = new QLabel(groupbox_connection);
        label_baudrate->setObjectName(QString::fromUtf8("label_baudrate"));
        label_baudrate->setGeometry(QRect(10, 90, 81, 16));
        label_baudrate->setFont(font2);
        lineedit_slaveid = new QLineEdit(groupbox_connection);
        lineedit_slaveid->setObjectName(QString::fromUtf8("lineedit_slaveid"));
        lineedit_slaveid->setGeometry(QRect(10, 170, 151, 20));
        lineedit_slaveid->setFont(font1);
        label_slaveid = new QLabel(groupbox_connection);
        label_slaveid->setObjectName(QString::fromUtf8("label_slaveid"));
        label_slaveid->setGeometry(QRect(10, 150, 81, 16));
        label_slaveid->setFont(font2);
        button_disconnect = new QPushButton(groupbox_connection);
        button_disconnect->setObjectName(QString::fromUtf8("button_disconnect"));
        button_disconnect->setEnabled(false);
        button_disconnect->setGeometry(QRect(90, 210, 71, 23));
        button_disconnect->setFont(font1);
        label_comerror = new QLabel(groupbox_connection);
        label_comerror->setObjectName(QString::fromUtf8("label_comerror"));
        label_comerror->setEnabled(true);
        label_comerror->setGeometry(QRect(130, 30, 31, 16));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(170, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        label_comerror->setPalette(palette);
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setStyleStrategy(QFont::PreferDefault);
        label_comerror->setFont(font3);
        label_comerror->setTextFormat(Qt::PlainText);
        label_iderror = new QLabel(groupbox_connection);
        label_iderror->setObjectName(QString::fromUtf8("label_iderror"));
        label_iderror->setEnabled(true);
        label_iderror->setGeometry(QRect(130, 150, 31, 16));
        label_iderror->setFont(font3);
        label_iderror->setTextFormat(Qt::PlainText);
        label_status = new QLabel(groupbox_connection);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(10, 250, 51, 16));
        label_status->setFont(font2);
        label_connectionstatus = new QLabel(groupbox_connection);
        label_connectionstatus->setObjectName(QString::fromUtf8("label_connectionstatus"));
        label_connectionstatus->setGeometry(QRect(70, 250, 91, 16));
        label_connectionstatus->setFont(font1);
        pushbutton_themechange = new QPushButton(groupbox_connection);
        pushbutton_themechange->setObjectName(QString::fromUtf8("pushbutton_themechange"));
        pushbutton_themechange->setGeometry(QRect(20, 300, 130, 30));
        pushbutton_themechange->setFont(font2);
        groupbox_mode1 = new QGroupBox(centralwidget);
        groupbox_mode1->setObjectName(QString::fromUtf8("groupbox_mode1"));
        groupbox_mode1->setEnabled(false);
        groupbox_mode1->setGeometry(QRect(20, 10, 1031, 461));
        QFont font4;
        font4.setPointSize(10);
        groupbox_mode1->setFont(font4);
        groupbox_setpoints = new QGroupBox(groupbox_mode1);
        groupbox_setpoints->setObjectName(QString::fromUtf8("groupbox_setpoints"));
        groupbox_setpoints->setEnabled(false);
        groupbox_setpoints->setGeometry(QRect(10, 21, 211, 431));
        label_mode1setpoint = new QLabel(groupbox_setpoints);
        label_mode1setpoint->setObjectName(QString::fromUtf8("label_mode1setpoint"));
        label_mode1setpoint->setGeometry(QRect(40, 20, 131, 16));
        label_mode1setpoint->setFont(font2);
        lineedit_mode1setpoint = new QLineEdit(groupbox_setpoints);
        lineedit_mode1setpoint->setObjectName(QString::fromUtf8("lineedit_mode1setpoint"));
        lineedit_mode1setpoint->setGeometry(QRect(40, 40, 131, 20));
        QFont font5;
        font5.setPointSize(8);
        lineedit_mode1setpoint->setFont(font5);
        pushbutton_mode1setpoint = new QPushButton(groupbox_setpoints);
        pushbutton_mode1setpoint->setObjectName(QString::fromUtf8("pushbutton_mode1setpoint"));
        pushbutton_mode1setpoint->setGeometry(QRect(40, 70, 61, 23));
        pushbutton_mode1setpoint->setFont(font5);
        pushbutton_stopmode1 = new QPushButton(groupbox_setpoints);
        pushbutton_stopmode1->setObjectName(QString::fromUtf8("pushbutton_stopmode1"));
        pushbutton_stopmode1->setGeometry(QRect(110, 70, 61, 23));
        pushbutton_stopmode1->setFont(font5);
        label = new QLabel(groupbox_setpoints);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 120, 71, 16));
        label->setFont(font2);
        label_2 = new QLabel(groupbox_setpoints);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 190, 81, 16));
        label_2->setFont(font2);
        checkbox_mode1write = new QCheckBox(groupbox_setpoints);
        checkbox_mode1write->setObjectName(QString::fromUtf8("checkbox_mode1write"));
        checkbox_mode1write->setGeometry(QRect(40, 300, 131, 21));
        checkbox_mode1write->setFont(font2);
        lineedit_mode1filename = new QLineEdit(groupbox_setpoints);
        lineedit_mode1filename->setObjectName(QString::fromUtf8("lineedit_mode1filename"));
        lineedit_mode1filename->setGeometry(QRect(40, 280, 101, 20));
        lineedit_mode1filename->setFont(font5);
        label_3 = new QLabel(groupbox_setpoints);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(144, 280, 31, 16));
        label_3->setFont(font1);
        label_4 = new QLabel(groupbox_setpoints);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(40, 260, 71, 16));
        label_4->setFont(font2);
        lineedit_mode1picname = new QLineEdit(groupbox_setpoints);
        lineedit_mode1picname->setObjectName(QString::fromUtf8("lineedit_mode1picname"));
        lineedit_mode1picname->setGeometry(QRect(40, 360, 100, 20));
        label_5 = new QLabel(groupbox_setpoints);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(144, 360, 31, 16));
        label_5->setFont(font1);
        label_6 = new QLabel(groupbox_setpoints);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 340, 91, 16));
        label_6->setFont(font2);
        pushbutton_mode1saveplot = new QPushButton(groupbox_setpoints);
        pushbutton_mode1saveplot->setObjectName(QString::fromUtf8("pushbutton_mode1saveplot"));
        pushbutton_mode1saveplot->setGeometry(QRect(40, 390, 75, 23));
        pushbutton_mode1saveplot->setFont(font5);
        horizontalframe_plot1 = new QFrame(groupbox_mode1);
        horizontalframe_plot1->setObjectName(QString::fromUtf8("horizontalframe_plot1"));
        horizontalframe_plot1->setGeometry(QRect(230, 20, 791, 431));
        horizontallayout_plot1 = new QHBoxLayout(horizontalframe_plot1);
        horizontallayout_plot1->setObjectName(QString::fromUtf8("horizontallayout_plot1"));
        label_relay1 = new QLabel(groupbox_mode1);
        label_relay1->setObjectName(QString::fromUtf8("label_relay1"));
        label_relay1->setGeometry(QRect(125, 160, 21, 30));
        label_relay1->setFont(font2);
        label_relay2 = new QLabel(groupbox_mode1);
        label_relay2->setObjectName(QString::fromUtf8("label_relay2"));
        label_relay2->setGeometry(QRect(125, 230, 21, 30));
        label_relay2->setFont(font2);
        lcdnumber_currentval1 = new QLCDNumber(groupbox_mode1);
        lcdnumber_currentval1->setObjectName(QString::fromUtf8("lcdnumber_currentval1"));
        lcdnumber_currentval1->setGeometry(QRect(48, 160, 71, 31));
        lcdnumber_currentval1->setFrameShape(QFrame::Box);
        lcdnumber_currentval1->setLineWidth(2);
        lcdnumber_currentval1->setProperty("intValue", QVariant(0));
        lcdnumber_currentval2 = new QLCDNumber(groupbox_mode1);
        lcdnumber_currentval2->setObjectName(QString::fromUtf8("lcdnumber_currentval2"));
        lcdnumber_currentval2->setGeometry(QRect(48, 230, 71, 31));
        lcdnumber_currentval2->setLineWidth(2);
        label_relay1status = new QLabel(groupbox_mode1);
        label_relay1status->setObjectName(QString::fromUtf8("label_relay1status"));
        label_relay1status->setGeometry(QRect(153, 160, 30, 30));
        label_relay1status->setFont(font2);
        label_relay2status = new QLabel(groupbox_mode1);
        label_relay2status->setObjectName(QString::fromUtf8("label_relay2status"));
        label_relay2status->setGeometry(QRect(153, 230, 31, 30));
        label_relay2status->setFont(font2);
        groupbox_mode2 = new QGroupBox(centralwidget);
        groupbox_mode2->setObjectName(QString::fromUtf8("groupbox_mode2"));
        groupbox_mode2->setEnabled(false);
        groupbox_mode2->setGeometry(QRect(20, 10, 1031, 461));
        groupbox_mode2->setFont(font4);
        groupbox_mode2setpoints = new QGroupBox(groupbox_mode2);
        groupbox_mode2setpoints->setObjectName(QString::fromUtf8("groupbox_mode2setpoints"));
        groupbox_mode2setpoints->setEnabled(false);
        groupbox_mode2setpoints->setGeometry(QRect(10, 20, 421, 181));
        label_7 = new QLabel(groupbox_mode2setpoints);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(160, 20, 71, 16));
        label_7->setFont(font2);
        label_8 = new QLabel(groupbox_mode2setpoints);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(160, 90, 81, 16));
        label_8->setFont(font2);
        checkbox_mode2write = new QCheckBox(groupbox_mode2setpoints);
        checkbox_mode2write->setObjectName(QString::fromUtf8("checkbox_mode2write"));
        checkbox_mode2write->setGeometry(QRect(290, 60, 110, 21));
        checkbox_mode2write->setFont(font2);
        lineedit_mode2filename = new QLineEdit(groupbox_mode2setpoints);
        lineedit_mode2filename->setObjectName(QString::fromUtf8("lineedit_mode2filename"));
        lineedit_mode2filename->setGeometry(QRect(290, 40, 90, 20));
        lineedit_mode2filename->setFont(font5);
        label_9 = new QLabel(groupbox_mode2setpoints);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(386, 40, 28, 16));
        label_9->setFont(font1);
        label_10 = new QLabel(groupbox_mode2setpoints);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(290, 20, 71, 16));
        label_10->setFont(font2);
        lineedit_mode2picname = new QLineEdit(groupbox_mode2setpoints);
        lineedit_mode2picname->setObjectName(QString::fromUtf8("lineedit_mode2picname"));
        lineedit_mode2picname->setGeometry(QRect(290, 120, 90, 20));
        lineedit_mode2picname->setFont(font5);
        label_11 = new QLabel(groupbox_mode2setpoints);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(385, 120, 28, 16));
        label_11->setFont(font1);
        label_12 = new QLabel(groupbox_mode2setpoints);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(290, 100, 91, 16));
        label_12->setFont(font2);
        pushbutton_mode2saveplot = new QPushButton(groupbox_mode2setpoints);
        pushbutton_mode2saveplot->setObjectName(QString::fromUtf8("pushbutton_mode2saveplot"));
        pushbutton_mode2saveplot->setGeometry(QRect(290, 150, 75, 23));
        pushbutton_mode2saveplot->setFont(font5);
        pushbutton_mode2setcontrolpoints = new QPushButton(groupbox_mode2setpoints);
        pushbutton_mode2setcontrolpoints->setObjectName(QString::fromUtf8("pushbutton_mode2setcontrolpoints"));
        pushbutton_mode2setcontrolpoints->setGeometry(QRect(10, 150, 60, 23));
        pushbutton_mode2setcontrolpoints->setFont(font5);
        pushbutton_mode2stop = new QPushButton(groupbox_mode2setpoints);
        pushbutton_mode2stop->setObjectName(QString::fromUtf8("pushbutton_mode2stop"));
        pushbutton_mode2stop->setGeometry(QRect(90, 150, 60, 23));
        pushbutton_mode2stop->setFont(font5);
        lineedit_mode2addtime = new QLineEdit(groupbox_mode2setpoints);
        lineedit_mode2addtime->setObjectName(QString::fromUtf8("lineedit_mode2addtime"));
        lineedit_mode2addtime->setGeometry(QRect(10, 90, 60, 20));
        lineedit_mode2addtime->setFont(font5);
        lineedit_mode2addtemperature = new QLineEdit(groupbox_mode2setpoints);
        lineedit_mode2addtemperature->setObjectName(QString::fromUtf8("lineedit_mode2addtemperature"));
        lineedit_mode2addtemperature->setGeometry(QRect(90, 90, 60, 20));
        lineedit_mode2addtemperature->setFont(font5);
        pushbutton_mode2clear = new QPushButton(groupbox_mode2setpoints);
        pushbutton_mode2clear->setObjectName(QString::fromUtf8("pushbutton_mode2clear"));
        pushbutton_mode2clear->setGeometry(QRect(110, 120, 40, 23));
        pushbutton_mode2clear->setFont(font5);
        pushbutton_mode2addpoint = new QPushButton(groupbox_mode2setpoints);
        pushbutton_mode2addpoint->setObjectName(QString::fromUtf8("pushbutton_mode2addpoint"));
        pushbutton_mode2addpoint->setGeometry(QRect(10, 120, 40, 23));
        pushbutton_mode2addpoint->setFont(font5);
        pushbutton_mode2removepoint = new QPushButton(groupbox_mode2setpoints);
        pushbutton_mode2removepoint->setObjectName(QString::fromUtf8("pushbutton_mode2removepoint"));
        pushbutton_mode2removepoint->setGeometry(QRect(60, 120, 40, 23));
        pushbutton_mode2removepoint->setFont(font5);
        label_14 = new QLabel(groupbox_mode2setpoints);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(90, 70, 50, 13));
        label_14->setFont(font2);
        label_15 = new QLabel(groupbox_mode2setpoints);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 70, 71, 16));
        label_15->setFont(font2);
        lineedit_mode2startingtemperature = new QLineEdit(groupbox_mode2setpoints);
        lineedit_mode2startingtemperature->setObjectName(QString::fromUtf8("lineedit_mode2startingtemperature"));
        lineedit_mode2startingtemperature->setGeometry(QRect(10, 40, 71, 20));
        lineedit_mode2startingtemperature->setFont(font5);
        lineedit_mode2startingtemperature->setInputMethodHints(Qt::ImhNone);
        lineedit_mode2startingtemperature->setMaxLength(3);
        lineedit_mode2startingtemperature->setCursorPosition(0);
        lineedit_mode2startingtemperature->setClearButtonEnabled(false);
        pushbutton_mode2setstartingtemperature = new QPushButton(groupbox_mode2setpoints);
        pushbutton_mode2setstartingtemperature->setObjectName(QString::fromUtf8("pushbutton_mode2setstartingtemperature"));
        pushbutton_mode2setstartingtemperature->setGeometry(QRect(90, 40, 60, 23));
        pushbutton_mode2setstartingtemperature->setFont(font5);
        label_24 = new QLabel(groupbox_mode2setpoints);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 20, 161, 16));
        label_24->setFont(font2);
        label_7->raise();
        label_8->raise();
        checkbox_mode2write->raise();
        lineedit_mode2filename->raise();
        label_9->raise();
        label_10->raise();
        lineedit_mode2picname->raise();
        label_11->raise();
        label_12->raise();
        pushbutton_mode2saveplot->raise();
        pushbutton_mode2setcontrolpoints->raise();
        pushbutton_mode2stop->raise();
        pushbutton_mode2clear->raise();
        pushbutton_mode2addpoint->raise();
        pushbutton_mode2removepoint->raise();
        label_14->raise();
        label_15->raise();
        lineedit_mode2startingtemperature->raise();
        pushbutton_mode2setstartingtemperature->raise();
        label_24->raise();
        lineedit_mode2addtemperature->raise();
        lineedit_mode2addtime->raise();
        horizontalframe_plot2 = new QFrame(groupbox_mode2);
        horizontalframe_plot2->setObjectName(QString::fromUtf8("horizontalframe_plot2"));
        horizontalframe_plot2->setGeometry(QRect(440, 20, 581, 431));
        horizontallayout_plot1_2 = new QHBoxLayout(horizontalframe_plot2);
        horizontallayout_plot1_2->setObjectName(QString::fromUtf8("horizontallayout_plot1_2"));
        label_relay1_2 = new QLabel(groupbox_mode2);
        label_relay1_2->setObjectName(QString::fromUtf8("label_relay1_2"));
        label_relay1_2->setGeometry(QRect(245, 60, 21, 30));
        label_relay1_2->setFont(font2);
        label_relay2_2 = new QLabel(groupbox_mode2);
        label_relay2_2->setObjectName(QString::fromUtf8("label_relay2_2"));
        label_relay2_2->setGeometry(QRect(245, 130, 21, 30));
        label_relay2_2->setFont(font2);
        lcdnumber_mode2currentval1 = new QLCDNumber(groupbox_mode2);
        lcdnumber_mode2currentval1->setObjectName(QString::fromUtf8("lcdnumber_mode2currentval1"));
        lcdnumber_mode2currentval1->setGeometry(QRect(168, 60, 71, 31));
        lcdnumber_mode2currentval1->setFrameShape(QFrame::Box);
        lcdnumber_mode2currentval1->setLineWidth(2);
        lcdnumber_mode2currentval1->setProperty("intValue", QVariant(0));
        lcdnumber_mode2currentval2 = new QLCDNumber(groupbox_mode2);
        lcdnumber_mode2currentval2->setObjectName(QString::fromUtf8("lcdnumber_mode2currentval2"));
        lcdnumber_mode2currentval2->setGeometry(QRect(168, 130, 71, 31));
        lcdnumber_mode2currentval2->setLineWidth(2);
        label_mode2relay1status = new QLabel(groupbox_mode2);
        label_mode2relay1status->setObjectName(QString::fromUtf8("label_mode2relay1status"));
        label_mode2relay1status->setGeometry(QRect(270, 60, 25, 30));
        label_mode2relay1status->setFont(font2);
        label_mode2relay2status = new QLabel(groupbox_mode2);
        label_mode2relay2status->setObjectName(QString::fromUtf8("label_mode2relay2status"));
        label_mode2relay2status->setGeometry(QRect(270, 130, 25, 30));
        label_mode2relay2status->setFont(font2);
        horizontalframe_trendplot2 = new QFrame(groupbox_mode2);
        horizontalframe_trendplot2->setObjectName(QString::fromUtf8("horizontalframe_trendplot2"));
        horizontalframe_trendplot2->setGeometry(QRect(10, 230, 421, 221));
        horizontallayout_plot1_3 = new QHBoxLayout(horizontalframe_trendplot2);
        horizontallayout_plot1_3->setObjectName(QString::fromUtf8("horizontallayout_plot1_3"));
        label_13 = new QLabel(groupbox_mode2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 210, 71, 16));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        label_13->setFont(font6);
        groupbox_controlmode = new QGroupBox(centralwidget);
        groupbox_controlmode->setObjectName(QString::fromUtf8("groupbox_controlmode"));
        groupbox_controlmode->setEnabled(false);
        groupbox_controlmode->setGeometry(QRect(1060, 370, 171, 101));
        groupbox_controlmode->setFont(font4);
        radiobutton_mode2 = new QRadioButton(groupbox_controlmode);
        radiobutton_mode2->setObjectName(QString::fromUtf8("radiobutton_mode2"));
        radiobutton_mode2->setGeometry(QRect(50, 60, 81, 17));
        radiobutton_mode2->setFont(font5);
        radiobutton_mode1 = new QRadioButton(groupbox_controlmode);
        radiobutton_mode1->setObjectName(QString::fromUtf8("radiobutton_mode1"));
        radiobutton_mode1->setGeometry(QRect(50, 30, 71, 17));
        radiobutton_mode1->setFont(font5);
        radiobutton_mode1->setCheckable(true);
        radiobutton_mode1->setChecked(true);
        MainWindow->setCentralWidget(centralwidget);
        groupbox_mode1->raise();
        groupbox_connection->raise();
        groupbox_controlmode->raise();
        groupbox_mode2->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1252, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        combobox_baudrate->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OVEN", nullptr));
        groupbox_connection->setTitle(QApplication::translate("MainWindow", "Connected to:", nullptr));
        button_connect->setText(QApplication::translate("MainWindow", "Connect", nullptr));
        lineedit_comport->setText(QApplication::translate("MainWindow", "com4", nullptr));
        label_comport->setText(QApplication::translate("MainWindow", "Serial Port:", nullptr));
        combobox_baudrate->setItemText(0, QApplication::translate("MainWindow", "2400", nullptr));
        combobox_baudrate->setItemText(1, QApplication::translate("MainWindow", "4800", nullptr));
        combobox_baudrate->setItemText(2, QApplication::translate("MainWindow", "9600", nullptr));
        combobox_baudrate->setItemText(3, QApplication::translate("MainWindow", "14400", nullptr));
        combobox_baudrate->setItemText(4, QApplication::translate("MainWindow", "19200", nullptr));
        combobox_baudrate->setItemText(5, QApplication::translate("MainWindow", "28800", nullptr));
        combobox_baudrate->setItemText(6, QApplication::translate("MainWindow", "38400", nullptr));
        combobox_baudrate->setItemText(7, QApplication::translate("MainWindow", "57600", nullptr));
        combobox_baudrate->setItemText(8, QApplication::translate("MainWindow", "115200", nullptr));

        label_baudrate->setText(QApplication::translate("MainWindow", "Baud Rate:", nullptr));
        lineedit_slaveid->setText(QApplication::translate("MainWindow", "1", nullptr));
        label_slaveid->setText(QApplication::translate("MainWindow", "Slave ID:", nullptr));
        button_disconnect->setText(QApplication::translate("MainWindow", "Disconnect", nullptr));
#ifndef QT_NO_SHORTCUT
        button_disconnect->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        label_comerror->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>e.g. &quot;COM7&quot;</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_comerror->setText(QApplication::translate("MainWindow", "HELP", nullptr));
#ifndef QT_NO_TOOLTIP
        label_iderror->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>e.g. &quot;1&quot;</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_iderror->setText(QApplication::translate("MainWindow", "HELP", nullptr));
        label_status->setText(QApplication::translate("MainWindow", "STATUS:", nullptr));
        label_connectionstatus->setText(QApplication::translate("MainWindow", "disconnected", nullptr));
        pushbutton_themechange->setText(QApplication::translate("MainWindow", "Theme Inversion", nullptr));
#ifndef QT_NO_SHORTCUT
        pushbutton_themechange->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+T", nullptr));
#endif // QT_NO_SHORTCUT
        groupbox_mode1->setTitle(QApplication::translate("MainWindow", "Mode 1:", nullptr));
        groupbox_setpoints->setTitle(QApplication::translate("MainWindow", "Set Points", nullptr));
        label_mode1setpoint->setText(QApplication::translate("MainWindow", "Temperature Set:", nullptr));
#ifndef QT_NO_TOOLTIP
        pushbutton_mode1setpoint->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Start heating and plotting</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        pushbutton_mode1setpoint->setText(QApplication::translate("MainWindow", "Set", nullptr));
#ifndef QT_NO_SHORTCUT
        pushbutton_mode1setpoint->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        pushbutton_stopmode1->setText(QApplication::translate("MainWindow", "Stop", nullptr));
#ifndef QT_NO_SHORTCUT
        pushbutton_stopmode1->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Channel 2 measurement</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "CHANNEL 1", nullptr));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Channel 2 measurement</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "CHANNEL 2", nullptr));
        checkbox_mode1write->setText(QApplication::translate("MainWindow", "Write File", nullptr));
#ifndef QT_NO_SHORTCUT
        checkbox_mode1write->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+W", nullptr));
#endif // QT_NO_SHORTCUT
        label_3->setText(QApplication::translate("MainWindow", ".csv", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "File Name:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", ".bmp", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Image Name:", nullptr));
        pushbutton_mode1saveplot->setText(QApplication::translate("MainWindow", "Save Plot", nullptr));
#ifndef QT_NO_TOOLTIP
        label_relay1->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Relay output 1 status</p><p>NaN - NO INFO</p><p>0 - OFF</p><p>1 - ON</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_relay1->setText(QApplication::translate("MainWindow", "K1:", nullptr));
#ifndef QT_NO_TOOLTIP
        label_relay2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Relay output 2 status</p><p>NaN - NO INFO</p><p>0 - OFF</p><p>1 - ON</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_relay2->setText(QApplication::translate("MainWindow", "K2:", nullptr));
        label_relay1status->setText(QApplication::translate("MainWindow", "NaN", nullptr));
        label_relay2status->setText(QApplication::translate("MainWindow", "NaN", nullptr));
        groupbox_mode2->setTitle(QApplication::translate("MainWindow", "Mode 2:", nullptr));
        groupbox_mode2setpoints->setTitle(QApplication::translate("MainWindow", "Control Points", nullptr));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Channel 2 measurement</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("MainWindow", "CHANNEL 1", nullptr));
#ifndef QT_NO_TOOLTIP
        label_8->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Channel 2 measurement</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_8->setText(QApplication::translate("MainWindow", "CHANNEL 2", nullptr));
        checkbox_mode2write->setText(QApplication::translate("MainWindow", "Write File", nullptr));
#ifndef QT_NO_SHORTCUT
        checkbox_mode2write->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+W", nullptr));
#endif // QT_NO_SHORTCUT
        label_9->setText(QApplication::translate("MainWindow", ".csv", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "File Name:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", ".bmp", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Image Name:", nullptr));
        pushbutton_mode2saveplot->setText(QApplication::translate("MainWindow", "Save Plot", nullptr));
        pushbutton_mode2setcontrolpoints->setText(QApplication::translate("MainWindow", "Start", nullptr));
#ifndef QT_NO_SHORTCUT
        pushbutton_mode2setcontrolpoints->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        pushbutton_mode2stop->setText(QApplication::translate("MainWindow", "Stop", nullptr));
#ifndef QT_NO_SHORTCUT
        pushbutton_mode2stop->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        pushbutton_mode2clear->setText(QApplication::translate("MainWindow", "Clear", nullptr));
#ifndef QT_NO_SHORTCUT
        pushbutton_mode2clear->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", nullptr));
#endif // QT_NO_SHORTCUT
        pushbutton_mode2addpoint->setText(QApplication::translate("MainWindow", "Add", nullptr));
        pushbutton_mode2removepoint->setText(QApplication::translate("MainWindow", "Del", nullptr));
#ifndef QT_NO_SHORTCUT
        pushbutton_mode2removepoint->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+D", nullptr));
#endif // QT_NO_SHORTCUT
        label_14->setText(QApplication::translate("MainWindow", "Temp, C", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "Time, sec", nullptr));
        lineedit_mode2startingtemperature->setText(QString());
        pushbutton_mode2setstartingtemperature->setText(QApplication::translate("MainWindow", "Set", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "Starting Temperature, C", nullptr));
#ifndef QT_NO_TOOLTIP
        label_relay1_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Relay output 1 status</p><p>NaN - NO INFO</p><p>0 - OFF</p><p>1 - ON</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_relay1_2->setText(QApplication::translate("MainWindow", "K1:", nullptr));
#ifndef QT_NO_TOOLTIP
        label_relay2_2->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Relay output 2 status</p><p>NaN - NO INFO</p><p>0 - OFF</p><p>1 - ON</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        label_relay2_2->setText(QApplication::translate("MainWindow", "K2:", nullptr));
        label_mode2relay1status->setText(QApplication::translate("MainWindow", "NaN", nullptr));
        label_mode2relay2status->setText(QApplication::translate("MainWindow", "NaN", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Trend Plot:", nullptr));
        groupbox_controlmode->setTitle(QApplication::translate("MainWindow", "Control Mode:", nullptr));
        radiobutton_mode2->setText(QApplication::translate("MainWindow", "Mode 2", nullptr));
#ifndef QT_NO_SHORTCUT
        radiobutton_mode2->setShortcut(QApplication::translate("MainWindow", "F2", nullptr));
#endif // QT_NO_SHORTCUT
        radiobutton_mode1->setText(QApplication::translate("MainWindow", "Mode 1", nullptr));
#ifndef QT_NO_SHORTCUT
        radiobutton_mode1->setShortcut(QApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
