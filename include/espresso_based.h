#ifndef ESPRESSO_BASED_H
#define ESPRESSO_BASED_H

#include "ftxui/dom/node.hpp"
#include "ftxui/screen/color.hpp"
#include "ingredient.h"
#include "sub_ingredients.h"
#include <chrono>
#include <cmath>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

class EspressoBased {
public:
    virtual std::string get_name() = 0;
    virtual double price() = 0;

    void brew();
    std::vector<Ingredient*>& get_ingredients();

    virtual ~EspressoBased();

protected:
    EspressoBased();
    EspressoBased(const EspressoBased& esp);
    void operator=(const EspressoBased& esp);

    std::vector<Ingredient*> ingredients;
    std::string name;
};

#endif // ESPRESSO_BASED_H