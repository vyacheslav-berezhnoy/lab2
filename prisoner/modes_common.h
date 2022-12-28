#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include "factory.h"
bool is_number(const std::string &s);
int get_iterations();
void update_scores(std::vector<std::shared_ptr<Prisoner>> &prisoners);
void get_decisions(std::vector<std::shared_ptr<Prisoner>> &prisoners);
void get_prisoners(std::vector<std::shared_ptr<Prisoner>> &prisoners, int &count);