#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class NotePad;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void toolbar();


private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_2_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionPaste_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionBackground_color_triggered();

    void on_actionBackground_window_triggered();

    void on_actionPrint_triggered();



private:
    Ui::NotePad *ui;
    QString filename;
};
#endif // MAINWINDOW_H
