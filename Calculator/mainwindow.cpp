#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::string num1 = "";
    std::string num2 = "";
    char operation = ' ';
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initial_click(const QString& text) {
    QString currentText = ui->textBrowser->toPlainText();
    QString historyText = ui->textBrowser_2->toPlainText();
    historyText.chop(1);
    if (operation == '=') runClear();
    if (currentText == "0" || currentText == historyText) {
        ui->textBrowser->clear();
        ui->textBrowser->insertPlainText(text);
        return;
    }
    ui->textBrowser->insertPlainText(text);
}

void MainWindow::runOperation() {
    std::string result;
    switch (operation) {
    case '+':
        result = runAddition();
        operation = '=';
        break;
    }

    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText(QString::fromStdString(result));
}

std::string MainWindow::runAddition() {
    std::string result;
    int carry = 0;
    int i = num1.size() - 1;
    int j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        sum %= 10;
        result.insert(result.begin(), sum + '0'); // Insert sum digit at the beginning
    }

    return result;
}

void MainWindow::runClear() {
    this->num1 = "";
    this->num2 = "";
    operation = ' ';
    ui->textBrowser_2->clear();
    ui->textBrowser->clear();
}

void MainWindow::on_pushButton_1_clicked()
{
    initial_click(ui->pushButton_1->text());
}


void MainWindow::on_pushButton_2_clicked()
{
    initial_click(ui->pushButton_2->text());
}


void MainWindow::on_pushButton_11_clicked()
{
    initial_click(ui->pushButton_11->text());
}


void MainWindow::on_pushButton_5_clicked()
{
    initial_click(ui->pushButton_5->text());
}


void MainWindow::on_pushButton_8_clicked()
{
    initial_click(ui->pushButton_8->text());
}


void MainWindow::on_pushButton_9_clicked()
{
    initial_click(ui->pushButton_9->text());
}


void MainWindow::on_pushButton_12_clicked()
{
    initial_click(ui->pushButton_12->text());
}


void MainWindow::on_pushButton_14_clicked()
{
    initial_click(ui->pushButton_14->text());
}


void MainWindow::on_pushButton_17_clicked()
{
    initial_click(ui->pushButton_17->text());
}


void MainWindow::on_pushButton_0_clicked()
{
    initial_click(ui->pushButton_0->text());
}



void MainWindow::on_pushButton_addition_clicked()
{
    if (num1 != "" && operation != '=') return;
    this->num1 = ui->textBrowser->toPlainText().toStdString();
    if (operation == '=') {
        std::string temp = num1;
        runClear();
        num1 = temp;
    }
    ui->textBrowser_2->insertPlainText(QString::fromStdString(num1 + "+"));
    operation = '+';
}


void MainWindow::on_pushButton_equals_clicked()
{
    if (num1 == "" || operation == '=') return;
    ui->textBrowser_2->insertPlainText(ui->textBrowser->toPlainText() + "=");
    this->num2 = ui->textBrowser->toPlainText().toStdString();

    runOperation();
}


void MainWindow::on_pushButton_3_clicked()
{
    runClear();
    ui->textBrowser->insertPlainText("0");
}

