#ifndef __RANGE_H__
#define __RANGE_H__

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
		_step = _direction ? step : -step;
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
};

#endif