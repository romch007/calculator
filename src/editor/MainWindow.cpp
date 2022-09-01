#include <MainWindow.hpp>
#include <QFileDialog>
#include <QStyle>
#include <calculator/Context.hpp>
#include <sstream>

MainWindow::MainWindow() {
  m_layout = new QVBoxLayout;
  m_textEditor = new TextEditor;
  m_output = new QTextEdit;

  setupActions();

  m_toolbar = addToolBar("Tools");
  m_toolbar->insertActions(nullptr, {m_openAction, m_saveAction, m_runAction});

  setWindowTitle("Calculator");
  resize(1280, 720);

  m_textEditor->setFontFamily("Hack");
  m_output->setFontFamily("Hack");

  m_output->setDisabled(true);

  m_layout->addWidget(m_textEditor);
  m_layout->addWidget(m_output);

  auto layout_container = new QWidget;
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
}
void MainWindow::execute() {
  auto text = m_textEditor->toPlainText();
  std::stringstream result;
  calculator::Context context(result);
  context.Execute(text.toStdString());
  m_output->setText(QString::fromStdString(result.str()));
}

void MainWindow::openFile() {
  m_openedFile = QFileDialog::getOpenFileName(
      this, "Open Calc file", QDir::currentPath(), "Calc Files (*.calc)");
  if (m_openedFile == "") return;
  QFile file(m_openedFile);
  file.open(QIODevice::ReadOnly);
  QString data = QString::fromUtf8(file.readAll());
  m_textEditor->setText(data);
}

void MainWindow::saveFile() {
}