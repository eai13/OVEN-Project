#define _CRT_SECURE_NO_WARNINGS

#define PI 1
#define PD 0

#define PWM_PERIOD 5000

#define NEW_VAR 1000

#define GAIN    10

// Good but needs tests with new PI
#define P_REG1  0.01 //0.0251673
#define D_REG1  0

#define P_REG2  0.05
#define I_REG2  0.0005 // 0.00001 increased 50 times

#define WINDOW_SIZE 6

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mblib.h"
#include <QDate>

char sym = ';';

// Current theme of the window
uint8_t theme = WHITE;

// Modbus slave pointer
modbus_connection * OVEN = NULL;

// Write file
std::ofstream data_file_1;
std::ofstream data_file_2;
std::ofstream log_file;

// Comparison timer
QTimer * timer_counter = new QTimer;

// Plot 1
QTimer * plot1_timer = new QTimer;
QChartView *    qcv_plot1;
QValueAxis *    x_axis_plot1;
QValueAxis *    y_axis_plot1;
QChart *        chart_plot1;
QLineSeries *   series_plot1;
uint32_t current_time_1 = 0;
// Plot 2
QTimer * plot2_timer = new QTimer;
QChartView *    qcv_plot2;
QValueAxis *    x_axis_plot2;
QValueAxis *    y_axis_plot2;
QChart *        chart_plot2;
QLineSeries *   series_plot2;
uint32_t current_time_2 = 0;
// Plot 2 trend
QChartView *    qcv_trend;
QValueAxis *    x_axis_trend;
QValueAxis *    y_axis_trend;
QChart *        chart_trend;
QLineSeries *   series_trend;

std::list<std::array<int32_t, 2>> heating_profile;
std::list<std::array<int32_t, 2>> heating_profile_copy;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDateTime date;
    std::cout << date.currentSecsSinceEpoch() << std::endl;
    log_file.open("log_" + std::to_string(date.currentSecsSinceEpoch()) + ".txt", std::ios::out | std::ios::trunc);
    // Setting validators for editlines
    ui->lineedit_mode1setpoint->setValidator(new QIntValidator(0, 1000, this));
    ui->lineedit_slaveid->setValidator(new QIntValidator(0, 255, this));
    ui->lineedit_mode2addtemperature->setValidator(new QIntValidator(0, 1000, this));
    ui->lineedit_mode2addtime->setValidator(new QIntValidator(this));
    ui->lineedit_mode2startingtemperature->setValidator(new QIntValidator(0, 1000, this));

    // Set visibility
    ui->groupbox_mode1->setVisible(true);
    ui->groupbox_mode2->setVisible(false);

    // Setting current theme
    this->setStyleSheet("QMainWindow, QGroupBox, QLabel, QRadioButton, QCheckBox { background-color: white; color: black }");
    theme = WHITE;

    // Plotting the first mode chart
    chart_plot1 = new QChart();
    series_plot1 = new QLineSeries();
    chart_plot1->addSeries(series_plot1);
    // Setting up the X axis
    x_axis_plot1 = new QValueAxis;
    x_axis_plot1->setTickCount(11);
    x_axis_plot1->setRange(0, 50);
    x_axis_plot1->setTitleText("Time, sec");
    // Setting up the Y axis
    y_axis_plot1 = new QValueAxis;
    y_axis_plot1->setTickCount(11);
    y_axis_plot1->setRange(0, 1000);
    y_axis_plot1->setTitleText("Temperature, C");
    // Setting up the whole chart
    chart_plot1->addAxis(x_axis_plot1, Qt::AlignBottom);
    chart_plot1->addAxis(y_axis_plot1, Qt::AlignLeft);
    chart_plot1->legend()->hide();
    series_plot1->attachAxis(x_axis_plot1);
    series_plot1->attachAxis(y_axis_plot1);
    // Setting up the visualization
    qcv_plot1 = new QChartView(chart_plot1);
    qcv_plot1->setFixedSize(791, 431);
    qcv_plot1->setRenderHint(QPainter::Antialiasing);
    qcv_plot1->setParent(ui->horizontalframe_plot1);

    // Plotting the second mode chart
    chart_plot2 = new QChart();
    series_plot2 = new QLineSeries();
    chart_plot2->addSeries(series_plot2);
    // Setting up the X axis
    x_axis_plot2 = new QValueAxis;
    x_axis_plot2->setTickCount(11);
    x_axis_plot2->setRange(0, 50);
    x_axis_plot2->setTitleText("Time, sec");
    // Setting up the Y axis
    y_axis_plot2 = new QValueAxis;
    y_axis_plot2->setTickCount(11);
    y_axis_plot2->setRange(0, 1000);
    y_axis_plot2->setTitleText("Temperature, C");
    // Setting up the whole chart
    chart_plot2->addAxis(x_axis_plot2, Qt::AlignBottom);
    chart_plot2->addAxis(y_axis_plot2, Qt::AlignLeft);
    chart_plot2->legend()->hide();
    series_plot2->attachAxis(x_axis_plot2);
    series_plot2->attachAxis(y_axis_plot2);
    // Setting up the visualization
    qcv_plot2 = new QChartView(chart_plot2);
    qcv_plot2->setFixedSize(581, 431);
    qcv_plot2->setRenderHint(QPainter::Antialiasing);
    qcv_plot2->setParent(ui->horizontalframe_plot2);

    // Plotting the second mode trend chart
    chart_trend = new QChart();
    series_trend = new QLineSeries();
    chart_trend->addSeries(series_trend);
    // Setting up the X axis
    x_axis_trend = new QValueAxis;
    x_axis_trend->setTickCount(6);
    x_axis_trend->setRange(0, 50);
    x_axis_trend->setTitleText("Time, sec");
    // Setting up the Y axis
    y_axis_trend = new QValueAxis;
    y_axis_trend->setTickCount(6);
    y_axis_trend->setRange(0, 1000);
    y_axis_trend->setTitleText("Temperature, C");
    // Setting up the whole chart
    chart_trend->addAxis(x_axis_trend, Qt::AlignBottom);
    chart_trend->addAxis(y_axis_trend, Qt::AlignLeft);
    chart_trend->legend()->hide();
    series_trend->attachAxis(x_axis_trend);
    series_trend->attachAxis(y_axis_trend);
    // Setting up the visualization
    qcv_trend = new QChartView(chart_trend);
    qcv_trend->setFixedSize(421, 221);
    qcv_trend->setRenderHint(QPainter::Antialiasing);
    qcv_trend->setParent(ui->horizontalframe_trendplot2);
}

