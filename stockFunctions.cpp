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

double highestValue(const vector<double>& values, int startDay, int endDay)
{
  double highest = values[startDay];

  for (int i = startDay; i <= endDay; i++) {
    if (values[i] > highest) {
      highest = values[i];
    }
  }
  return highest;
}

double average(const std::vector<double>& values, int startDay, int endDay)
{
  double total = 0;
  int count = 0;

  for
}
