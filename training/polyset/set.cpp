/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 18:37:15 by camerico          #+#    #+#             */
/*   Updated: 2026/03/03 19:42:17 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.hpp"
#include "searchable_array_bag.hpp"


set::set(searchable_bag& s_bag) : bag(s_bag)     //2eme constructeur
{
    
}

set::~set() {}


bool set::has(int value) const
{
    return (bag.has(value));
}


void set::insert (int value)
{
    if (!(this->has(value)))
        bag.insert(value);
}

void set::insert (int *data, int size)
{
    for (int i = 0; i < size; i++)
    {
        this->insert(data[i]);
    }
}

void set::print() const
{
    bag.print();
}
void set::clear()
{
    bag.clear();
}
const searchable_bag& set::get_bag()
{
	return(this->bag);
}