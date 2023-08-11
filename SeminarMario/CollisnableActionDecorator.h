#pragma once

#include "Entities.h" 
#include "EntitiesPool.h"

class CollisnableActionDecorator : public EntityState
{
private:
    EntitiesPool* _enemiesPool;

public:
    CollisnableActionDecorator(IGraphicsComponentPtr graphics, IPhysicsComponentPtr physics, EntitiesPool* enemiesPool)
        : EntityState(graphics, physics), _enemiesPool(enemiesPool)
    {
        
    }

   
    void update() override;

};
