/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <canvaswidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_3;
    QAction *openFileAC;
    QAction *openDirAC;
    QAction *saveAC;
    QAction *saveasAC;
    QAction *closeAC;
    QAction *outputDirAC;
    QAction *lastAC;
    QAction *action_20;
    QAction *nextAC;
    QAction *action_26;
    QAction *undoAC;
    QAction *action_30;
    QAction *action_31;
    QAction *createAC;
    QAction *copyAC;
    QAction *delAimAC;
    QAction *ellipseShapeAC;
    QAction *setlineAC;
    QAction *delFileAC;
    QAction *editLabelAC;
    QAction *action_2;
    QAction *action_4;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    CanVasWidget *graphicsView;
    QStatusBar *statusbar;
    QMenuBar *menuBar;
    QMenu *fileMU;
    QMenu *editMU;
    QMenu *toolMU;
    QMenu *helpMU;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(769, 619);
        MainWindow->setContextMenuPolicy(Qt::ActionsContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/tools"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(40, 40));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->setAnimated(true);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_3 = new QAction(MainWindow);
        action_3->setObjectName("action_3");
        openFileAC = new QAction(MainWindow);
        openFileAC->setObjectName("openFileAC");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/resource/icon/Newtest.png"), QSize(), QIcon::Normal, QIcon::Off);
        openFileAC->setIcon(icon1);
        openDirAC = new QAction(MainWindow);
        openDirAC->setObjectName("openDirAC");
        saveAC = new QAction(MainWindow);
        saveAC->setObjectName("saveAC");
        saveasAC = new QAction(MainWindow);
        saveasAC->setObjectName("saveasAC");
        closeAC = new QAction(MainWindow);
        closeAC->setObjectName("closeAC");
        outputDirAC = new QAction(MainWindow);
        outputDirAC->setObjectName("outputDirAC");
        lastAC = new QAction(MainWindow);
        lastAC->setObjectName("lastAC");
        action_20 = new QAction(MainWindow);
        action_20->setObjectName("action_20");
        nextAC = new QAction(MainWindow);
        nextAC->setObjectName("nextAC");
        action_26 = new QAction(MainWindow);
        action_26->setObjectName("action_26");
        undoAC = new QAction(MainWindow);
        undoAC->setObjectName("undoAC");
        action_30 = new QAction(MainWindow);
        action_30->setObjectName("action_30");
        action_31 = new QAction(MainWindow);
        action_31->setObjectName("action_31");
        createAC = new QAction(MainWindow);
        createAC->setObjectName("createAC");
        copyAC = new QAction(MainWindow);
        copyAC->setObjectName("copyAC");
        delAimAC = new QAction(MainWindow);
        delAimAC->setObjectName("delAimAC");
        ellipseShapeAC = new QAction(MainWindow);
        ellipseShapeAC->setObjectName("ellipseShapeAC");
        setlineAC = new QAction(MainWindow);
        setlineAC->setObjectName("setlineAC");
        delFileAC = new QAction(MainWindow);
        delFileAC->setObjectName("delFileAC");
        editLabelAC = new QAction(MainWindow);
        editLabelAC->setObjectName("editLabelAC");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new CanVasWidget(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 769, 24));
        fileMU = new QMenu(menuBar);
        fileMU->setObjectName("fileMU");
        editMU = new QMenu(menuBar);
        editMU->setObjectName("editMU");
        toolMU = new QMenu(menuBar);
        toolMU->setObjectName("toolMU");
        helpMU = new QMenu(menuBar);
        helpMU->setObjectName("helpMU");
        MainWindow->setMenuBar(menuBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        toolBar->setMinimumSize(QSize(0, 0));
        toolBar->setIconSize(QSize(50, 50));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menuBar->addAction(fileMU->menuAction());
        menuBar->addAction(editMU->menuAction());
        menuBar->addAction(toolMU->menuAction());
        menuBar->addAction(helpMU->menuAction());
        fileMU->addAction(openFileAC);
        fileMU->addSeparator();
        fileMU->addAction(openDirAC);
        fileMU->addAction(saveasAC);
        fileMU->addSeparator();
        fileMU->addSeparator();
        fileMU->addAction(saveAC);
        fileMU->addSeparator();
        fileMU->addAction(closeAC);
        fileMU->addSeparator();
        fileMU->addSeparator();
        fileMU->addAction(delFileAC);
        fileMU->addAction(action_2);
        editMU->addSeparator();
        editMU->addAction(outputDirAC);
        editMU->addSeparator();
        editMU->addAction(lastAC);
        editMU->addAction(nextAC);
        editMU->addSeparator();
        editMU->addSeparator();
        editMU->addSeparator();
        editMU->addAction(undoAC);
        editMU->addSeparator();
        toolMU->addSeparator();
        toolMU->addAction(editLabelAC);
        toolMU->addAction(createAC);
        toolMU->addAction(copyAC);
        toolMU->addSeparator();
        toolMU->addAction(delAimAC);
        toolMU->addSeparator();
        toolMU->addAction(ellipseShapeAC);
        toolMU->addSeparator();
        toolMU->addAction(setlineAC);
        toolMU->addSeparator();
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "LabelAnnotation", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        action_3->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        openFileAC->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266 ", nullptr));
#if QT_CONFIG(shortcut)
        openFileAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        openDirAC->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\347\233\256\345\275\225   ", nullptr));
#if QT_CONFIG(shortcut)
        openDirAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        saveAC->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230 ", nullptr));
#if QT_CONFIG(shortcut)
        saveAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        saveasAC->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272 ", nullptr));
#if QT_CONFIG(shortcut)
        saveasAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        closeAC->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211   ", nullptr));
#if QT_CONFIG(shortcut)
        closeAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        outputDirAC->setText(QCoreApplication::translate("MainWindow", "\350\276\223\345\207\272\347\233\256\345\275\225", nullptr));
#if QT_CONFIG(shortcut)
        outputDirAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        lastAC->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
#if QT_CONFIG(shortcut)
        lastAC->setShortcut(QCoreApplication::translate("MainWindow", "A", nullptr));
#endif // QT_CONFIG(shortcut)
        action_20->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
        nextAC->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
#if QT_CONFIG(shortcut)
        nextAC->setShortcut(QCoreApplication::translate("MainWindow", "D", nullptr));
#endif // QT_CONFIG(shortcut)
        action_26->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\346\225\260\346\215\256", nullptr));
        undoAC->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200", nullptr));
#if QT_CONFIG(shortcut)
        undoAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        action_30->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256", nullptr));
        action_31->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\345\214\272\345\235\227", nullptr));
        createAC->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\345\214\272\345\235\227", nullptr));
#if QT_CONFIG(shortcut)
        createAC->setShortcut(QCoreApplication::translate("MainWindow", "W", nullptr));
#endif // QT_CONFIG(shortcut)
        copyAC->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266\345\214\272\345\235\227", nullptr));
#if QT_CONFIG(shortcut)
        copyAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        delAimAC->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\214\272\345\235\227", nullptr));
#if QT_CONFIG(shortcut)
        delAimAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+D", nullptr));
#endif // QT_CONFIG(shortcut)
        ellipseShapeAC->setText(QCoreApplication::translate("MainWindow", "\346\244\255\345\234\206\345\214\272\345\235\227", nullptr));
#if QT_CONFIG(shortcut)
        ellipseShapeAC->setShortcut(QCoreApplication::translate("MainWindow", "E", nullptr));
#endif // QT_CONFIG(shortcut)
        setlineAC->setText(QCoreApplication::translate("MainWindow", "\347\272\277\346\235\241\351\242\234\350\211\262", nullptr));
#if QT_CONFIG(shortcut)
        setlineAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        delFileAC->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\226\207\344\273\266", nullptr));
#if QT_CONFIG(shortcut)
        delFileAC->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        editLabelAC->setText(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221\346\240\207\347\255\276", nullptr));
#if QT_CONFIG(shortcut)
        editLabelAC->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        action_2->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\344\277\235\345\255\230", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247", nullptr));
        fileMU->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        editMU->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221", nullptr));
        toolMU->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        helpMU->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
