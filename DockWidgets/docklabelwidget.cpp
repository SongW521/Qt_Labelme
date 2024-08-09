#include "docklabelwidget.h"
#include <QTextEdit>
#include <QGridLayout>
#include <QPushButton>
#include <QHeaderView>
DockLabelWidget::DockLabelWidget(QWidget *parent)
    : QWidget{parent}
{
    tableWidget = new QTableWidget(0, 2, this); // 0 行，2 列
    tableWidget->setHorizontalHeaderLabels(QStringList() << "标签" << "信息");
    tableWidget->horizontalHeader()->setStretchLastSection(true);
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); // 设置表格为只读

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(tableWidget);
    setLayout(mainLayout);
}

void DockLabelWidget::addContent(const QString &label, const QString &information) {
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);
    tableWidget->setItem(row, 0, new QTableWidgetItem(label));
    tableWidget->setItem(row, 1, new QTableWidgetItem(information));
}
void DockLabelWidget::addContents(const QList<QPair<QString, QString>> &contents) {
    tableWidget->setRowCount(0);
    for (const auto &content : contents) {
        addContent(content.first, content.second);
    }
}
void DockLabelWidget::clearContent() {
    tableWidget->setRowCount(0);
}

void DockLabelWidget::removeRow(int row) {
    if (row >= 0 && row < tableWidget->rowCount()) {
        tableWidget->removeRow(row);
    }
}


