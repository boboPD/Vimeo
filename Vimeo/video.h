#ifndef VIDEO_H
#define VIDEO_H

#include <QString>

class Video
{
private:
    QString title;
    QString description;
    QStringList *tags;
    QString filepath;
public:

    enum UPLOAD_SITES
    {
        YOUTUBE,
        VIMEO,
        METACAFE,
        DAILYMOTION
    };

    Video(QString title, QString desc, QString filepath, QStringList* tags);
    QString getTitle();
    QString getDescription();
    QStringList* getTags();
    QString getFilepath();
};

#endif // VIDEO_H
