#include "Giantgoblin.h"
#include "Entity.h"
#include "Position.h"

Giantgoblin::Giantgoblin(char difficultyGrade)
{
	setStats(27, 10, 3, 10);
	setType('G');
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

Giantgoblin::~Giantgoblin()
{
	std::cout << "Giantgoblin has been killed" << std::endl;
}

void Giantgoblin::attacking(Entity* target)
{
	target->setStats(target->getHealth() - this->getAttack(), target->getAttack(), target->getDefense(), target->getSpeed());
}

void Giantgoblin::setEnemyGrade()
{
	grade = 'E';
}

char Giantgoblin::getEnemyGrade()
{
	return grade;
}
