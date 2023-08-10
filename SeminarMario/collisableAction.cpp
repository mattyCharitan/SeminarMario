#include "collisableAction.h"

collisableAction::collisableAction(IGraphicsComponentPtr graphics, IPhysicsComponentPtr physics, EntitiesPool* entitiesPool)
{	this->_graphicsPtr = graphics;
	this->_physicsPtr = physics;
	_entitiesPool = entitiesPool;
}

//void collisableAction::update()
//{
//	_base->update();
//}
//
//void collisableAction::addState(Event const& e, std::shared_ptr<EntityState> toWhere)
//{
//	_base->addState(e,toWhere);
//}
//
//std::shared_ptr<EntityState> collisableAction::tryModifyState(Event const& e) const
//{
//	return _base->tryModifyState(e);
//}
//
//IPhysicsComponentPtr const& collisableAction::getPhysics() const
//{
//	return _base->getPhysics();
//}
//
//void collisableAction::reset(cv::Point const& TL)
//{
//	_base->reset(TL);
//}
//
//void collisableAction::draw(cv::Mat& canvas)
//{
//	_base->draw(canvas);
//}

