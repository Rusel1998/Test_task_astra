#ifndef MYFILESYSTEMMODEL_H
#define MYFILESYSTEMMODEL_H

#include <QFileSystemModel>
#include <QSet>
#include <QHash>

class MyFileSystemModel : public QFileSystemModel
{
    Q_OBJECT
public:
    MyFileSystemModel(QObject* parent = 0);
    QVariant data(const QModelIndex& index,
               int role = Qt::DisplayRole) const;

public slots:
    void identifyPathsOfName(QString nameFilter);

private:
    QHash<QString, QString> m_fileToNameHash;
    QSet<QString> m_filteredSet;

    void populateFileToNameHash();
    void populateFilteredSet(QString nameFilter);
    void addAllParentalPaths(const QString& filePath);
};

#endif // MYFILESYSTEMMODEL_H
