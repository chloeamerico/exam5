/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:16:58 by camerico          #+#    #+#             */
/*   Updated: 2026/03/03 18:27:33 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "searchable_tree_bag.hpp"


searchable_tree_bag::searchable_tree_bag() {}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& copy) : tree_bag(copy) {}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag& copy)
{
    if(this != &copy)
    {
        tree_bag::operator=(copy);
    }
    return (*this);
}

bool searchable_tree_bag::search(node* node, const int value) const
{
    if (node == nullptr)
        return false;
    if(node->value == value)
        return true;
    else if (value < node->value)
        return (search(node->l, value));
    else
        return (search(node->r, value));
}

bool searchable_tree_bag::has(int value) const
{
    return (search(this->tree, value));
}

searchable_tree_bag::~searchable_tree_bag() {}
