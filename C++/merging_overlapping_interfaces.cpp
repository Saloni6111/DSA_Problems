#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Data structure to represent an interval
struct Interval
{
	int begin, end;

	bool operator<(Interval const &i) {
		return (begin < i.begin);
	}
};

// Function to merge overlapping intervals
void mergeIntervals(vector<Interval> intervals)		// no-ref, no-const
{
	// sort the intervals in increasing order of their starting time
	sort(intervals.begin(), intervals.end());

	// create an empty stack
	stack<Interval> s;

	// do for each interval
	for (const Interval &curr: intervals)
	{
		// if the stack is empty or the top interval in the stack does not overlap
		// with the current interval, push it into the stack
		if (s.empty() || curr.begin > s.top().end) {
			s.push(curr);
		}

		// if the top interval of the stack overlaps with the current interval,
		// merge two intervals by updating the end of the top interval
		// to the current interval
		if (s.top().end < curr.end) {
			s.top().end = curr.end;
		}
	}

	// print all non-overlapping intervals
	while (!s.empty())
	{
		cout << '{' << s.top().begin << ", " << s.top().end << "}\n";
		s.pop();
	}
}

int main()
{
	vector<Interval> intervals = { { 1, 5 }, { 2, 3 }, { 4, 6 }, { 7, 8 },
							{ 8, 10 }, {12, 15} };

	mergeIntervals(intervals);

	return 0;
}