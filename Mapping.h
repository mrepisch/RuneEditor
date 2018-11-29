#ifndef MAPPING_H
#define MAPPING_H

#include <QHash>

class Mapping
{
public:
    Mapping( const QString& t_name);
    void setSpecials( QHash<QString,QString>t_specials);
    void setMapping(QHash<QString,QString>t_mapping);
    void setSingleMapping( QString t_key, QString t_value);
    QString translateTextToKeys( const QString& t_text);
    QString translateTextToValues( const QString& t_text);
    QString getValue( QString t_key);
    QString getKey( QString t_value);
    void writeToIni( const QString& t_path);
    void readFromIni( const QString& t_path);
private:
    QHash<QString,QString>m_charMapping;
    QString m_name;
};

#endif // MAPPING_H
