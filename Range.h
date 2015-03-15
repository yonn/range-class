#ifndef __RANGE_H__
#define __RANGE_H__

class Range {
private:

	int _start;
	int _stop;
	int _step;

public:

	class iterator {
	private:
		int _value;
		int _step;
	public:

		void _init(int value, int step) { _value = value; _step = step; }

		int operator*()
		{
			return _value;
		}

		bool operator!=(iterator it)
		{
			return _value < *it;
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
		_step = step;
	}

	Range(int stop) : Range(0, stop, 1) {}

	iterator begin()
	{
		iterator ans;
		ans._init(_start, _step);
		return ans;
	}

	iterator end()
	{
		iterator ans;
		ans._init(_stop, 0);
		return ans;
	}
};

#endif