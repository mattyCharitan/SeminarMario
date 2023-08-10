#include "Entity.h"
#include "../../SeminarMario - Day4/Config.h"

Entity::Entity(EntityStatePtr state)
	:_state(state)
{

}

void Entity::onNotify(Event const& e)
{
	if (e.sender == EventSenders::SENDER_TIMER
		&&
		e.type == EventTypes::EVENT_TIMER
		&&
		e.code == EventCodes::TIME_TICK)
	{
		_state->update();
	}
	if (e.sender == EventSenders::SENDER_ENTITY_STATE
		&&
		e.type == EventTypes::EVENT_PHYSICS
		&&
		e.code == EventCodes::COLLISION_WITH_ENEMY) {
		int a = 4;
	}

	auto newStateCandidate = _state->tryModifyState(e);

	if (newStateCandidate)
	{
		newStateCandidate->reset(_state->getPhysics()->getTL());
		_state = newStateCandidate;
	}
}

void Entity::reset(cv::Point const& TL)
{
	_state->reset(TL);
}

void Entity::draw(cv::Mat& canvas)
{
	_state->draw(canvas);
}

IPhysicsComponentPtr const& Entity::getPhysicsComponent()
{
	return _state->getPhysics();
}
