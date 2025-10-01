#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

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
    auto *const layout = new QVBoxLayout(centerWidget);
    auto *const titleLayout = new QHBoxLayout();

    titleLayout->addStretch(1);
    titleLayout->addWidget(new QLabel("Nazvanie", this));
    titleLayout->addStretch(1);
    
    layout->addLayout(titleLayout);
    layout->addWidget(tabWidget_);
    
    setCentralWidget(centerWidget);
}