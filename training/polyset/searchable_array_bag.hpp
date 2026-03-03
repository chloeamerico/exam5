/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchable_array_bag.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 15:27:48 by camerico          #+#    #+#             */
/*   Updated: 2026/03/03 15:30:58 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"
#include "array_bag.hpp"

class searchable_array_bag : public array_bag, public searchable_bag
{
    public :
    
        searchable_array_bag();
        searchable_array_bag(const searchable_array_bag& copy);
        searchable_array_bag& operator=(const searchable_array_bag& copy);
        bool has(int) const;
        ~searchable_array_bag();
};
