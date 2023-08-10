#include "../../SeminarMario - Day4/Entities.h"

class Entity : public IObserver
{
protected:
	EntityStatePtr _state;

public:
	Entity(EntityStatePtr state);

	// Inherited via IObserver
	virtual void onNotify(Event const& e) override;
	virtual void reset(cv::Point const& TL);

	void draw(cv::Mat& canvas);
	IPhysicsComponentPtr const& getPhysicsComponent();
};
typedef std::shared_ptr< Entity> EntityPtr;