// Closing the program
MainWindow::~MainWindow(){
    // Check for some dumbs who close without disconnection
    if ((OVEN != NULL) && (ui->label_connectionstatus->text() == "connected")){
        // Turning off the relays
        OVEN->set_coil(rout1, 0);

        // Disconnecting
        OVEN->disconnect();
    }

    // Stop and disable the timers
    if (plot1_timer->isActive()){
        plot1_timer->stop();
        plot1_timer->disconnect(plot1_timer, SIGNAL(timeout()), this, SLOT(update_plot1()));
    }
    if (plot2_timer->isActive()){
        plot2_timer->stop();
        plot2_timer->disconnect(plot2_timer, SIGNAL(timeout()), this, SLOT(update_plot2()));
    }
    if (timer_counter->isActive()){
        timer_counter->stop();
        timer_counter->disconnect(timer_counter, SIGNAL(timeout()), this, SLOT(counter()));
    }

    // Closing the data file
    if (data_file_1.is_open() == true) data_file_1.close();
    if (data_file_2.is_open() == true) data_file_2.close();

    heating_profile.clear();

    delete ui;
}

// Button "CONNECT" click
void MainWindow::on_button_connect_clicked(){
    // Serial name in "string"
    std::string serial_name = "";
    // Serial name in "wchar_t"
    wchar_t * serial_name_w;
    // Slave id variable
    uint8_t slave_id = 0;

    // Check the text of the serial
    if (ui->lineedit_comport->text().toStdString().length() == 0){
        std::cout << "Wrong Serial" << std::endl;
        return;
    }
    else{
        // Set "string" serial name
        serial_name = ui->lineedit_comport->text().toStdString();
        // Allocate memory for "wchar_t" serial name
        serial_name_w = new wchar_t[serial_name.length() + 1];
        // Conversion from "char *" to "wchar_t *"
        std::mbstowcs(serial_name_w, serial_name.c_str(), serial_name.length() + 1);
    }

    // Check the text of ID
    if (ui->lineedit_slaveid->text().toStdString().length() == 0){
        std::cout << "Wrong ID" << std::endl;
        return;
    }
    else slave_id = ui->lineedit_slaveid->text().toUInt();

    // Setting the baud rate
    uint32_t baud_rate = ui->combobox_baudrate->currentText().toUInt();

    // Allocating memory for connection
    OVEN = new modbus_connection(serial_name_w, baud_rate, 2, 0, 8, slave_id);
    // Check for connection
    if (OVEN->check_connection() == 1){
        // Setting availability of the objects
        ui->label_connectionstatus->setText("connected");
        ui->button_connect->setEnabled(false);
        ui->button_disconnect->setEnabled(true);
        if (ui->radiobutton_mode1->isChecked()){
            on_radiobutton_mode1_clicked();
        }
        else if (ui->radiobutton_mode2->isChecked()){
            on_radiobutton_mode2_clicked();
        }

        // Enable choosing the control mode
        ui->groupbox_controlmode->setEnabled(true);

        // Banning autonomous control
        OVEN->set_coil(r_L1, 1);

        // Turning off the relays
        OVEN->set_coil(rout1, 0);

        // Setting low set points
        OVEN->set_coil(SP1, 0);
    }
    else if (OVEN->check_connection() == 0){
        // Setting the availability of the objects
        ui->label_connectionstatus->setText("disconnected");
        ui->button_connect->setEnabled(true);
        ui->button_disconnect->setEnabled(false);
        ui->groupbox_controlmode->setEnabled(false);

        // Deleting the OVEN object
        OVEN->~modbus_connection();
        OVEN = NULL;
    }
}

