#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

#include "mainwindow.hpp"
#include "tabwidget.hpp"

TabWidget::TabWidget(QWidget *parent) {
    setObjectName("TabWidget");

    QLabel *label1 = new QLabel("QLabel_1", this);
    QLabel *label2 = new QLabel("QLabel_2", this);
    QLabel *label3 = new QLabel("QLabel_3", this);
    QLabel *label4 = new QLabel("QLabel_4", this);

    addTab(label1, QString(tr("File")));
    addTab(label2, QString(tr("Main")));
    addTab(label3, QString(tr("View")));
    addTab(label4, QString(tr("Geometry")));

    // setStyleSheet("color: blue;");
}