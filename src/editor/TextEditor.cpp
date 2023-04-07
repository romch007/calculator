#include <QFontDatabase>
#include <QKeySequence>
#include <TextEditor.hpp>

TextEditor::TextEditor() = default;

void TextEditor::keyPressEvent(QKeyEvent* event) {
  QTextEdit::keyPressEvent(event);
}