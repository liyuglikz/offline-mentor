#ifndef TRAININGFORM_H
#define TRAININGFORM_H

#include <omkit/section.h>
#include <omkit/solution.h>

#include <QWidget>
#include <QHash>

namespace Ui {
class TrainingForm;
}

class QListWidgetItem;
class TotalPage;

class TrainingForm : public QWidget
{
    Q_OBJECT

public:
    explicit TrainingForm(QWidget *parent = 0);
    ~TrainingForm();

    bool setSection(const Section& section);
    QUuid sectionId() const;
    bool tryClose();

signals:
    void savedSolution(const Solution& solution);

private slots:
    void on_listWidget_itemSelectionChanged();
    void on_startButton_clicked();
    void onAnswerEntered(QListWidgetItem* caseItem);
    void toMentorAnswer(QListWidgetItem* caseItem);
    void backToQuestion(QListWidgetItem* caseItem);
    void next(QListWidgetItem* caseItem);
    void transferSolution();
    void createSolutionArchive(QString path);

private:
    void openQuestionPage(int pageId);
    bool isSectionCompleted() const;
    void updateTotal();

    Ui::TrainingForm *ui;

    struct NodeDescriptor {
        int questionPageId;
        int mentorAnswerPageId;
        QListWidgetItem* nextItem;
    };

    Section section;
    QHash<QListWidgetItem*, NodeDescriptor> nodes;
    QListWidgetItem* instructionItem = nullptr;
    QListWidgetItem* firstCaseItem = nullptr;
    QListWidgetItem* totalItem = nullptr;
    TotalPage* totalPage = nullptr;
};

#endif // TRAININGFORM_H
