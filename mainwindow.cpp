#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    toolBarsInit();
    dockWidgetInit();

    //绑定绘图板信号
    connect(ui->graphicsView,&CanVasWidget::drawFinish,this,[=](){
        ui->ellipseShapeAC->setChecked(false);
        flagbuffers = ui->graphicsView->getItemsFlagBuffer();
        loadLabelsMessage(flagbuffers);
    });
}
//初始化工具栏
void MainWindow::toolBarsInit()
{
    //添加自动保存
    QAction *autoSaveAC = new QAction(this);
    autoSaveAC->setText("自动保存");
    autoSaveAC->setIcon(QIcon(":/icon/autosave"));
    autoSaveAC->setCheckable(true);
    autoSaveAC->setChecked(true);

    //添加工具栏
    ui->setupUi(this);
    ui->toolBar->addAction(ui->openFileAC);
    ui->toolBar->addAction(ui->openDirAC);
    ui->toolBar->addAction(ui->outputDirAC);
    ui->toolBar->addAction(autoSaveAC);
    ui->toolBar->addAction(ui->delFileAC);
    ui->toolBar->addAction(ui->undoAC);
    ui->toolBar->addAction(ui->lastAC);
    ui->toolBar->addAction(ui->nextAC);

    ui->toolBar->addAction(ui->ellipseShapeAC);
    ui->toolBar->addAction(ui->copyAC);
    ui->ellipseShapeAC->setCheckable(true);
    //设置Action的图标
    ui->saveAC->setIcon(QIcon(":/icon/save"));
    ui->openFileAC->setIcon(QIcon(":/icon/openfile"));
    ui->openDirAC->setIcon(QIcon(":/icon/opendir"));
    ui->outputDirAC->setIcon(QIcon(":/icon/output"));
    ui->lastAC->setIcon(QIcon(":/icon/last"));
    ui->nextAC->setIcon(QIcon(":/icon/next"));

    ui->delFileAC->setIcon(QIcon(":/icon/del"));
    ui->undoAC->setIcon(QIcon(":/icon/undo"));
    ui->copyAC->setIcon(QIcon(":/icon/copy"));
    ui->ellipseShapeAC->setIcon(QIcon(":/icon/ellipse"));

    //绑定Action事件
    connect(ui->openFileAC,&QAction::triggered,this,&MainWindow::openflieActionTriggered);
    connect(ui->openDirAC,&QAction::triggered,this,&MainWindow::openDirActionTriggered);
    connect(ui->outputDirAC,&QAction::triggered,this,&MainWindow::outputDirActionTriggered);
    connect(autoSaveAC,&QAction::triggered,this,&MainWindow::autoSaveActionTriggered);
    connect(ui->delFileAC,&QAction::triggered,this,&MainWindow::delflieActionTriggered);
    connect(ui->undoAC,&QAction::triggered,this,&MainWindow::undoActionTriggered);
    connect(ui->nextAC,&QAction::triggered,this,&MainWindow::nextActionTriggered);
    connect(ui->lastAC,&QAction::triggered,this,&MainWindow::lastActionTriggered);
    connect(ui->ellipseShapeAC,&QAction::triggered,this,&MainWindow::ellipseActionTriggered);
    connect(ui->copyAC,&QAction::triggered,this,&MainWindow::copyActionTriggered);

}
//初始化子窗口
void MainWindow::dockWidgetInit()
{
    //添加子窗口
    QDockWidget *dock1 = new QDockWidget("数据标签", this);
    QDockWidget *dock2 = new QDockWidget("图像列表", this);
    dockLabelWidget = new DockLabelWidget(dock1);
    dockListwidget = new DockListWidget(dock2);
    dock1->setWidget(dockLabelWidget);
    dock2->setWidget(dockListwidget);
    this->addDockWidget(Qt::RightDockWidgetArea, dock1,Qt::Vertical);
    this->addDockWidget(Qt::RightDockWidgetArea, dock2,Qt::Vertical);
    //连接槽函数显示文件列表
    connect(this,&MainWindow::loadList,dockListwidget,&DockListWidget::updateListView);
    connect(dockListwidget,&DockListWidget::itemClicked,this,[=](int index){
        currentIndex = index;
        loadImage(files[index]);
    });
    //连接槽函数更新当前下标
    connect(this,&MainWindow::updateIndex,dockListwidget,&DockListWidget::updateCurrentItem);
}

void MainWindow::loadLabelsMessage(const QVector<flagBuffer> &buffers)
{
    QList<QPair<QString, QString>> contents;
    QPair<QString, QString> content;
    for(int i = 0;i<buffers.length();i++){
         QString message = QString("P(%1,%2) w: %3 h: %4 t: %5" )
                                .arg(buffers[i].center.x())
                                .arg(buffers[i].center.y())
                                .arg(buffers[i].w)
                                .arg(buffers[i].h)
                                .arg(buffers[i].angle);
         content = {flagbuffers[i].labelname,message};
         contents.append(content);
    }
    dockLabelWidget->addContents(contents);
}


