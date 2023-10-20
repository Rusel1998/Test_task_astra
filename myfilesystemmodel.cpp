#include "myfilesystemmodel.h"

MyFileSystemModel::MyFileSystemModel(QObject* parent):
    QFileSystemModel(parent)
{
}

QVariant MyFileSystemModel::data(const QModelIndex &index,
                                 int role) const {
    if(role == Qt::TextColorRole){
        if(m_filteredSet.contains(filePath(index)))
            return QColor(Qt::red);
    }
    return QFileSystemModel::data(index, role);
}

void MyFileSystemModel::identifyPathsOfName(QString nameFilter){
    if(m_fileToNameHash.isEmpty())
        populateFileToNameHash();
    populateFilteredSet(nameFilter);
}

void MyFileSystemModel::populateFileToNameHash(){
    QDirIterator it(rootDirectory(), QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        const QFileInfo& fInfo = it.fileInfo();
        if(fInfo.isFile() || fInfo.isDir())
            m_fileToNameHash[it.filePath()] = fInfo.fileName();
    }
}

void MyFileSystemModel::populateFilteredSet(QString nameFilter){
    m_filteredSet.clear();

    QHashIterator<QString, QString> i(m_fileToNameHash);
    while (i.hasNext()) {
        i.next();
        if(i.value().contains(nameFilter))
            addAllParentalPaths(i.key());
    }
    emit dataChanged(QModelIndex(),QModelIndex());
}

void MyFileSystemModel::addAllParentalPaths(const QString &filePath){
    QString pathToAdd = filePath;
    while(pathToAdd != rootPath()){
        if(m_filteredSet.contains(pathToAdd))
            break;
        else {
            m_filteredSet.insert(pathToAdd);
            int lastInd = pathToAdd.lastIndexOf("/");
            pathToAdd.truncate(lastInd);
        }
    }
}
