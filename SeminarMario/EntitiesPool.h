#pragma once

#include <vector>
#include "Entities.h"


// Object Pool Design Pattern
class EntitiesPool
{
private:
	std::vector<EntityPtr> _pool;
	std::vector<bool> _isInUse;


public:
	EntitiesPool();

	void insert(EntityPtr whom);

	// throws exception if all entities are in use.
	EntityPtr getNext();
	std::vector<EntityPtr> entitiesInUse();
	void returnEntity(EntityPtr toFree);

};

