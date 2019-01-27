#include <calc.h>
#include <QApplication>
#include <QKeyEvent>

void CalcView::addTextButton(QString text, int row,int col, int rowSpan, int colSpan) {
    this->addActionButton(text, CAction::Text, row, col, rowSpan, colSpan);
}

void CalcView::addTextButton(QString text, int row, int col) {
    addTextButton(text, row, col, 1, 1);
}

void CalcView::addTextButton(char text, int row,int col, int rowSpan, int colSpan) {
    this->addActionButton(QString(QChar(text)), CAction::Text, row, col, rowSpan, colSpan);
}

void CalcView::addTextButton(char text, int row, int col) {
    addTextButton(QString(QChar(text)), row, col, 1, 1);
}

void CalcView::addActionButton(QString text, CAction action, int row, int col, int rowSpan, int colSpan) {
    QPushButton *button = new QPushButton();
    button->setText(text);
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    controlsGrid->addWidget(button, row, col, rowSpan, colSpan);

    if (action == CAction::Text) {
        connect(button, SIGNAL (pressed()), this, SLOT(handleTextButton()));
    } else if (action == CAction::Delete) {
        connect(button, SIGNAL (pressed()), this, SLOT(handleDeleteButton()));
    } else if (action == CAction::Calculate) {
        connect(button, SIGNAL (pressed()), this, SLOT(handleCalculateButton()));
    }
}

void CalcView::addActionButton(QString text, CAction action, int row, int col) {
    this->addActionButton(text, action, row, col, 1, 1);
}

CalcView::CalcView(CalculateLambda calculate) : QWidget() {
    // default calc lambda (no calc)
    this->calculate = calculate;

    // create controls grid
    this->controlsGrid = new QGridLayout();
    controlsGrid->setHorizontalSpacing(0);
    controlsGrid->setVerticalSpacing(0);
    controlsGrid->setContentsMargins(0, 0, 0, 0);

    for (int8_t i = 1; i < 10; i++) {
        addTextButton('0'+i, 4 - (i - 1)/3, (i - 1)%3);
    }
    addTextButton('.', 5, 2);
    addTextButton('0', 5, 0, 1, 2);

    addTextButton('/', 1, 0, 1, 2);
    addTextButton('*', 1, 2);
    addTextButton('-', 1, 3);
    addTextButton('+', 2, 3, 2, 1);
    //addActionButton(QString("del"), CAction::Calculate, 0, 4, 1, 1);

    addTextButton('=', 0, 0);
    addTextButton('(', 0, 1);
    addTextButton(')', 0, 2);
    addActionButton(QString("enter"), CAction::Calculate, 4, 3, 2, 1);

    // create field grid
    this->fieldsGrid = new QGridLayout();
    fieldsGrid->setHorizontalSpacing(0);
    fieldsGrid->setVerticalSpacing(0);
    fieldsGrid->setContentsMargins(0, 0, 0, 0);

    input = new QTextEdit();
    output = new QTextEdit();
    input->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    output->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    connect(input, SIGNAL (textChanged()), this, SLOT (handleInputChanged()));

    fieldsGrid->addWidget(input, 0, 0);
    fieldsGrid->addWidget(output, 1, 0);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addLayout(fieldsGrid, 0, 0);
    mainLayout->addLayout(controlsGrid, 0, 1);

    this->setLayout(mainLayout);
}

void CalcView::handleTextButton() {
    QPushButton* senderButton = static_cast<QPushButton *>(sender());
    this->input->setText(this->input->toPlainText() + senderButton->text());
}

void CalcView::handleCalculateButton() {
    this->output->setText(
        QString::fromStdString(
            this->calculate(this->input->toPlainText().toStdString())
        )
    );
}

void CalcView::handleInputChanged() {
    this->output->setText(
        QString::fromStdString(
            this->calculate(this->input->toPlainText().toStdString())
        )
    );
}

void CalcView::handleDeleteButton() {
    this->input->setText(this->input->toPlainText().right(1));
}
