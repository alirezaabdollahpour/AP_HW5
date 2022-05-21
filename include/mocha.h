#ifndef MOCHA_H
#define MOCHA_H

#include "espresso_based.h"
#include "ingredient.h"
#include "sub_ingredients.h"
#include <iostream>
#include <string>
#include <vector>

class Mocha : public EspressoBased {
public:
    Mocha();
    Mocha(const Mocha& moch);
    ~Mocha();
    void operator=(const Mocha& moch);

    virtual std::string get_name();
    virtual double price();

    void add_side_item(Ingredient* side);
    std::vector<Ingredient*>& get_side_items();

private:
    std::vector<Ingredient*> side_items;
};
#endif // MOCHA_H