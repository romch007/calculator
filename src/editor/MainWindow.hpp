#pragma once

#ifndef CALCULATOR_EDITOR_MAIN_WINDOW_HPP
#define CALCULATOR_EDITOR_MAIN_WINDOW_HPP

#include <QAction>
#include <QKeyEvent>
#include <QMainWindow>
#include <QTextEdit>
#include <QToolBar>
#include <QVBoxLayout>
#include <TextEditor.hpp>

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow();

 public Q_SLOTS:
  void execute();
  void openFile();
  void saveFile();

 private:
  void setupActions();

  TextEditor* m_textEditor;
  QTextEdit* m_output;
  QVBoxLayout* m_layout;

  QToolBar* m_toolbar;
  QAction* m_runAction;
  QAction* m_openAction;
  QAction* m_saveAction;

  QString m_openedFile;
};

#endif