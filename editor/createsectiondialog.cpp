#include "createsectiondialog.h"
#include "section.h"
#include "ui_createsectiondialog.h"

#include <QMessageBox>
#include <QFileDialog>

CreateSectionDialog::CreateSectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateSectionDialog)
{
    ui->setupUi(this);
}

CreateSectionDialog::~CreateSectionDialog()
{
    delete ui;
}

Section CreateSectionDialog::result() const
{
    return section;
}

void CreateSectionDialog::accept()
{
    auto path = ui->pathEdit->text();
    if (!path.endsWith(".oms", Qt::CaseInsensitive))
        path.append(".oms");

    section.name = ui->nameEdit->text();
    section.path = path;
    if (!section.create()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось создать раздел. "
                                             "Проверьте правильность написания пути.");
        return;
    }
    QDialog::accept();
}

void CreateSectionDialog::on_choosePathButton_clicked()
{
    QString path = QFileDialog::getSaveFileName(
                this, "Путь к файлу раздела", "", "Файл раздела (*.oms)");
    if (!path.isEmpty()) {
        ui->pathEdit->setText(path);
    }
}