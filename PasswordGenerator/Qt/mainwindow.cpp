#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QClipboard>

#include "pwdgenerator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonCopyClipboard, SIGNAL(clicked()), this, SLOT(onCopyClipboardClicked()));
    connect(ui->pushButtonGeneratePwd, SIGNAL(clicked()), this, SLOT(onGeneratePwdClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onCopyClipboardClicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->lineEdit->text());
}


void MainWindow::onGeneratePwdClicked()
{
    const int letters = ui->spinBoxLetters->value();
    const int symbols = ui->spinBoxSymbols->value();
    const int numbers = ui->spinBoxNumbers->value();
    ui->lineEdit->setText(PwdGenerator::generatePassword(letters, numbers, symbols));
}

