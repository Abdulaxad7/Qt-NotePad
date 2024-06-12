#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QHBoxLayout>
#include<QFileDialog>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QFont>
#include<QFontDialog>
#include<QColorDialog>
#include<QColor>
#include<QPrintDialog>
#include<QPrinter>
#include<QGraphicsBlurEffect>
#include<QPixmap>
#include<QGraphicsEffect>
#include<QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NotePad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

    // ... add actions to toolbar ...

    // QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
    // blurEffect->setBlurRadius(2);
    // MainWindow::centralWidget()->setGraphicsEffect(blurEffect);


    MainWindow::setStyleSheet("background-color: rgb(0,0,0);");
    MainWindow::setWindowOpacity(0.9); // Adjust opacity as needed

// 40, 40, 40, 0.8
    QIcon icon(":/windows-copy-icon-5.jpg.png");
    setWindowIcon(icon);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::toolbar(){
    QToolBar *toolbar = new QToolBar(this);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(toolbar);
    layout->setAlignment(Qt::AlignCenter); // Optional for centering
    setLayout(layout);


    /*toolbar->setStyleSheet("background-color: rgba(40, 40, 40, 0.8);");
    toolbar->setWindowOpacity(0.1);*/ // Adjust opacity as needed

    // QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect();
    // blurEffect->setBlurRadius(30); // Adjust radius as needed
    // toolbar->setGraphicsEffect(blurEffect);





}


void MainWindow::on_actionNew_triggered()
{
    filename="";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString filename=QFileDialog::getOpenFileName(this,"Open the filename");
    QFile file(filename);
    if(!file.open(QFile::ReadOnly)|QFile::Text){
        // QMessageBox::warning(this," "," file not open");
        return;
    }
     QTextStream in(&file);
    QString text =in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,"Open the filename");

    QFile file(filename);
    if(!file.open(QFile::WriteOnly)|QFile::Text){
        // QMessageBox::warning(this," "," ");
        return;
    }
    QTextStream out(&file);
    QString text =ui->textEdit->toPlainText();

        out<<text;
        file.flush();
        file.close();
}


void MainWindow::on_actionSave_2_triggered()
{
    QString filename=QFileDialog::getSaveFileName(this,"Open the filename");
    QFile file(filename);
    filename=filename;

    if(!file.open(QFile::WriteOnly)|QFile::Text){
        // QMessageBox::warning(this," "," file not open");
        return;
    }
    QTextStream out(&file);
    QString text =ui->textEdit->toPlainText();

    out<<text;
    file.flush();
    file.close();
    // ui->textEdit->sa
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->paste();

}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionPaste_triggered()

{
    ui->textEdit->copy();

}


void MainWindow::on_actionExit_triggered()
{
    exit(0);
}


void MainWindow::on_actionAbout_triggered()
{
    QString about_text;
    about_text="Auther  : somebody\n";
    about_text+="Date  : 12/3/4231\n";
    about_text+="Mac/  : Users/abdulaxad\n";
    about_text+="Notepad  : (R)\n";
    QMessageBox::about(this,"Title ",about_text);

}


void MainWindow::on_actionFont_triggered()

{
    bool check;
    QFont font =QFontDialog::getFont(&check,this);
    if(check){
        ui->textEdit->setFont(font);
    }else return;
}


void MainWindow::on_actionColor_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose Color ");
    if(color.isValid()){
        ui->textEdit->setTextColor(color);

    }else return ;
}


void MainWindow::on_actionBackground_color_triggered()
{
    QColor color=QColorDialog::getColor(Qt::white,this,"Choose Color ");
    if(color.isValid()){
        ui->textEdit->setTextBackgroundColor(color);

    }else return ;
}


void MainWindow::on_actionBackground_window_triggered()
{
    QColor color=QColorDialog::getColor("Choose Color ");
    if(color.isValid()){
        ui->textEdit->setPalette(QPalette(color));

    }
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)return;
    ui->textEdit->print(&printer);
}




