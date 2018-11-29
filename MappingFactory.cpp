#include "MappingFactory.h"
#include <QString>
MappingFactory::MappingFactory()
{

}

Mapping* MappingFactory::generateMapping(const QString &t_mappingName)
{
    Mapping* r_mapping = new Mapping(t_mappingName);
    r_mapping->readFromIni(QStringLiteral("config.ini"));
    return r_mapping;
//Mapping* r_mapping = nullptr;
//if (t_mappingName == "elder")
//{
//    r_mapping = new Mapping("elder");
//    //QHash<QString, QString>mapping;
//    //mapping.insert(QString("q"), QString("ᚦ"));
//    //mapping.insert(QString("w"), QString("ᚹ"));
//    //mapping.insert(QString("e"), QString("ᛖ"));
//    //mapping.insert(QString("r"), QString("ᚱ"));
//    //mapping.insert(QString("t"), QString("ᛏ"));
//    //mapping.insert(QString("z"), QString("ᛉ"));
//    //mapping.insert(QString("u"), QString("ᚢ"));
//    //mapping.insert(QString("i"), QString("ᛁ"));
//    //mapping.insert(QString("o"), QString("ᛟ"));
//    //mapping.insert(QString("p"), QString("ᛈ"));
//    //mapping.insert(QString("a"), QString("ᚨ"));
//    //mapping.insert(QString("s"), QString("ᛊ"));
//    //mapping.insert(QString("d"), QString("ᛞ"));
//    //mapping.insert(QString("f"), QString("ᚠ"));
//    //mapping.insert(QString("g"), QString("ᚷ"));
//    //mapping.insert(QString("h"), QString("ᚺ"));
//    //mapping.insert(QString("j"), QString("ᛃ"));
//    //mapping.insert(QString("k"), QString("ᚲ"));
//    //mapping.insert(QString("l"), QString("ᛚ"));
//    //mapping.insert(QString("y"), QString(" "));
//    //mapping.insert(QString("x"), QString(" "));
//    //mapping.insert(QString("c"), QString("ᚲ"));
//    //mapping.insert(QString("v"), QString(" "));
//    //mapping.insert(QString("b"), QString("ᛒ"));
//    //mapping.insert(QString("n"), QString("ᚾ"));
//    //mapping.insert(QString("m"), QString("ᛗ"));
//    //mapping.insert(QString("þ"), QString("ᚦ"));
//
//
//    r_mapping->readFromIni(QStringLiteral("config.ini"));
//
//}
//else if( t_mappingName == "younger")
//{
//     r_mapping = new Mapping("younger");
//    QHash<QString, QString>mapping;
//    mapping.insert(QString("q"), QString(""));
//    mapping.insert(QString("w"), QString("ᚢ"));
//    mapping.insert(QString("e"), QString("ᛁ"));
//    mapping.insert(QString("r"), QString("ᚱ"));
//    mapping.insert(QString("R"), QString("ᛦ"));
//    mapping.insert(QString("t"), QString("ᛏ"));
//    mapping.insert(QString("z"), QString(""));
//    mapping.insert(QString("u"), QString("ᚢ"));
//    mapping.insert(QString("i"), QString("ᛁ"));
//    mapping.insert(QString("o"), QString("ᚬ"));
//    mapping.insert(QString("ø"), QString("ᚢ"));
//    mapping.insert(QString("p"), QString("ᛒ"));
//    mapping.insert(QString("a"), QString("ᛅ"));
//    mapping.insert(QString("s"), QString("ᛋ"));
//    mapping.insert(QString("d"), QString("ᛏ"));
//    mapping.insert(QString("f"), QString("ᚠ"));
//    mapping.insert(QString("g"), QString("ᚴ"));
//    mapping.insert(QString("h"), QString("ᚼ"));
//    mapping.insert(QString("j"), QString(""));
//    mapping.insert(QString("k"), QString("ᚴ"));
//    mapping.insert(QString("l"), QString("ᛚ"));
//    mapping.insert(QString("y"), QString("ᚢ"));
//    mapping.insert(QString("x"), QString(" "));
//    mapping.insert(QString("c"), QString(""));
//    mapping.insert(QString("v"), QString("ᚠ"));
//    mapping.insert(QString("b"), QString("ᛒ"));
//    mapping.insert(QString("n"), QString("ᚾ"));
//    mapping.insert(QString("m"), QString("ᛘ"));
//    mapping.insert(QString("þ"), QString("ᚦ"));
//    mapping.insert(QString("ð"), QString("ᚦ"));
//    r_mapping->setMapping(mapping);
//}
//return r_mapping;
}
