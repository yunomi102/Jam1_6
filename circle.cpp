#include"circle.h"

bool ishit(circle c1, circle c2)
{
	double dx = c1.x - c2.x;
	double dy = c1.y - c2.y;
	double r2 = c1.r + c2.r;
	if (dx * dx + dy * dy < r2 * r2)
	{
		return true;
	}
	return false;
}