// Button "DISCONNECT" click
void MainWindow::on_button_disconnect_clicked(){
    // Check if the connection was established before
    if (    (ui->button_connect->isEnabled() == false) &&
            (ui->button_disconnect->isEnabled() == true) &&
            (ui->label_connectionstatus->text() == "connected")){

        // Turning off the relays
        OVEN->set_coil(rout1, 0);

        // Disable all of the modes
        // For mode 1
        ui->lineedit_mode1setpoint->setText("");
        ui->groupbox_mode1->setEnabled(false);
        ui->radiobutton_mode1->setChecked(true);
        ui->lineedit_mode1filename->setText("");
        ui->checkbox_mode1write->setChecked(false);
        ui->lineedit_mode1picname->setText("");
        refresh_plot1();
        ui->label_relay1status->setText("NaN");
        ui->label_relay2status->setText("NaN");
        ui->lcdnumber_currentval1->display(0);
        ui->lcdnumber_currentval2->display(0);

        // For mode 2
        ui->groupbox_mode2->setEnabled(false);
        ui->radiobutton_mode1->setChecked(true);
        ui->lineedit_mode2filename->setText("");
        ui->checkbox_mode2write->setChecked(false);
        ui->lineedit_mode2picname->setText("");
        refresh_trend();
        refresh_plot2();
        ui->label_mode2relay1status->setText("NaN");
        ui->label_mode2relay2status->setText("NaN");
        ui->lcdnumber_mode2currentval1->display(0);
        ui->lcdnumber_mode2currentval2->display(0);
        ui->lineedit_mode2addtemperature->setText("");
        ui->lineedit_mode2addtime->setText("");
        ui->lineedit_mode2startingtemperature->setText("");

        // For control mode window
        ui->groupbox_controlmode->setEnabled(false);

        // Disconnect
        OVEN->disconnect();
        OVEN = NULL;

        // Set the availability of the buttons
        ui->button_connect->setEnabled(true);
        ui->button_disconnect->setEnabled(false);
        ui->label_connectionstatus->setText("disconnected");

        // Heating profile clearing
        heating_profile.clear();

        // Closing the write file
        if (data_file_1.is_open() == true) data_file_1.close();
        if (data_file_2.is_open() == true) data_file_2.close();

        // Set active lineedit
        ui->lineedit_slaveid->setFocus();
    }
    else return;
}

// Mode 1 radiobutton clicked
void MainWindow::on_radiobutton_mode1_clicked(){
    // Set visibility
    ui->groupbox_mode1->setVisible(true);
    ui->groupbox_mode2->setVisible(false);

    // Enabling the mode 1 box
    ui->groupbox_mode1->setEnabled(true);
    ui->groupbox_setpoints->setEnabled(true);
    ui->pushbutton_stopmode1->setEnabled(false);
    ui->lineedit_mode1filename->setEnabled(false);
    ui->checkbox_mode1write->setChecked(false);
    refresh_plot1();

    // Disabling the mode 2 box
    ui->groupbox_mode2->setEnabled(false);
    ui->label_mode2relay1status->setText("NaN");
    ui->label_mode2relay2status->setText("NaN");
    ui->lineedit_mode2filename->setText("");
    ui->lineedit_mode2picname->setText("");
    ui->lineedit_mode2addtemperature->setText("");
    ui->lineedit_mode2addtime->setText("");
    ui->lineedit_mode2startingtemperature->setText("");
    ui->checkbox_mode2write->setChecked(false);
    ui->lcdnumber_mode2currentval1->display(0);
    ui->lcdnumber_mode2currentval2->display(0);
    refresh_plot2();
    refresh_trend();
    heating_profile.clear();
    heating_profile_copy.clear();

    // Reading current set point values
    float value;
    if (OVEN->get_coil(SP1, value) == 0) ui->lineedit_mode1setpoint->setText(QString::fromStdString(std::to_string(value)));
    else ui->lineedit_mode1setpoint->setText("Error");
    if (OVEN->get_coil(PV1, value) == 0) ui->lcdnumber_currentval1->display(value);
    else ui->lcdnumber_currentval1->display(0);
//    if (OVEN->get_coil(PV2, value) == 0) ui->lcdnumber_currentval2->display(value);
//    else ui->lcdnumber_currentval2->display(0);

    // Set active lineedit
    ui->lineedit_mode1setpoint->setFocus();
}
// Mode 2 radiobutton clicked
void MainWindow::on_radiobutton_mode2_clicked(){
    // Set visibility
    ui->groupbox_mode1->setVisible(false);
    ui->groupbox_mode2->setVisible(true);

    // Enabling the mode 2 box
    ui->lineedit_mode2filename->setEnabled(false);
    ui->lineedit_mode2addtemperature->setEnabled(false);
    ui->lineedit_mode2addtime->setEnabled(false);
    ui->lineedit_mode2addtemperature->setText("");
    ui->lineedit_mode2addtime->setText("");
    ui->lineedit_mode2startingtemperature->setText("");
    ui->lineedit_mode2startingtemperature->setEnabled(true);
    ui->groupbox_mode2->setEnabled(true);
    ui->groupbox_mode2setpoints->setEnabled(true);
    ui->checkbox_mode2write->setChecked(false);
    ui->pushbutton_mode2stop->setEnabled(false);
    ui->pushbutton_mode2clear->setEnabled(false);
    ui->pushbutton_mode2removepoint->setEnabled(false);
    ui->pushbutton_mode2setcontrolpoints->setEnabled(false);
    ui->pushbutton_mode2addpoint->setEnabled(false);
    ui->pushbutton_mode2setstartingtemperature->setEnabled(true);
    refresh_plot2();
    refresh_trend();
    heating_profile.clear();
    heating_profile_copy.clear();

    // Disabling the mode 1 box
    ui->lineedit_mode1filename->setText("");
    ui->lineedit_mode1picname->setText("");
    ui->lineedit_mode1setpoint->setText("");
    ui->groupbox_mode1->setEnabled(false);
    ui->label_relay1status->setText("NaN");
    ui->label_relay2status->setText("NaN");
    ui->lcdnumber_currentval1->display(0);
    ui->lcdnumber_currentval2->display(0);
    ui->checkbox_mode1write->setChecked(false);
    refresh_plot1();

    // Reading current values for mode 2
    float value;
    if (OVEN->get_coil(PV1, value) == 0) ui->lcdnumber_mode2currentval1->display(value);
    else ui->lcdnumber_mode2currentval1->display(0);
//    if (OVEN->get_coil(PV2, value) == 0) ui->lcdnumber_mode2currentval2->display(value);
//    else ui->lcdnumber_mode2currentval2->display(0);

    // Set active lineedit
    ui->lineedit_mode2startingtemperature->setFocus();
}

