/* generated by rust_qt_binding_generator */
#ifndef BINDINGS_H
#define BINDINGS_H

#include <QtCore/QObject>
#include <QtCore/QAbstractItemModel>

class RomList;
class Simple;

class RomList : public QAbstractItemModel
{
    Q_OBJECT
    friend class Simple;
public:
    class Private;
private:
    Private * m_d;
    bool m_ownsPrivate;
    explicit RomList(bool owned, QObject *parent);
public:
    explicit RomList(QObject *parent = nullptr);
    ~RomList();

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    bool hasChildren(const QModelIndex &parent = QModelIndex()) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    bool canFetchMore(const QModelIndex &parent) const override;
    void fetchMore(const QModelIndex &parent) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder) override;
    int role(const char* name) const;
    QHash<int, QByteArray> roleNames() const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;
    Q_INVOKABLE bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    Q_INVOKABLE bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    Q_INVOKABLE QString name(int row) const;

Q_SIGNALS:
    // new data is ready to be made available to the model with fetchMore()
    void newDataReady(const QModelIndex &parent) const;
private:
    QHash<QPair<int,Qt::ItemDataRole>, QVariant> m_headerData;
    void initHeaderData();
    void updatePersistentIndexes();
Q_SIGNALS:
};

class Simple : public QObject
{
    Q_OBJECT
public:
    class Private;
private:
    RomList* const m_romList;
    Private * m_d;
    bool m_ownsPrivate;
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged FINAL)
    Q_PROPERTY(RomList* romList READ romList NOTIFY romListChanged FINAL)
    explicit Simple(bool owned, QObject *parent);
public:
    explicit Simple(QObject *parent = nullptr);
    ~Simple();
    QString message() const;
    void setMessage(const QString& v);
    const RomList* romList() const;
    RomList* romList();
Q_SIGNALS:
    void messageChanged();
    void romListChanged();
};
#endif // BINDINGS_H
