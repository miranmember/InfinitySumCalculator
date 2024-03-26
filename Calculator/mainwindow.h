#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_1_clicked();

    void initial_click(const QString& text);

    void runOperation();

    std::string runAddition();

    void runClear();

    void on_pushButton_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_0_clicked();

    void on_pushButton_addition_clicked();

    void on_pushButton_equals_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    std::string num1;
    std::string num2;
    char operation;
};
#endif // MAINWINDOW_H
