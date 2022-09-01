#pragma once

#ifndef CALCULATOR_CONTEXT_HPP
#define CALCULATOR_CONTEXT_HPP

#include <calculator/Enums.hpp>
#include <calculator/Prerequisites.hpp>
#include <string>
#include <unordered_map>

namespace calculator {
  CALCULATOR_API void Evaluate(const std::string& input,
                               std::ostream& outputStream);

  /**
   * An execution context containing current variables
   */
  class CALCULATOR_API Context {
   public:
    explicit Context(std::ostream& outputStream);
    ~Context() = default;

    Context(const Context&) = delete;
    Context(Context&&) noexcept = delete;

    Context& operator=(const Context&) = delete;
    Context& operator=(Context&&) noexcept = delete;

    /**
     * Execute a given script
     * @param input The script
     */
    void Execute(const std::string& input);

    /**
     * Register a new variable
     * @param variableName The variable name
     * @param value The variable value
     * @param assignmentType The assignment type
     *
     * @sa Assignment
     */
    void SetVariable(std::string variableName, double value,
                     Ast::AssignmentType assignmentType);

    /**
     * Get the value of an existing variable
     * @param variableName The variable name
     * @return The variable value
     */
    double GetVariable(const std::string& variableName) const;

    std::ostream& GetOutputStream() const;

   private:
    std::unordered_map<std::string, double> m_variables;
    std::ostream& m_outputStream;
  };
}  // namespace calculator

#endif