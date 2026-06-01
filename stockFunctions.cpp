#include "stockFunctions.h"
#include <cmath>
#include <string>
#include <vector>

using namespace std;

double percentChange(const vector<double>& values, int startDay, int endDay)
{
  double startValue = values[startDay];
  double endValue = values[endDay];
  double change = endValue - startValue;

  return change / startValue * 100;
}