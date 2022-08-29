#pragma once

#ifndef CALCULATOR_CONTEXT_HPP
#define CALCULATOR_CONTEXT_HPP

#include <calculator/Prerequisites.hpp>
#include <string>
#include <unordered_map>

namespace calculator {
  CALCULATOR_API double Evaluate(const std::string &input);

  class CALCULATOR_API Context {
   public:
    Context() = default;
    ~Context() = default;

    Context(const Context &) = delete;
    Context(Context &&) noexcept = default;

    Context &operator=(const Context &) = delete;
    Context &operator=(Context &&) noexcept = default;

    double Evaluate(const std::string &input);

    void AddVariable(std::string_view variableName, double value);
    double GetVariable(std::string_view variableName);

   private:
    std::unordered_map<std::string_view, double> m_variables;
  };
}  // namespace calculator

#endif