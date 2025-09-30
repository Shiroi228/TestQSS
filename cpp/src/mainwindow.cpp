#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "mainwindow.hpp"

/*
 * MainWindow
 *
 * */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), tabWidget_(new TabWidget(this)) {
    // showFullScreen();
    setMinimumSize({800, 600});

    setObjectName("MainWindow");

    auto *const centerWidget = new QWidget(this);
    auto *const layout = new QHBoxLayout(centerWidget);

    layout->addWidget(tabWidget_);
    
    setCentralWidget(centerWidget);
}