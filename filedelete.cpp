#include "filedelete.h"
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>

bool FileDelete::removeDir(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst))
        {
                result = QFile::remove(info.absoluteFilePath());
        }

    return result;
}
FileDelete::FileDelete()
{
}