// Function for plotting in the timer
uint8_t regulation_type;
double i_part, p_part, d_part;
double error[2];
double close_time;
uint8_t preparation_needed;
int32_t trending_time = 0;
int32_t time_counter = 0;
uint8_t heater_on = 0;
uint8_t get_data_count = 0;

void MainWindow::update_plot1(){
    // PWM Time counter
    std::cout << "Time increment: " << time_counter << std::endl;
    if (time_counter == 4800) time_counter = 0;
    else time_counter += 200;
    if ((time_counter < close_time) && (heater_on == 0)){
        OVEN->set_coil(rout1, 1000);
        std::cout << "HEATER ON" << std::endl;
        heater_on = 1;
        ui->label_relay1status->setText("1");
    }
    else if ((time_counter >= close_time) && (heater_on == 1)){
        OVEN->set_coil(rout1, 0);
        std::cout << "HEATER_OFF" << std::endl;
        heater_on = 0;
        ui->label_relay1status->setText("0");
    }

    // Counter for 1 second data getting
    if (get_data_count == 4){
        get_data_count = 0;
        // Plotting
        float temperature1;
        if (series_plot1->count() >= 50) x_axis_plot1->setRange(0, x_axis_plot1->max() + 1);
        if (OVEN->get_coil(PV1, temperature1) == 0){
            series_plot1->append(current_time_1, temperature1);
            ui->lcdnumber_currentval1->display(temperature1);
            current_time_1++;
        }

        // Getting actual error value
        error[0] = error[1];
        error[1] = ui->lineedit_mode1setpoint->text().toDouble() - temperature1;
        std::cout << "CUR: " << error[1] << "   PREV: " << error[0] << std::endl;

        // Growth control PD
        std::cout << "Regulation type: " << (uint16_t)regulation_type << std::endl;
        if (regulation_type == PD){
            if (std::abs(ui->lineedit_mode1setpoint->text().toDouble() - temperature1) > 3){
                p_part = error[1] * P_REG1 * PWM_PERIOD;
                d_part = (error[1] - error[0]) * D_REG1 * PWM_PERIOD;
                (p_part + d_part > PWM_PERIOD) ? (close_time = PWM_PERIOD) : ((p_part + d_part < 0) ? (close_time = 0) : (close_time = p_part + d_part));
                if ((close_time < 500) && (close_time != 0)) close_time = 500;
                std::cout << p_part << "   " << d_part << "   Close time: " << close_time << std::endl;
            }
            else{
                std::cout << ">>>> Go to PI <<<<" << std::endl;
                regulation_type = PI;
                i_part = 0;
            }
        }
        // Constant value control PI
        else if (regulation_type == PI){
            p_part = error[1] * P_REG2 * PWM_PERIOD;
            i_part += error[1] * I_REG2 * PWM_PERIOD;
            if (i_part < 0) i_part = 0;
            (p_part + i_part > PWM_PERIOD) ? (close_time = PWM_PERIOD) : ((p_part + i_part < 0) ? (close_time = 0) : (close_time = p_part + i_part));
            std::cout << p_part << "   " << i_part << "   Close time: " << close_time << std::endl;
        }

        // File writing
        if (data_file_1.is_open() == true){
            data_file_1 << current_time_1 << sym << temperature1 << sym << ui->label_relay1status->text().toStdString() << std::endl;
        }
    }
    else{
        get_data_count++;
    }
}

