#ifndef DOCKLISTWIDGET_H
#define DOCKLISTWIDGET_H

#include <QWidget>
#include <QListWidget>

class DockListWidget : public QWidget
{
    Q_OBJECT
public:
	explicit DockListWidget(QWidget *parent = nullptr);
    QListWidget *fileListWidget;
	QStringList fileList;
signals:
    void itemClicked(int currentIndex);
public slots :
	void updateListView(QStringList lists);
    void updateCurrentItem(int index);
    void onItemDoubleClicked();
};

#endif // DOCKLISTWIDGET_H
