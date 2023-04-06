#include <stdlib.h>
#include <iostream>

class Weapon{
	int damage;
	Weapon(std::string type_class);
	Weapon& operator=(const Weapon& right);
	friend Character;
	friend Warrior;
};
class Armor{
	Armor(std::string type_class);
	Armor& operator=(const Armor& right);
	friend Character;
	friend Warrior;
};

class Character {
protected:
	std::string name;
	int HP;
	int ST;
	int strength;
	int dexterity;
	int experience;
	int level;
	Weapon weapon;
	Armor armor;

	virtual void level_up();
	void equip_weapon(const Weapon& _weapon) { weapon = _weapon; }
	void equip_armor(const Armor& _armor) { armor = _armor; }
	virtual void wounded(Character& enemy);
	virtual int attack();
	virtual int defence();

	friend Warrior;
};

class Warrior : Character {
	Warrior(std::string _name) {
		name = _name;
		HP = 150;
		ST = 50;
		strength = 1;
		dexterity = 0;
		experience = 0;
		level = 1;
		Weapon _weapon("warrior");
		weapon = _weapon;
		Armor _armor("warrior");
		armor = _armor;
	}
	void level_up() {
		if (experience == 100 * level * (1 + (level - 1) / 10)) {
			HP += 25;
			ST += 10;
			strength += 1;
			level += 1;
		}
		if (level % 10 == 0) {
			HP += 25;
			ST += 10;
			dexterity += 1;
		}
	}
	void wounded(Character& enemy) {
		if (1 + rand() % 101 > dexterity) {
			int damage;
			damage = enemy.attack();
		}
	}
};