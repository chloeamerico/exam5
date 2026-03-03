/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_tree_bag.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:40:30 by camerico          #+#    #+#             */
/*   Updated: 2026/03/03 16:16:55 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "tree_bag.hpp"
#include "searchable_bag.hpp"

class searchable_tree_bag : public searchable_bag, public tree_bag
{
    private :

        bool search(node *node, const int value) const;

    public :

        searchable_tree_bag();
        searchable_tree_bag(const searchable_tree_bag& copy);
        searchable_tree_bag& operator=(const searchable_tree_bag& copy);
        bool has(int x) const;
        ~searchable_tree_bag();
};