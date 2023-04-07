#pragma once

#ifndef CALCULATOR_EDITOR_TEXT_EDITOR_HPP
#define CALCULATOR_EDITOR_TEXT_EDITOR_HPP

#include <QKeyEvent>
#include <QTextEdit>

class TextEditor : public QTextEdit {
  Q_OBJECT

 public:
  TextEditor();

 private:
  void keyPressEvent(QKeyEvent* event) override;
};

#endif