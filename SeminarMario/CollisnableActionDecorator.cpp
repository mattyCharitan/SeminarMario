#include "CollisnableActionDecorator.h"
#include "Config.h"
#include <memory>


void CollisnableActionDecorator::update()
{
  
    std::vector<EntityPtr> enemies = _enemiesPool->entitiesInUse();
    for (const auto& enemy : enemies)
    {
        if (this->_physicsPtr->checkCollision(enemy->getState()->getPhysics())) {
            Notify(Event{ EventSenders::SENDER_ENTITY_STATE, EventTypes::EVENT_PHYSICS, EventCodes::COLLISION_WITH_ENEMY });
        }
    }
        EntityState::update();
   
	
}
