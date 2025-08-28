#pragma once
class DifficultySelection
{
public:
	DifficultySelection();
	~DifficultySelection();

	void selectDifficulty();
	void setDifficulty();
	char getDifficultyGrade();

private:
	int difficulty;
	char difficultyGrade;
	bool selected;
};