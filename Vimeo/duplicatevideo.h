#ifndef DUPLICATEVIDEO_H
#define DUPLICATEVIDEO_H

#include <QObject>
#include <QString>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QStringList>
#include <QMutex>

class DuplicateVideo : public QObject
{
    Q_OBJECT
private:
    QMutex* mutex;
    QString originalFilename;
    QStringList* copyFilenamesList;

    QFuture<void> *future;
    QFutureWatcher<void> *watcher;

    int numberOfRunningJobs;

    void createCopy(QString copyFilename);

    static const QString copyFilesDumpPath;

public:
    DuplicateVideo(QString orgnlFilename, QStringList* cpyFilenamesList);
    void createCopies();

signals:
    void completedAllJobs();

private slots:
    void completedSingleJob();
};

#endif // DUPLICATEVIDEO_H
