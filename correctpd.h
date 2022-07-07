#ifndef CORRECTPD_H
#define CORRECTPD_H

#include <QDialog>
#include <QDate>

namespace Ui {
class CorrectPD;
}

class CorrectPD : public QDialog
{
    Q_OBJECT

public:
    explicit CorrectPD(QWidget *parent = nullptr);
    ~CorrectPD();

    void setParams(int tid, int cp, QString dt);


private slots:
    void on_btn_cancel_clicked();

    void on_btn_correct_clicked();

private:
    Ui::CorrectPD *ui;

    int table_id, current_products;
    QString date;

};

#endif // CORRECTPD_H
