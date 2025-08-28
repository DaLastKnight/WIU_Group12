#include "Demon.h"
#include "Entity.h"
#include "Position.h"

Demon::Demon(char difficultyGrade)
{
	setStats(32, 8, 5, 5);
	setType('D');
	if (difficultyGrade == 'E') // Easy
	{
		setStats(getHealth() * 0.8, getAttack() * 0.8, getDefense() * 0.8, getSpeed() * 0.8);
	}
	else if (difficultyGrade == 'N') // Normal
	{
		// Stats remain the same, so no action needed.
	}
	else if (difficultyGrade == 'H') // Hard
	{
		setStats(getHealth() * 1.2, getAttack() * 1.2, getDefense() * 1.2, getSpeed() * 1.2);
	}
	else if (difficultyGrade == 'O') // Oblivion
	{
		setStats(getHealth() * 1.4, getAttack() * 1.4, getDefense() * 1.4, getSpeed() * 1.4);
	}
}

Demon::~Demon()
{
	std::cout << "Demon has been killed" << std::endl;
}

void Demon::attacking(Entity* target)
{
	target->setStats(target->getHealth() - this->getAttack(), target->getAttack(), target->getDefense(), target->getSpeed());
}

void Demon::setEnemyGrade()
{
	grade = 'B';
}

char Demon::getEnemyGrade()
{
	return grade;
}