// Function for plotting in the timer
void MainWindow::update_plot2(){
    // PWM Time counter
    std::cout << "Time increment: " << time_counter << std::endl;
    if (time_counter == 4800) time_counter = 0;
    else time_counter += 200;
    if ((time_counter < close_time) && (heater_on == 0)){
        OVEN->set_coil(rout1, 1000);
        std::cout << "HEATER ON" << std::endl;
        heater_on = 1;
        ui->label_mode2relay1status->setText("1");
    }
    else if ((time_counter >= close_time) && (heater_on == 1)){
        OVEN->set_coil(rout1, 0);
        std::cout << "HEATER_OFF" << std::endl;
        heater_on = 0;
        ui->label_mode2relay1status->setText("0");
    }

    // 1 second passed
    if (get_data_count == 4){
        get_data_count = 0;

        // Getting current temperature values
        float value_1;
        if (OVEN->get_coil(PV1, value_1) == 0) ui->lcdnumber_mode2currentval1->display(value_1);

        // Plotting
        series_plot2->append(current_time_2, value_1);
        if (series_plot2->count() >= 50) x_axis_plot2->setMax(x_axis_plot2->max() + 1);

        // File writing
        if (data_file_2.is_open()) data_file_2 << current_time_2 << sym << value_1 << sym;

        // If the trend starts not from the current temperature, then we need to prepare the heater
        if (preparation_needed){
            std::cout << "Preparation" << std::endl;
            // If we got to the starting temperature
            if (std::abs((*(heating_profile.begin()))[1] - value_1) < 0.5){
                preparation_needed = 0;
                heating_profile_copy = heating_profile;
                if (heating_profile_copy.size() > 1){
                    auto next = heating_profile_copy.begin();
                    next++;
                    // If growing then use PD control
                    if ((*next)[1] > (*(heating_profile_copy.begin()))[1]){
                        regulation_type = PD;
                    }
                    // If sloping then use PD
                    else if ((*next)[1] < (*(heating_profile_copy.begin()))[1]){
                        regulation_type = PD;
                    }
                    // If maintaining then use PI
                    else{
                        regulation_type = PI;
                        i_part = 0;
                    }
                }
            }
            // If the starting temperature was not reached then go PD control
            else{
                error[0] = error[1];
                error[1] = (double)(*(heating_profile.begin()))[1] - value_1;
                //std::cout << error[0] << "  " << error[1] << std::endl;
                p_part = error[1] * P_REG1 * PWM_PERIOD;
                d_part = (error[1] - error[0]) * D_REG1 * PWM_PERIOD;
                (p_part + d_part > PWM_PERIOD) ? (close_time = PWM_PERIOD) : ((p_part + d_part < 0) ? (close_time = 0) : (close_time = p_part + d_part));
                if ((close_time < 300) && (close_time != 0)) close_time = 300;
                std::cout << close_time << std::endl;
            }

            // File writing
            if (data_file_2.is_open()) data_file_2 << (*(heating_profile.begin()))[1] << std::endl;
        }
        // If current temperature is the start of the trend
        else if (!preparation_needed){
            std::cout << "Profile" << std::endl;
            // If the profile has not ended
            if (heating_profile_copy.size() > 1){
                // Getting the next element
                auto next = heating_profile_copy.begin();
                next++;
                // While heating through the line
                if (trending_time < (*next)[0]){
                    // Getting the set value
                    double dtime = (*next)[0] - (*(heating_profile_copy.begin()))[0];
                    double dtemp = (*next)[1] - (*(heating_profile_copy.begin()))[1];
                    double speed = (double)dtemp / (double)dtime;
                    double trending_value = (double)(*(heating_profile_copy.begin()))[1] + speed * (trending_time - (*(heating_profile_copy.begin()))[0]);

                    // Refreshing the error
                    error[0] = error[1];
                    error[1] = trending_value - value_1;

                    // PI or PD control
                    if (regulation_type == PI){
                        if (std::abs(error[1]) > 3){
                            std::cout << "PI_PD" << std::endl;
                            p_part = error[1] * P_REG1 * PWM_PERIOD;
                            d_part = (error[1] - error[0]) * D_REG1 * PWM_PERIOD;
                            (p_part + d_part > PWM_PERIOD) ? (close_time = PWM_PERIOD) : ((p_part + d_part < 0) ? (close_time = 0) : (close_time = p_part + d_part));
                            if ((close_time < 300) && (close_time != 0)) close_time = 300;
                            std::cout << close_time << std::endl;
                        }
                        else{
                            std::cout << "PI_PI" << std::endl;
                            p_part = error[1] * P_REG2 * PWM_PERIOD;
                            i_part += error[1] * I_REG2 * PWM_PERIOD;
                            if (i_part < 0) i_part = 0;
                            (p_part + i_part > PWM_PERIOD) ? (close_time = PWM_PERIOD) : ((p_part + i_part < 0) ? (close_time = 0) : (close_time = p_part + i_part));
                            std::cout << close_time << std::endl;
                        }
                    }
                    else if (regulation_type == PD){
                        std::cout << "PD" << std::endl;
                        p_part = error[1] * P_REG1 * PWM_PERIOD;
                        d_part = (error[1] - error[0]) * D_REG1 * PWM_PERIOD;
                        (p_part + d_part > PWM_PERIOD) ? (close_time = PWM_PERIOD) : ((p_part + d_part < 0) ? (close_time = 0) : (close_time = p_part + d_part));
                        //if ((close_time < 500) && (close_time != 0)) close_time = 500;
                        std::cout << close_time << std::endl;
                    }
                }
                // When at the end
                else{
                    heating_profile_copy.pop_front();
                    if (heating_profile_copy.size() > 1){
                        next = heating_profile_copy.begin();
                        next++;
                        if ((*next)[1] > (*(heating_profile_copy.begin()))[1]){
                            regulation_type = PD;
                        }
                        else if ((*next)[1] < (*(heating_profile_copy.begin()))[1]){
                            regulation_type = PD;
                        }
                        else{
                            regulation_type = PI;
                            i_part = 0;
                        }
                    }
                }
                trending_time++;
            }
            else if (heating_profile_copy.size() == 1){
                error[0] = error[1];
                error[1] = (*(heating_profile_copy.begin()))[1] - value_1;
                close_time = ((*(heating_profile_copy.begin()))[1] - value_1) * P_REG1 * 5000;
                p_part = error[1] * P_REG2 * PWM_PERIOD;
                i_part += error[1] * I_REG2 * PWM_PERIOD;
                (p_part + i_part > PWM_PERIOD) ? (close_time = PWM_PERIOD) : ((p_part + i_part < 0) ? (close_time = 0) : (close_time = p_part + i_part));
                std::cout << "ENDED" << std::endl;
            }
            // File writing
            if (data_file_2.is_open()) data_file_2 << (*(heating_profile_copy.begin()))[1] << std::endl;
        }

        // Time incrementing
        current_time_2++;
    }
    else{
        get_data_count++;
    }
}

