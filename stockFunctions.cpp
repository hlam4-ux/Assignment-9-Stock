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

  for (int i = startDay; i <= endDay; i++) {
    total += values[i];
    count++;
  }

  return total / count;
}

double standardDev(const std::vector<double>& values, int startDay, int endDay)
{
  double avg = average(values, startDay, endDay);

  double total = 0;
  int count = 0;

  for (int i = startDay; i <= endDay; i++) {
    double diff = values[i] - avg;
    total += diff * diff;
    count++;
  }

  return sqrt(total / count);
}

vector<double> parseData(const std::string& csv)
{
  vector<double> result;

  int start = 0;
  int comma = csv.find(",");

  while (comma != string::npos) {
    string piece = csv.substr(start, comma - start);
    result.push_back(stod(piece));
    start = comma + 1;
    comma = csv.find(",", start);
  }

  result.push_back(stod(csv.substr(start)));
  return result;
}

vector<double> getChangeVector(const vector<double>& values)
{
  vector<double> changes;

  if (values.size() == 0) {
    return changes;
  }

  changes.push_back(0);

  for (int i = 1; i < values.size(); i++) {
    changes.push_back(values[i] - values[i - 1]);
  }

  return changes;
}