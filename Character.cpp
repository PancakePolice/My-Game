#include "Character.h"

int Character::getDefense() const {
	if (isBlocking)
		return 1;
	if (isParrying)
		return 2;
	if (isWarding)
		return 3;
}

void Character::Attack(Character& opponent) {
	EndDefense();
	if (opponent.isBlocking)
		opponent.setHealth(opponent.getHealth() - (attack / 2));
	else
		opponent.setHealth(opponent.getHealth() - attack);
}

void Character::Strike(Character& opponent) {
	EndDefense();
	if (opponent.isParrying)
		setHealth(getHealth() - attack * 2);
	else
		opponent.setHealth(opponent.getHealth() - (attack * 2));
}

void Character::Magic(Character& opponent) {
	EndDefense();
	if (opponent.isWarding)
		opponent.setHealth(opponent.getHealth() - (magic / 2));
	else
		opponent.setHealth(opponent.getHealth() - magic);
}