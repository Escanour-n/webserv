#include "GlobalModel.hpp"

GlobalModel::GlobalModel( void )
{

}

GlobalModel::GlobalModel(const GlobalModel& copy)
{
	*this = copy;
}


GlobalModel::~GlobalModel( void )
{
}

GlobalModel&	GlobalModel::operator=(const GlobalModel& target)
{
	if (this != &target)
	{
		data = target.data;
	}
	return (*this);
}

void	GlobalModel::addData(const Data& _data)
{
	data.push_back(_data);
}

const Data&	GlobalModel::getData(const String& key)
{
	std::vector<Data>::iterator	iterBegin = data.begin();
	std::vector<Data>::iterator	iterEnd = data.end();
	while (iterBegin != iterEnd)
	{
		if (!iterBegin->getKey().compare(key))
			return (*iterBegin);
		iterBegin++;
	}
	throw std::exception();
	(void)key;
}

const std::vector<Data>	GlobalModel::getAllData( void ) const
{
	return (data);
}
