#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define BLACK 0
#define WHITE 1

#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QTimer>

#include <fstream>
#include <stdint.h>
#include <iostream>
#include <list>
#include <array>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_connect_clicked();

    void on_button_disconnect_clicked();

    void on_radiobutton_mode1_clicked();

    void on_pushbutton_mode1setpoint_clicked();

    void update_plot1();
    void update_plot2();
    //void counter(void);

    void refresh_plot1();
    void refresh_plot2();
    void refresh_trend();

    void on_pushbutton_themechange_clicked();

    void on_pushbutton_stopmode1_clicked();

    void on_checkbox_mode1write_stateChanged(int arg1);

    void on_pushbutton_mode1saveplot_clicked();

    void on_pushbutton_mode2saveplot_clicked();

    void on_checkbox_mode2write_stateChanged(int arg1);

    void on_radiobutton_mode2_clicked();

    void on_pushbutton_mode2stop_clicked();

    void on_pushbutton_mode2setcontrolpoints_clicked();

    void on_pushbutton_mode2setstartingtemperature_clicked();

    void on_pushbutton_mode2addpoint_clicked();

    void on_pushbutton_mode2removepoint_clicked();

    void on_pushbutton_mode2clear_clicked();

    void on_lineedit_mode2startingtemperature_returnPressed();

    void on_lineedit_mode2picname_returnPressed();

    void on_lineedit_slaveid_returnPressed();

    void on_lineedit_mode2addtemperature_returnPressed();

    void on_lineedit_mode1setpoint_returnPressed();

    void on_lineedit_mode1picname_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
