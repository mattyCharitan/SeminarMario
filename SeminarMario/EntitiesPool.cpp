#include "EntitiesPool.h"

EntitiesPool::EntitiesPool() {}

void EntitiesPool::insert(EntityPtr whom) {
    _pool.push_back(whom);
    _isInUse.push_back(false);
}

EntityPtr EntitiesPool::getNext() {
    for (size_t i = 0; i < _isInUse.size(); ++i) {
        if (!_isInUse[i]) {
            _isInUse[i] = true;
            return _pool[i];
        }
    }
    throw std::runtime_error("All entities are in use.");
}

std::vector<EntityPtr> EntitiesPool::entitiesInUse()
{
    std::vector<EntityPtr> inUseEntities;

    for (size_t i = 0; i < _isInUse.size(); ++i) {
        if (_isInUse[i]) {
            inUseEntities.push_back(_pool[i]);
        }
    }

    return inUseEntities;
}


void EntitiesPool::returnEntity(EntityPtr toFree) {
    for (size_t i = 0; i < _pool.size(); ++i) {
        if (_pool[i] == toFree) {
            if (_isInUse[i]) {
                _isInUse[i] = false;
                return;
            }
            else {
                throw std::invalid_argument("Entity is not in use.");
            }
        }
    }
    throw std::invalid_argument("Entity not found in the pool.");
}
