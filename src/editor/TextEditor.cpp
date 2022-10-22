#include <QFontDatabase>
#include <TextEditor.hpp>

TextEditor::TextEditor() {
  const QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
  setFont(fixedFont);
}