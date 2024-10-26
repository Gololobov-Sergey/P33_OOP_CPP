#pragma once


enum class TYPE
{
	OCEAN, SEA, RIVER, LAKE, POND, PUDDLE, NOTYPE = 99
};


class Reservoir
{
	TYPE type;

	char* name;

	int length;

	int width;

	int depth;

public:
	Reservoir();

	Reservoir(TYPE type, const char* name, int length, int width, int depth);

	Reservoir(const Reservoir& res);

	~Reservoir();

	int getVolume() const;

	int getArea() const;

	TYPE getType() const;

	char* getName() const;

	int getLength() const;

	int getWidth() const;

	int getDepth() const;

	bool equalType(const Reservoir& res) const;

	int compareArea(const Reservoir& res) const;  // 1 0 -1

	void copy(const Reservoir& res);

	void info() const;

	const char* getTypeName() const;
};

Reservoir::Reservoir() : Reservoir(TYPE::NOTYPE, "No name", 0, 0, 0) { }

Reservoir::Reservoir(TYPE type, const char* name, int length, int width, int depth)
{
	this->type = type;
	this->name = new char[strlen(name)+1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->length = length;
	this->width = width;
	this->depth = depth;
}

Reservoir::Reservoir(const Reservoir& res)
{
	this->copy(res);
}

Reservoir::~Reservoir()
{
	delete name;
}

int Reservoir::getVolume() const
{
	return length * width * depth;
}

int Reservoir::getArea() const
{
	return length * width;
}

TYPE Reservoir::getType() const
{
	return type;
}
char* Reservoir::getName() const
{
	return name;
}

int Reservoir::getLength() const
{
	return length;
}

inline int Reservoir::getWidth() const
{
	return width;
}

inline int Reservoir::getDepth() const
{
	return depth;
}

bool Reservoir::equalType(const Reservoir& res) const
{
	return this->type == res.type;
}

int Reservoir::compareArea(const Reservoir& res) const
{
	if (this->getArea() > res.getArea())
		return 1;
	else if (this->getArea() < res.getArea())
		return -1;
	return 0;
}

void Reservoir::copy(const Reservoir& res)
{
	this->type = res.type;
	if (this->name)
		delete this->name;
	this->name = new char[strlen(res.name) + 1];
	strcpy_s(this->name, strlen(res.name) + 1, res.name);
	this->length = res.length;
	this->width = res.width;
	this->depth = res.depth;
}

void Reservoir::info() const
{
	cout << "Type      : " << getTypeName() << endl;
	cout << "Name      : " << name << endl;
	cout << "[W, L, D] : " << width << ", " << length << ", " << depth << endl;
}

const char* Reservoir::getTypeName() const
{
	switch (type)
	{
	case TYPE::OCEAN:  return "Ocean";
	case TYPE::SEA:    return "Sea";
	case TYPE::RIVER:  return "River";
	case TYPE::LAKE:   return "Lake";
	case TYPE::POND:   return "Pond";
	case TYPE::PUDDLE: return "Puddle";
	case TYPE::NOTYPE: return "No type";
	}
}
