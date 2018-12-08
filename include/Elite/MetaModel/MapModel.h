#ifndef MAP_MODEL_H
#define MAP_MODEL_H

#include "Elite/MetaModel/MetaModel.h"
#include <map>
#include <string>

class MapModel : public MetaModel {
public:
    MapModel (const string& name);
    virtual ~MapModel ();

    struct id* find(const string& name);

protected:
    /* data */
    std::map< std::string, struct id* > data;

};




#endif /* end of include guard: MAP_MODEL_H */
