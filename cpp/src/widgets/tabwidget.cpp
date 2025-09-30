#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>


#include "mainwindow.hpp"
#include "tabwidget.hpp"

TabWidget::TabWidget(QWidget *parent) {
    setObjectName("TabWidget");

    addTab(new QWidget(this), QString(tr("File")));
    addTab(new QWidget(this), QString(tr("Main")));
    addTab(new QWidget(this), QString(tr("View")));
    addTab(new QWidget(this), QString(tr("Geometry")));
}