MainWindow::~MainWindow()
{
    delete ui;
}
//打开文件
void MainWindow::openflieActionTriggered()
{
    // 定义文件过滤器
    QString filter = tr("Image Files (*.png *.jpg *.jpeg)") + ";;";
    filter += tr("Text Files (*.txt)") + ";;";
    filter += tr("All Files (*)");
    //定义默认路径
    QString defaultPath = "D:/";
    //文件选择器
    QString file = QFileDialog::getOpenFileName(this, tr("选择图片"),defaultPath, filter);
    files.clear();
    files.append(file);
    emit loadList(files);
    //更新当前图像下标
    currentIndex = 0;
    loadImage(files[0]);
}
//打开目录
void MainWindow::openDirActionTriggered()
{
    files.clear();
    //定义默认路径
    QString defaultPath = "E:/";
    //文件选择器
    QString dirPath = QFileDialog::getExistingDirectory(this, tr("选择图片"),defaultPath);
    if (!dirPath.isEmpty()) {
        // 用户选择了一个目录
        findImagesRecursively(dirPath);
        if(!files.empty()){
            //加载图像列表
            emit loadList(files);
            //更新当前图像下标
            currentIndex = 0;
            loadImage(files[0]);
        }
    }

}
//输出目录
void MainWindow::outputDirActionTriggered()
{
    //根据ui下自定义路径选择文件夹

}
//自动保存
void MainWindow::autoSaveActionTriggered(bool checked)
{
    if(checked){
        autoSaveState = true;
    }
    else{
        autoSaveState = false;
    }
}
//删除文件
void MainWindow::delflieActionTriggered()
{
    if(QFile::remove(files[currentIndex])){
        //如果存在json文件，则删除该文件
        QMessageBox::information(this,"提示","删除成功");
    }
    else{
        QMessageBox::warning(this,"错误","找不到文件");
    }
}
//撤销
void MainWindow::undoActionTriggered()
{
}
//上一文件
void MainWindow::lastActionTriggered()
{
    if(autoSaveState && flagbuffers.isDetached()){
        saveBufferToJson();
    }
    currentIndex --;
    if(currentIndex < 0){
        QMessageBox::information(this,"提示：","没有更多图片");
        currentIndex = 0;
    }
    else{
        loadImage(files[currentIndex]);
        emit updateIndex(currentIndex);
    }


}
//下一个文件
void MainWindow::nextActionTriggered()
{
    if(autoSaveState && flagbuffers.isDetached()){
        saveBufferToJson();
    }
    currentIndex ++;
    if(currentIndex >= files.length()){
        QMessageBox::information(this,"提示：","没有更多图片");
            currentIndex --;
    }
    else{
        loadImage(files[currentIndex]);
        emit updateIndex(currentIndex);
    }

}
//绘制椭圆
void MainWindow::ellipseActionTriggered(bool checked)
{
    if(files.empty()){
        QMessageBox::information(this,"提示：","没有图片");
        ui->ellipseShapeAC->setChecked(false);
    }
    else if(checked && files.isDetached()){
        ui->graphicsView->setDrawMode(true);
    }
    else{
        ui->graphicsView->setDrawMode(false);
    }
}

//复制图像
void MainWindow::copyActionTriggered()
{

}
//加载图片
void MainWindow::loadImage(QString imgName)
{
    QPixmap pixmap = QPixmap(imgName);
    ui->graphicsView->updateBkgroudImage(pixmap);
}


//保存为JSON文件
bool MainWindow::saveBufferToJson()
{
    outputFileName = files[currentIndex].left(files[currentIndex].length() - 4) + ".json";
    //解析参数
    for(int i= 0;i < flagbuffers.length();i++ ){
        qDebug() << flagbuffers[i].labelname << flagbuffers[i].angle;
        qDebug() << flagbuffers[i].w << flagbuffers[i].h ;
        qDebug() << flagbuffers[i].center;
    }
    QJsonArray jsonArray;
    for (const flagBuffer &buffer : flagbuffers) {
        QJsonObject jsonObj;
        jsonObj["label"] = buffer.labelname;
        jsonObj["center_X"] = buffer.center.x();
        jsonObj["center_Y"] = buffer.center.y();
        jsonObj["width"] = buffer.w;
        jsonObj["height"] = buffer.h;
        jsonObj["angle"] = buffer.angle;
        jsonArray.append(jsonObj);
    }

    QFile file(outputFileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open file for writing.");
        return false;
    }

    QJsonDocument jsonDoc(jsonArray);
    file.write(jsonDoc.toJson());
    file.close();
    return true;
}
//递归查找图像
void MainWindow::findImagesRecursively(const QString &directoryPath) {
    QDir directory(directoryPath);
    // 设置要搜索的图片文件扩展名
    QStringList imageExtensions;
    imageExtensions << "png" << "jpg" << "bmp";

    // 获取目录中的所有条目
    foreach (const QFileInfo &fileInfo,directory.entryInfoList(QDir::Files
                                | QDir::Dirs | QDir::NoDotAndDotDot)) {
        if (fileInfo.isDir()) {
            findImagesRecursively(fileInfo.filePath());
        }
        else {
            // 检查文件扩展名是否是图片格式
            if (imageExtensions.contains(fileInfo.suffix().toLower())) {
                files.append(fileInfo.absoluteFilePath());
            }
        }
    }
}

