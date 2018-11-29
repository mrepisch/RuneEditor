#ifndef MAPPINGFACTORY_H
#define MAPPINGFACTORY_H

#include "Mapping.h"
#include <QString>


class MappingFactory
{
public:
    MappingFactory();
    Mapping *generateMapping( const QString& t_mappingName);
};

#endif // MAPPINGFACTORY_H