// Clears the plot
void MainWindow::refresh_plot1(void){
    if (plot1_timer->isActive()){
        plot1_timer->stop();
        plot1_timer->disconnect(plot1_timer, SIGNAL(timeout()), this, SLOT(update_plot1()));
    }

    series_plot1->clear();
    x_axis_plot1->setRange(0, 50);
    y_axis_plot1->setRange(0, 1000);
    time_counter = 0;
    current_time_1 = 0;
}
// Clears the plot
void MainWindow::refresh_plot2(void){
    if (plot2_timer->isActive()){
        plot2_timer->stop();
        plot2_timer->disconnect(plot2_timer, SIGNAL(timeout()), this, SLOT(update_plot2()));
    }

    close_time = 0;
    time_counter = 0;
    series_plot2->clear();
    x_axis_plot2->setRange(0, 50);
    y_axis_plot2->setRange(0, 1000);
    current_time_2 = 0;
    trending_time = 0;
}
// Clears the plot
void MainWindow::refresh_trend(void){
    series_trend->clear();
    x_axis_trend->setRange(0, 50);
    y_axis_trend->setRange(0, 20);
    heating_profile.clear();
    heating_profile_copy.clear();
}

// Set the point for heating
void MainWindow::on_pushbutton_mode1setpoint_clicked(){

    // Reading the value from the input 1
    float value_1;
    if (OVEN->get_coil(PV1, value_1) == 0) ui->lcdnumber_currentval1->display((int16_t)value_1);

    // Refreshing the plot 1
    refresh_plot1();
    y_axis_plot1->setMax(ui->lineedit_mode1setpoint->text().toInt() + 50);

    // Setting initial regulation type (PD)
    regulation_type = PD;

    // Setting availability of the GUI elements
    ui->pushbutton_stopmode1->setEnabled(true);
    ui->pushbutton_mode1setpoint->setEnabled(false);
    ui->pushbutton_mode1saveplot->setEnabled(false);
    ui->groupbox_connection->setEnabled(false);
    ui->groupbox_controlmode->setEnabled(false);
    ui->checkbox_mode1write->setEnabled(false);
    ui->lineedit_mode1filename->setEnabled(false);
    ui->lineedit_mode1picname->setEnabled(false);
    ui->lineedit_mode1setpoint->setEnabled(false);

    // Initializing file writing
    if ((ui->checkbox_mode1write->isChecked() == true) && (ui->lineedit_mode1filename->text().toStdString().length() > 0)){
        std::string csv_filename = ui->lineedit_mode1filename->text().toStdString() + ".csv";
        data_file_1.open(csv_filename, std::ios::out | std::ios::trunc);
        data_file_1 << "Setpoint (C):" << sym << ui->lineedit_mode1setpoint->text().toStdString();
        data_file_1 << std::endl << std::endl;
        data_file_1 << "Time (sec)" << sym << "Temperature 1 (C)" << sym << "Temperature 2 (C)" << sym << "Relay 1" << sym << "Relay 2" << std::endl;
    }

    // Start plotting
    connect(plot1_timer, SIGNAL(timeout()), this, SLOT(update_plot1()));
    plot1_timer->start(200);

    get_data_count = 0;
    heater_on = 0;
    close_time = 0;
    time_counter = 0;
    current_time_1 = 0;
}
// Set the list for heating
void MainWindow::on_pushbutton_mode2setcontrolpoints_clicked(){
    // Setting the availability for GUI elements
    ui->lineedit_mode2addtemperature->setEnabled(false);
    ui->lineedit_mode2addtime->setEnabled(false);
    ui->lineedit_mode2filename->setEnabled(false);
    ui->lineedit_mode2picname->setEnabled(false);
    ui->lineedit_mode2startingtemperature->setEnabled(false);
    ui->checkbox_mode2write->setEnabled(false);
    ui->pushbutton_mode2addpoint->setEnabled(false);
    ui->pushbutton_mode2clear->setEnabled(false);
    ui->pushbutton_mode2removepoint->setEnabled(false);
    ui->pushbutton_mode2saveplot->setEnabled(false);
    ui->pushbutton_mode2setstartingtemperature->setEnabled(false);
    ui->pushbutton_mode2setcontrolpoints->setEnabled(false);
    ui->pushbutton_mode2stop->setEnabled(true);
    ui->groupbox_controlmode->setEnabled(false);
    ui->groupbox_connection->setEnabled(false);

    // Reading the value from the input 1
    float value_1;
    if (OVEN->get_coil(PV1, value_1) == 0) ui->lcdnumber_mode2currentval1->display((int16_t)value_1);

    // Refreshing the plot 2 and trend
    refresh_plot2();
    y_axis_plot2->setMax(y_axis_trend->max());

    // Check if preheating or precooling needed
    if (std::abs((*(heating_profile.begin()))[1] - value_1) <= 0.5) preparation_needed = 0;
    else preparation_needed = 1;

    // Initializing file writing
    if ((ui->checkbox_mode2write->isChecked() == true) && (ui->lineedit_mode2filename->text().toStdString().length() > 0)){
        std::string csv_filename = ui->lineedit_mode2filename->text().toStdString() + ".csv";
        data_file_2.open(csv_filename, std::ios::out | std::ios::trunc);
        data_file_2 << "Time (sec)" << sym << "Temperature 1 (C)" << sym << "Set point (C)" << std::endl;
    }

    // Setting the initial state of the heater as OFF
    heater_on = 0;
    get_data_count = 0;
    current_time_2 = 0;
    close_time = 0;
    trending_time = 0;
    time_counter = 0;
    heating_profile_copy = heating_profile;

    // Start plotting
    connect(plot2_timer, SIGNAL(timeout()), this, SLOT(update_plot2()));
    plot2_timer->start(200);
}

// Button for theme changing "BLACK" or "WHITE"
void MainWindow::on_pushbutton_themechange_clicked(){
    if (theme == WHITE){
        this->setStyleSheet("QMainWindow, QGroupBox, QLabel, QRadioButton, QCheckBox { background-color: black; color: white }");
        theme = BLACK;
    }
    else if (theme == BLACK){
        this->setStyleSheet("QMainWindow, QGroupBox, QLabel, QRadioButton, QCheckBox { background-color: white; color: black }");
        theme = WHITE;
    }
}

