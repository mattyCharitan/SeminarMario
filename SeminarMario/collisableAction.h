#pragma once
#include "Entities.h"
#include "EntitiesPool.h"

class collisableAction : public EntityState {
	int a = 0;
	EntityStatePtr _base;
	

public:
	EntitiesPool* _entitiesPool;
	collisableAction(IGraphicsComponentPtr graphics, IPhysicsComponentPtr physics, EntitiesPool* entitiesPool);
	/*virtual void update();

	void addState(Event const& e, std::shared_ptr<EntityState> toWhere);
	virtual std::shared_ptr<EntityState> tryModifyState(Event const& e) const;

	IPhysicsComponentPtr const& getPhysics() const;
	virtual void reset(cv::Point const& TL);

	void draw(cv::Mat& canvas);*/
	

};
