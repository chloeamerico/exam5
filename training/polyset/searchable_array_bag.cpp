/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:31:43 by camerico          #+#    #+#             */
/*   Updated: 2026/03/03 15:39:50 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag() {}

searchable_array_bag::searchable_array_bag(const searchable_array_bag& copy) : array_bag(copy) {}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag& copy)
{
    if (this != &copy)
    {
        array_bag::operator=(copy);
    }
    return *this;
}

bool searchable_array_bag::has(int value) const
{
    for (int i = 0; i < this->size(); i++)
    {
        if (this->data[i] == value)
        {
            return true;
        }
    }
    return false;
}

searchable_array_bag::~searchable_array_bag() {}