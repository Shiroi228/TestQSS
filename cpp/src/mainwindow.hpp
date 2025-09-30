#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "widgets/tabwidget.hpp"

/*
 * MainWindow
 *
 * */

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private:
    TabWidget *tabWidget_;

};

#endif // MAINWINDOW_H
