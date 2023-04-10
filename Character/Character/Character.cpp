#include <stdlib.h>
#include <iostream>

class Weapon{
	int dmg;
	float str_scale;
	float dex_scale;
public:
	Weapon();
	Weapon(std::string type_class) {
		if (type_class == "warrior"){
			dmg = 4;
			str_scale = 1.5;
			dex_scale = 1;
		}
		if (type_class == "archer"){

		}
	}
	Weapon& operator=(const Weapon& right) {
		Weapon tmp;
		tmp.dmg = right.dmg;
		tmp.str_scale = right.str_scale;
		tmp.dex_scale = right.dex_scale;
		return tmp;
	}

	int damage(int str, int dex) {
		return dmg + dex * dex_scale + str * str_scale;
	}
	
	friend Character;
	friend Warrior;
};



class Armor{
	int armor_class;
	float str_scale;
	float dex_scale;
public:
	Armor();
	Armor(std::string type_class) {
		if (type_class == "warrior") {
			armor_class = 10;
			str_scale = 1.5;
			dex_scale = 1;
		}
	}

	float block(int str, int dex) {
		
	}

	Armor& operator=(const Armor& right) {
		Armor tmp;
		tmp.armor_class = right.armor_class;
		tmp.dex_scale = right.dex_scale;
		tmp.str_scale = right.str_scale;
		return tmp;
	}
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
	Character();

public:
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
		int dmg;
		if (1 + rand() % 101 > dexterity) {
			dmg = enemy.weapon.damage(enemy.strength, enemy.dexterity);
		}
	}
};