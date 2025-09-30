#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QLibraryInfo>
#include <QTextCodec>
#include <QTranslator>
#include <QVector>

#include "src/mainwindow.hpp"

void loadStyleSheet(QApplication& app, const QString& fileName) {
    QFile styleFile(fileName);
    if (styleFile.open(QFile::ReadOnly)) {
        QTextStream stream(&styleFile);
        QString style = stream.readAll();
        qWarning("loadStyleSheet");
        app.setStyleSheet(style);
        styleFile.close();
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setOrganizationName("Vadeev");
    QApplication::setApplicationName("TestQSS");

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QTranslator qtTranslator;
    qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    QApplication::installTranslator(&qtTranslator);

    QString translationPath = QCoreApplication::applicationDirPath() + "/translations";
    QVector<QTranslator*> translators;
    QDir dir(translationPath);

    if (!dir.exists()) {
        qDebug() << "Translation directory not found:" << translationPath;
    } else {
        QStringList filters;
        filters << "*.qm";
        QFileInfoList fileList = dir.entryInfoList(filters, QDir::Files);

        for (const QFileInfo &fileInfo : fileList) {
            QTranslator* translator = new QTranslator(&app);
            if (translator->load(fileInfo.absoluteFilePath())) {
                app.installTranslator(translator);
                translators.append(translator);
                qDebug() << "Loaded translation:" << fileInfo.fileName();
            } else {
                qDebug() << "Failed to load translation:" << fileInfo.fileName();
                delete translator;
            }
        }
    }

    // QFile styleFile(":/style/style.qss");
    // if (styleFile.open(QFile::ReadOnly)) {
    //     QTextStream stream(&styleFile);
    //     QString style = stream.readAll();
    //     qWarning("loadStyleSheet");
    //     app.setStyleSheet(style);
    //     styleFile.close();
    // } else {
    //     qWarning("no loadStyleSheet");
    // }
    loadStyleSheet(app, ":/style/style.qss");
    MainWindow w;
    
    w.setWindowTitle("TestQSS");
    w.show();

    return app.exec();
}