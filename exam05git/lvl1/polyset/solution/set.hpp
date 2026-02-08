#pragma once

#include "searchable_bag.hpp"

class set
{
  private:
	searchable_bag &_bag;

  public:
	set() = delete;
	set(searchable_bag &bag);
	set(const set &src);
	set &operator=(const set &src);
	~set();

	void insert(int value);
	void insert(int *arr, int size);
	void print() const;
	void clear();

	bool has(int value) const;

	const searchable_bag &get_bag() const;
};