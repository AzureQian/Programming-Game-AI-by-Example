#ifndef ENTITY_H
#define ENTITY_H

class BaseGameEntity
{
private:

	static int m_iNextValidID;

	int	m_ID;

	void SetID(int val);

public:

	BaseGameEntity(int id)
	{
		SetID(id);
	}

	virtual ~BaseGameEntity(){}

	virtual void Update() = 0;

	int ID() const { return m_ID; }
};

#endif
