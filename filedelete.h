#ifndef FILEDELETE_H
#define FILEDELETE_H
#include <QString>
class FileDelete
{
public:
    static bool removeDir(const QString &dirName);
    FileDelete();
};

#endif // FILEDELETE_H
