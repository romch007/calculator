#pragma once

#ifndef CALCULATOR_EVALUATION_HPP
#define CALCULATOR_EVALUATION_HPP

#include <calculator/Prerequisites.hpp>
#include <string>

namespace calculator {
  CALCULATOR_API double Evaluate(const std::string &input);
}

#endif