#include "Animation.h"
#include <opencv2/opencv.hpp>
#include "Timer.h"
#include "HeroEntity.h"

#include "SlimeEntity.h"
#include "LifeEntity.h"
#include "ScoreEntity.h"
using namespace cv;

int main()
{

	Mat background = imread(R"(../Animations/background.png)", IMREAD_UNCHANGED);

	EntitiesPool enemiesPool;
	enemiesPool.insert(createSlime(R"(../Animations/SlimeOrange)"));
	auto life = Createlives(R"(../Animations/hearts)");
	auto score = CreateScore();
	auto slime = enemiesPool.getNext();
	
	slime->reset(Point(background.size().width * 2 / 3, background.size().height * 3.80 / 5));
	
	EntityPtr hero = createHero(R"(../Animations/Hero)", &enemiesPool, life);
	hero->reset(Point(0, background.size().height * 1.89 / 3));
	

	Timer timer(100);
	timer.Register(slime);
	timer.Register(hero);

	bool isToExit = false;
	while (false == isToExit)
	{
		Mat canvas = background.clone();

		isToExit = timer.tick();
		slime->draw(canvas);
		life->draw(canvas);
		score->draw(canvas);
		hero->draw(canvas);
		//life->reset(Point(0, 0));


		imshow("test", canvas);
	}
	
	return 0;
}

