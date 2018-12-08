
#include "Elite/MetaModel/MapModel.h"
#include "Translater/idmap.h"

MapModel::MapModel (const string& name)
    : MetaModel(name) {

}

MapModel::~MapModel () {

}


id* MapModel::find(const string& name) {
    auto p = data.find(name);
    if (p != data.end()) return p->second;
    return NULL;
}
