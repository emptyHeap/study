#ifndef CALC_H
#define CALC_H

#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QGridLayout>
#include <functional>
#include <map>

using CalculateLambda = std::function<std::string(std::string)>;

class CalcView : public QWidget
{
    Q_OBJECT

private:
    enum CAction {
        Delete,
        Calculate,
        Text
    };

    CalculateLambda calculate;
    std::map<QPushButton*, char> textButtons;
    QPushButton* calculateButton;
    QPushButton* deleteButton;
    QTextEdit* input;
    QTextEdit* output;

    QGridLayout* controlsGrid;
    QGridLayout* fieldsGrid;

    void addTextButton(QString text, int row, int col);
    void addTextButton(QString text, int row, int col, int rowSpan, int colSpan);
    void addTextButton(char text, int row, int col);
    void addTextButton(char text, int row, int col, int rowSpan, int colSpan);
    void addActionButton(QString text, CAction action, int row, int col);
    void addActionButton(QString text, CAction action, int row, int col, int rowSpan, int colSpan);

private slots:
    void handleTextButton();
    void handleDeleteButton();
    void handleCalculateButton();
    void handleInputChanged();

public:
    CalcView(CalculateLambda calculate);
};

#endif // CALC_H
