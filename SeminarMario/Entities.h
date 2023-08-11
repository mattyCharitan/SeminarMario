#pragma once
#include "Observer.h"
#include <map>
#include "Graphics.h"
#include "Physics.h"

class EntityState : public Subject
{
protected:
	
	

	std::map<Event, std::shared_ptr<EntityState>> _adjecentStates;


public:
	IPhysicsComponentPtr _physicsPtr;
	IGraphicsComponentPtr _graphicsPtr;
	EntityState(IGraphicsComponentPtr graphics, IPhysicsComponentPtr physics);

	virtual void update();
	
	void addState(Event const& e, std::shared_ptr<EntityState> toWhere);
	virtual std::shared_ptr<EntityState> tryModifyState(Event const& e) const;

	IPhysicsComponentPtr const& getPhysics() const;
	virtual void reset(cv::Point const& TL, bool plus = true);

	void draw(cv::Mat & canvas);
};
typedef std::shared_ptr<EntityState> EntityStatePtr;


class Entity : public IObserver
{
protected:
	int seconds = 0;
	bool _isCollidable = true;
	IPhysicsComponentPtr _originalPhysicsPtr;
	EntityStatePtr _state;

public:
	Entity(EntityStatePtr state);
	virtual EntityStatePtr getState();
	virtual void onNotify(Event const& e) override;
	virtual void reset(cv::Point const& TL);
	void nonCollidable();
	void collidable();

	void draw(cv::Mat& canvas);
};
typedef std::shared_ptr< Entity> EntityPtr;