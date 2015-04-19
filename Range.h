#ifndef RANGE_H
#define RANGE_H

#include <vector>

class Range {
private:
	int _start;
	int _stop;
	int _step;
	bool _direction;

public:
	class iterator {
	private:
		int _value;
		int _step;
		bool _direction;
	public:

		void _init(int value, int step, bool dir) { _value = value; _step = step; _direction = dir; }

		int operator*()
		{
			return _value;
		}

		bool operator!=(iterator it)
		{
			bool ans = _direction ? (_value < *it) : (_value > *it);
			return ans;
		}

		void operator++()
		{
			_value += _step;
		}

		void operator--()
		{
			_value -= _step;
		}
	};

	Range(int start, int stop, int step = 1)
	{
		_start = start;
		_stop = stop;
		_direction = (start < stop) ? true : false;

		if ((!_direction && step > 0)) {
			_step = -step;
		} else {
			_step = step;
		}
	}

	Range(int stop) : Range(0, stop, 1) {}

	iterator begin()
	{
		iterator ans;
		ans._init(_start, _step, _direction);
		return ans;
	}

	iterator end()
	{
		iterator ans;
		ans._init(_stop, 0, true);
		return ans;
	}

	std::vector<int> iota()
	{
		std::vector<int> ans;
		for (auto it = begin(); it != end(); ++it) {
			ans.push_back(*it);
		}
		return ans;
	}

};

#endif /*RANGE_H*/
