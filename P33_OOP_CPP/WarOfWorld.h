#pragma once
#include<iostream>

#include"List.h"

using namespace std;

class Warrior;

class Skill
{
public:
	virtual void execute(Warrior* w1, Warrior* w2) = 0;
};

class Heal : public Skill
{
public:
	virtual void execute(Warrior* w1, Warrior* w2);
};


class Warrior
{
	int hp;
	int damage;
	List<Skill*> skills;

public:
	Warrior(int hp, int damage, Skill* sk = nullptr) : hp(hp), damage(damage)
	{
		if(sk)
			skills.push_back(sk);
	}

	void setHP(int hp)
	{
		this->hp = hp;
	}

	void setDamage(int damage)
	{
		this->damage = damage;
	}

	int getHP() 
	{
		return hp;
	}

	int getDamage()
	{
		return damage;
	}

	Skill* getSkill()
	{
		if(skills.length() > 0)
			return skills[0];
		return nullptr;
	}

	virtual void skill(Warrior* w) = 0;

	friend ostream& operator<<(ostream& out, const Warrior* w);

	virtual ostream& print(ostream& out) const
	{
		out << "HP : " << hp << ", Damage : " << damage << endl;
		return out;
	}
};


void Heal::execute(Warrior* w1, Warrior* w2)
{
	w1->setHP(1000);
	cout << "HP = 1000" << endl;
}

ostream& operator<<(ostream& out, const Warrior* w)
{
	return w->print(out);
}

class Light : public Warrior
{
public:
	Light(int hp, int damage, Skill* sk = nullptr) : Warrior(hp, damage, sk) {}
};


class Dark : public Warrior
{
public:
	Dark(int hp, int damage) : Warrior(hp, damage) {}
};

class Archer : public Light
{

public:
	Archer(int hp, int damage, Skill* sk = nullptr) : Light(hp, damage, sk)
	{

	}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Archer    -> ";
		return Warrior::print(out);
	}
};

class Swordsman : public Light
{
public:
	Swordsman(int hp, int damage) : Light(hp, damage)
	{

	}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Swordsman -> ";
		return Warrior::print(out);
	}
};

class Rider : public Light
{
public:
	Rider(int hp, int damage) : Light(hp, damage)
	{

	}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Rider     -> ";
		return Warrior::print(out);
	}
};


class Ork : public Dark
{
public:
	Ork(int hp, int damage) : Dark(hp, damage)
	{

	}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Ork       -> ";
		return Warrior::print(out);
	}
};

class Demon : public Dark
{
public:
	Demon(int hp, int damage) : Dark(hp, damage)
	{

	}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Demon     -> ";
		return Warrior::print(out);
	}
};


class Skeleton : public Dark
{

public:
	Skeleton(int hp, int damage) : Dark(hp, damage)
	{

	}

	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const override
	{
		out << "Skeleton  -> ";
		return Warrior::print(out);
	}
};

class WarOfWorld
{
	List<Light*> lightes;
	List<Dark*> darkes;

public:
	WarOfWorld(int size)
	{
		Light* l = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int c = rand() % 3;
			switch (c)
			{
			case 0: l = new Archer(rand() % 31 + 50, rand() % 21 + 10, new Heal()); break;
			case 1: l = new Swordsman(rand() % 31 + 50, rand() % 21 + 10); break;
			case 2: l = new Rider(rand() % 31 + 50, rand() % 21 + 10); break;
			}
			lightes.push_back(l);
		}

		Dark* d = nullptr;
		for (size_t i = 0; i < size; i++)
		{
			int c = rand() % 3;
			switch (c)
			{
			case 0: d = new Ork(rand() % 31 + 50, rand() % 21 + 10); break;
			case 1: d = new Demon(rand() % 31 + 50, rand() % 21 + 10); break;
			case 2: d = new Skeleton(rand() % 31 + 50, rand() % 21 + 10); break;
			}
			darkes.push_back(d);
		}
	}

	void print()
	{
		cout << "        ----- LIGHT -----" << endl;
		lightes.print();

		gotoxy(40, 0);
		cout << "        ----- DARK  -----" << endl;
		darkes.print(40, 1);
	}


	Warrior* fight(Warrior* w1, Warrior* w2)
	{
		w2->setHP(w2->getHP() - w1->getDamage());
		//w1->skill(w2);

		Skill* sk = w1->getSkill();
		if(sk)
		 sk->execute(w1, w2);

		w1->setHP(w1->getHP() - w2->getDamage());
		w2->skill(w1);
		if (w1->getHP() <= 0)
			return w1;
		else if (w2->getHP() <= 0)
			return w2;
		return nullptr;
	}

	void game()
	{
		while (lightes.length() > 0 && darkes.length() > 0)
		{
			system("cls");
			print();
			int l = rand() % lightes.length();
			int d = rand() % darkes.length();
			Warrior* lose = fight(lightes[l], darkes[d]);
			if (lose == lightes[l])
				lightes.remove(l);
			else if (lose == darkes[d])
				darkes.remove(d);
			gotoxy(0, 15);
			system("pause");
		}
		

	}
};

