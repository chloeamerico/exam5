#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& src) : tree_bag(src) {}

searchable_tree_bag& searchable_tree_bag::operator= (const  searchable_tree_bag& src){
    if (this != &src){
        tree_bag::operator= (src);
    }
    return *this;
}

searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::has(int n) const{
    node* curr = tree;
    
    while(curr){
        if (curr->value == n)
            return true;
        else if (curr->value > n)
            curr = curr->l;
        else
            curr = curr->r;
    }
    return false;
}