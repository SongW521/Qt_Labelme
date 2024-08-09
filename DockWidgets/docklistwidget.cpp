#include "docklistwidget.h"
#include <QGridLayout>
DockListWidget::DockListWidget(QWidget *parent)
    : QWidget{parent}
{
    fileListWidget = new QListWidget(this);
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(fileListWidget);

    //绑定槽函数
    connect(fileListWidget, &QListWidget::itemDoubleClicked, this, &DockListWidget::onItemDoubleClicked);
}
void DockListWidget::updateListView(QStringList lists)
{
    fileListWidget->clear();
    fileListWidget->addItems(lists);
}

void DockListWidget::updateCurrentItem(int index)
{
    fileListWidget->setCurrentRow(index);
    QListWidgetItem* item = fileListWidget->currentItem();
    fileListWidget->scrollToItem(item, QAbstractItemView::EnsureVisible);
}

void DockListWidget::onItemDoubleClicked()
{
    int index = fileListWidget->currentRow();
    emit itemClicked(index);
}
