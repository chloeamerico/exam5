/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 19:03:38 by camerico          #+#    #+#             */
/*   Updated: 2026/03/03 19:09:18 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "searchable_bag.hpp"

class set
{
    private:
        searchable_bag& bag;
    
    public :

        set() = delete;
        set(searchable_bag& s_bag);     //2eme constructeur
        set(const set& copy) = delete;
        set& operator=(const set& copy) = delete;
        ~set();

        bool has(int) const;
        void insert (int);
        void insert (int *, int);
        void print() const;
        void clear();

        const searchable_bag& get_bag();
};