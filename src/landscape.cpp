#include "../include/landscape.hpp"

Landscape* Landscape::instance = NULL;

Landscape::Landscape(int rows, int columns) {
	
	assert(rows>0 && columns>0 && rows<= 2000 && columns<=2000);

	this->rows = rows;
	this->columns = columns;

	for (int i = 0; i < this->rows; ++i)
	{
		this->grids.push_back(std::vector<Grid>());

		for (int j = 0; j < this->columns; ++j)
		{
			this->grids[i].push_back(new Grid(false));
			//water on the edges
		}
	}
}

void Landscape::Init(int rows, int columns) {
	Landscape::instance = new Landscape(rows, columns);
}

void Landscape::Print() {
	for(LandscapeGridVector::iterator it = Landscape::instance->grids.begin(); it != Landscape::instance->grids.end(); ++it) {
		for(LandscapeGridLine::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {
			(*it2).print();
		}
		cout << endl;
	}
}
