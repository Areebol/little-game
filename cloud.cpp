//file: cloud.cpp

#include"cloud.h"

cloud::cloud()
{
	reset();
}

void cloud::reset()
{
	for (int i = 0; i < 30; ++i)
		for (int j = 0; j < 60; ++j)
			foggy[i][j] = true;
}

void cloud::set_clear(int i, int j)
{
	if (i < 0 || j < 0 || i >= 30 || j >= 60)
		return;
	foggy[i][j] = false;
}

void cloud::set_dark(int i, int j)
{
	if (i < 0 || j < 0 || i >= 30 || j >= 60)
		return;
	foggy[i][j] = true;
}

bool cloud::is_see(int i, int j)const
{
	return !foggy[i][j];
}
