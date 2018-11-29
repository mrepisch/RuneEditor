#include "Mapping.h"
#include "QSettings"
#include <QVector>

const QString S_DEFAULT = " ";


Mapping::Mapping(const QString &t_name)
{
    m_name = t_name;
}


void Mapping::setMapping(QHash<QString, QString> t_mapping)
{
    m_charMapping = t_mapping;
}

void Mapping::setSingleMapping(QString t_key, QString t_value)
{
    if( m_charMapping.contains(t_key))
    {
        m_charMapping[t_key] = t_value;
    }
}

QString Mapping::translateTextToKeys(const QString &t_text)
{
    QString r_result = t_text;
    bool done = false;
    while( !done)
    {
        int counter = 0;
        for( const QString& a_value : m_charMapping.values())
        {
            if( r_result.contains(a_value) && a_value != S_DEFAULT)
            {
                r_result = r_result.replace(a_value, m_charMapping.key(a_value) );
                ++counter;
            }
        }
        if( counter == 0)
        {
            done = true;
        }
    }
    return r_result;
}

QString Mapping::translateTextToValues(const QString &t_text)
{
    QString r_result = t_text;
    bool done = false;
    while( !done )
    {
        int charCounter = 0;
        for( const QString& a_key : m_charMapping.keys() )
        {
            if( r_result.contains(a_key))
            {
                r_result.replace(a_key, m_charMapping.value(a_key));
                ++charCounter;
            }
        }
        if( charCounter == 0)
        {
            done = true;
        }
    }
    return r_result;
}

QString Mapping::getValue(QString t_key)
{
    QString r_value = S_DEFAULT;
    if( m_charMapping.contains(t_key))
    {
        r_value = m_charMapping.value(t_key);
    }
    return r_value;
}

QString Mapping::getKey(QString t_value)
{
    QString r_value = S_DEFAULT;
    if( m_charMapping.keys().contains((t_value)))
    {
        r_value = m_charMapping.key(t_value);
    }
    return r_value;
}




void Mapping::writeToIni(const QString &t_path)
{
    QSettings inifile( t_path, QSettings::IniFormat);
    inifile.beginGroup(m_name);
    for( const QString& a_key : m_charMapping.keys())
    {

        inifile.setValue(a_key, m_charMapping.value(a_key));
    }
    inifile.sync();

}

void Mapping::readFromIni(const QString &t_path)
{
    QSettings inifile( t_path, QSettings::IniFormat);
    inifile.beginGroup(m_name);
    for( const QString& key : inifile.childKeys() )
    {
        m_charMapping.insert(key,inifile.value(key).toString() );
    }
}
