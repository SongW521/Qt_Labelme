#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvaswidget.h"
#include "docklistwidget.h"
#include "docklabelwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    void findImagesRecursively(const QString &directoryPath);
    void toolBarsInit();
    void dockWidgetInit();
    void loadLabelsMessage(const QVector<flagBuffer> &buffers);
    bool saveBufferToJson();

private slots:
    void openflieActionTriggered();
    void openDirActionTriggered();
    void outputDirActionTriggered();
    void autoSaveActionTriggered(bool checked);
    void delflieActionTriggered();
    void undoActionTriggered();
    void lastActionTriggered();
    void nextActionTriggered();
    void ellipseActionTriggered(bool checked);
    void copyActionTriggered();
    void loadImage(QString imgName);


private:
    Ui::MainWindow *ui;
    DockLabelWidget *dockLabelWidget;
    DockListWidget  *dockListwidget ;
    QStringList files;
    QString outputFileName;
    QVector<flagBuffer> flagbuffers;
    int currentIndex = 0;
    bool autoSaveState = false;
signals:
    void loadList(QStringList fileList);
    void updateIndex(int index);
};
#endif // MAINWINDOW_H
