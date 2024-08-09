#ifndef DOCKLABELWIDGET_H
#define DOCKLABELWIDGET_H

#include <QWidget>
#include <QTableWidget>
class DockLabelWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DockLabelWidget(QWidget *parent = nullptr);
    void addContent(const QString &label, const QString &information);
    void clearContent();
    void addContents(const QList<QPair<QString, QString>> &contents);
    void removeRow(int row);
private:
    QTableWidget *tableWidget;
signals:

};

#endif // DOCKLABELWIDGET_H
