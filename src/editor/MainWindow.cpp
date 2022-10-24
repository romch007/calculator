#include <MainWindow.hpp>
#include <QFileDialog>
#include <QStyle>
#include <QTextStream>
#include <QApplication>
#include <calculator/Context.hpp>
#include <sstream>

MainWindow::MainWindow() {
  m_layout = new QVBoxLayout;
  m_textEditor = new TextEditor;
  m_output = new QTextEdit;

  setupActions();

  m_toolbar = addToolBar("Tools");
  m_toolbar->insertActions(nullptr, {m_openAction, m_saveAction, m_runAction, m_quitAction});

  setWindowTitle("Calculator");
  resize(1280, 720);

  m_textEditor->setFontFamily("Hack");
  m_output->setFontFamily("Hack");

  m_output->setDisabled(true);

  m_layout->addWidget(m_textEditor);
  m_layout->addWidget(m_output);

  auto* layout_container = new QWidget;
  layout_container->setLayout(m_layout);

  setCentralWidget(layout_container);
}
void MainWindow::setupActions() {
  m_runAction = new QAction("Run", this);
  connect(m_runAction, &QAction::triggered, this, &MainWindow::execute);

  m_openAction = new QAction("Open", this);
  connect(m_openAction, &QAction::triggered, this, &MainWindow::openFile);

  m_saveAction = new QAction("Save", this);
  connect(m_saveAction, &QAction::triggered, this, &MainWindow::saveFile);

  m_quitAction = new QAction("Quit", this);
  connect(m_quitAction, &QAction::triggered, this, &MainWindow::quit);
}

void MainWindow::execute() {
  auto qtText = m_textEditor->toPlainText();
  std::string text = qtText.toUtf8().constData();
  std::stringstream result;

  calculator::Context context(result);
  context.Execute(text);

  auto textResult = result.str();
  qtText = QString::fromUtf8(textResult.c_str());

  m_output->setText(qtText);
}

void MainWindow::openFile() {
  m_openedFile = QFileDialog::getOpenFileName(
      this, "Open Calc file", QDir::currentPath(), "Calc Files (*.calc)");
  if (m_openedFile.isEmpty()) return;
  QFile file(m_openedFile);
  file.open(QIODevice::ReadOnly);
  QString data = QString::fromUtf8(file.readAll());
  m_textEditor->setText(data);
}

void MainWindow::saveFile() {
  auto newFilePath = QFileDialog::getSaveFileName(
      this, "Save Calc file", QDir::currentPath(), "Calc Files (*.calc)");
  if (newFilePath.isEmpty()) return;

  QFile file(newFilePath);
  file.open(QIODevice::ReadWrite);

  auto content = m_textEditor->toPlainText();
  QTextStream stream(&file);
  stream << content;
}

void MainWindow::quit() {
  QApplication::quit();
}
