#ifndef ANNOTATIONDATA_H
#define ANNOTATIONDATA_H

#include <QObject>

class AnnotationData : public QObject
{
    Q_OBJECT
public:
    explicit AnnotationData(QObject *parent = nullptr);

signals:
};

#endif // ANNOTATIONDATA_H