// Stop heating and plotting
void MainWindow::on_pushbutton_stopmode1_clicked(){
    // Stop plotting
    if (plot1_timer->isActive()){
        plot1_timer->stop();
        plot1_timer->disconnect(plot1_timer, SIGNAL(timeout()), this, SLOT(update_plot1()));
    }
    if (timer_counter->isActive()){
        timer_counter->stop();
        timer_counter->disconnect(timer_counter, SIGNAL(timeout()), this, SLOT(counter()));
    }
    current_time_1 = 0;
    time_counter = 0;

    // Setting low set points
    OVEN->set_coil(SP1, 0);
//    OVEN->set_coil(SP2, 0);

    // Banning autonomous control
    OVEN->set_coil(r_L1, 1);
    OVEN->set_coil(r_L2, 1);

    // Turning off the relays
    OVEN->set_coil(rout1, 0);
    OVEN->set_coil(rout2, 0);

    // Set availability of the GUI elements
    ui->pushbutton_mode1setpoint->setEnabled(true);
    ui->pushbutton_stopmode1->setEnabled(false);
    ui->pushbutton_mode1saveplot->setEnabled(true);
    ui->groupbox_controlmode->setEnabled(true);
    ui->groupbox_connection->setEnabled(true);
    ui->checkbox_mode1write->setEnabled(true);
    ui->checkbox_mode1write->setChecked(false);
    ui->lineedit_mode1filename->setEnabled(false);
    ui->lineedit_mode1picname->setEnabled(true);
    ui->lineedit_mode1setpoint->setEnabled(true);

    // Save data file
    if (data_file_1.is_open() == true) data_file_1.close();

    // Set available lineedit
    ui->lineedit_mode1setpoint->setFocus();
}
// Stop heating and plotting
void MainWindow::on_pushbutton_mode2stop_clicked(){
    // Stop plotting
    if (plot2_timer->isActive()){
        plot2_timer->stop();
        plot2_timer->disconnect(plot2_timer, SIGNAL(timeout()), this, SLOT(update_plot2()));
    }

    // Turning off the relays
    OVEN->set_coil(rout1, 0);

    // Set availability of the GUI elements
    ui->pushbutton_mode2setcontrolpoints->setEnabled(true);
    ui->pushbutton_mode2stop->setEnabled(false);
    ui->groupbox_controlmode->setEnabled(true);
    ui->groupbox_connection->setEnabled(true);
    ui->lineedit_mode2filename->setEnabled(false);
    ui->lineedit_mode2picname->setEnabled(true);
    ui->checkbox_mode2write->setEnabled(true);
    ui->checkbox_mode2write->setChecked(false);
    ui->pushbutton_mode2saveplot->setEnabled(true);
    if (series_trend->count() > 1){
        ui->lineedit_mode2addtemperature->setEnabled(true);
        ui->lineedit_mode2addtime->setEnabled(true);
        ui->pushbutton_mode2addpoint->setEnabled(true);
        ui->pushbutton_mode2clear->setEnabled(true);
        ui->pushbutton_mode2removepoint->setEnabled(true);
    }
    else{
        ui->lineedit_mode2startingtemperature->setEnabled(true);
        ui->pushbutton_mode2setstartingtemperature->setEnabled(true);
    }

    // Save data file
    if (data_file_2.is_open() == true) data_file_2.close();

    // Set available lineedit
    if (series_trend->count() > 1) ui->lineedit_mode2addtime->setFocus();
    else ui->lineedit_mode2startingtemperature->setFocus();
}

// Check box for write enabling
void MainWindow::on_checkbox_mode1write_stateChanged(int arg1){
    if (arg1){
        ui->lineedit_mode1filename->setEnabled(true);
        ui->lineedit_mode1filename->setFocus();
    }
    else if (!arg1){
        ui->lineedit_mode1filename->setEnabled(false);
        ui->lineedit_mode1filename->setText("");
        ui->lineedit_mode1setpoint->setFocus();
    }
}
// Check box for write enabling
void MainWindow::on_checkbox_mode2write_stateChanged(int arg1){
    if (arg1){
        ui->lineedit_mode2filename->setEnabled(true);
        ui->lineedit_mode2filename->setFocus();
    }
    else if (!arg1){
        ui->lineedit_mode2filename->setEnabled(false);
        ui->lineedit_mode2filename->setText("");
        if (series_trend->count() >= 1) ui->lineedit_mode2addtime->setFocus();
        else ui->lineedit_mode2startingtemperature->setFocus();
    }
}

// Saving the plot for the mode 1
void MainWindow::on_pushbutton_mode1saveplot_clicked(){
    if (ui->lineedit_mode1picname->text().length() > 0){
        std::string image_name = ui->lineedit_mode1picname->text().toStdString() + ".bmp";
        QPixmap image = qcv_plot1->grab();
        image.save(QString::fromStdString(image_name), "BMP");
    }
}
// Saving the plots for the mode 2
void MainWindow::on_pushbutton_mode2saveplot_clicked(){
    if (ui->lineedit_mode2picname->text().length() > 0){
        std::string image_plot_name = ui->lineedit_mode2picname->text().toStdString() + "_plot.bmp";
        std::string image_trend_name = ui->lineedit_mode2picname->text().toStdString() + "_trend.bmp";
        QPixmap image_plot = qcv_plot2->grab();
        QPixmap image_trend = qcv_trend->grab();
        image_plot.save(QString::fromStdString(image_plot_name), "BMP");
        image_trend.save(QString::fromStdString(image_trend_name), "BMP");
    }
}

// Starting point of the profile
void MainWindow::on_pushbutton_mode2setstartingtemperature_clicked(){
    if (ui->lineedit_mode2startingtemperature->text().length() > 0){
        heating_profile.push_back(std::array<int, 2>({0, ui->lineedit_mode2startingtemperature->text().toInt()}));
        series_trend->append(0, ui->lineedit_mode2startingtemperature->text().toInt());
        ui->lineedit_mode2addtemperature->setEnabled(true);
        ui->lineedit_mode2addtime->setEnabled(true);
        ui->lineedit_mode2startingtemperature->setEnabled(false);
        ui->pushbutton_mode2addpoint->setEnabled(true);
        ui->pushbutton_mode2removepoint->setEnabled(true);
        ui->pushbutton_mode2clear->setEnabled(true);
        ui->pushbutton_mode2setcontrolpoints->setEnabled(true);
        ui->pushbutton_mode2setstartingtemperature->setEnabled(false);
        ui->pushbutton_mode2stop->setEnabled(false);

        if (heating_profile.back()[1] > (y_axis_trend->max() - 50)) y_axis_trend->setMax(heating_profile.back()[1] + 50);

        // Set active lineedit
        ui->lineedit_mode2addtime->setFocus();
    }
}
// Adding point to the array
void MainWindow::on_pushbutton_mode2addpoint_clicked(){
    if ((ui->lineedit_mode2addtemperature->text().length() > 0) && (ui->lineedit_mode2addtime->text().length() > 0) && (ui->lineedit_mode2addtime->text().toInt() > heating_profile.back()[0])){
        heating_profile.push_back(std::array<int, 2>({ui->lineedit_mode2addtime->text().toInt(), ui->lineedit_mode2addtemperature->text().toInt()}));
        series_trend->append(ui->lineedit_mode2addtime->text().toInt(), ui->lineedit_mode2addtemperature->text().toInt());
        ui->lineedit_mode2addtemperature->setText("");
        ui->lineedit_mode2addtime->setText("");
        if (heating_profile.back()[0] > x_axis_trend->max()) x_axis_trend->setMax(heating_profile.back()[0]);

        if (heating_profile.back()[1] > (y_axis_trend->max() - 50)) y_axis_trend->setMax(heating_profile.back()[1] + 50);

        // Set available lineedit
        ui->lineedit_mode2addtime->setFocus();
    }
}
// Removing the last point in the list
void MainWindow::on_pushbutton_mode2removepoint_clicked(){
    // Check if the starting point is being deleted
    if (series_trend->count() == 1){
        ui->lineedit_mode2addtemperature->setText("");
        ui->lineedit_mode2addtemperature->setEnabled(false);
        ui->lineedit_mode2addtime->setText("");
        ui->lineedit_mode2addtime->setEnabled(false);
        ui->lineedit_mode2startingtemperature->setText("");
        ui->lineedit_mode2startingtemperature->setEnabled(true);
        ui->pushbutton_mode2addpoint->setEnabled(false);
        ui->pushbutton_mode2clear->setEnabled(false);
        ui->pushbutton_mode2removepoint->setEnabled(false);
        ui->pushbutton_mode2setcontrolpoints->setEnabled(false);
        ui->pushbutton_mode2setstartingtemperature->setEnabled(true);
    }
    else{
        // Check if the axis should be corrected
        if (series_trend->at(series_trend->count() - 2).x() >= 50) x_axis_trend->setMax(series_trend->at(series_trend->count() - 2).x());
        else x_axis_trend->setMax(50);
    }
    // Delete the back element
    series_trend->remove(series_trend->count() - 1);
    heating_profile.pop_back();
}
// Clearing the trend plot
void MainWindow::on_pushbutton_mode2clear_clicked(){
    // Set the availability of GUI elements
    ui->lineedit_mode2addtemperature->setText("");
    ui->lineedit_mode2addtemperature->setEnabled(false);
    ui->lineedit_mode2addtime->setText("");
    ui->lineedit_mode2addtime->setEnabled(false);
    ui->lineedit_mode2startingtemperature->setText("");
    ui->lineedit_mode2startingtemperature->setEnabled(true);
    ui->pushbutton_mode2addpoint->setEnabled(false);
    ui->pushbutton_mode2clear->setEnabled(false);
    ui->pushbutton_mode2removepoint->setEnabled(false);
    ui->pushbutton_mode2setcontrolpoints->setEnabled(false);
    ui->pushbutton_mode2setstartingtemperature->setEnabled(true);
    // Clearing the heating profile list
    heating_profile.clear();
    // Resetting the trend plot
    refresh_trend();
}


// Line edit additional functions
void MainWindow::on_lineedit_mode2startingtemperature_returnPressed(){
    on_pushbutton_mode2setstartingtemperature_clicked();
}
void MainWindow::on_lineedit_mode2picname_returnPressed(){
    on_pushbutton_mode2saveplot_clicked();
}
void MainWindow::on_lineedit_slaveid_returnPressed(){
    on_button_connect_clicked();
}
void MainWindow::on_lineedit_mode2addtemperature_returnPressed(){
    on_pushbutton_mode2addpoint_clicked();
}
void MainWindow::on_lineedit_mode1setpoint_returnPressed(){
    on_pushbutton_mode1setpoint_clicked();
}
void MainWindow::on_lineedit_mode1picname_returnPressed(){
    on_pushbutton_mode1saveplot_clicked();
}
