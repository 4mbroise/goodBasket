#ifndef PCSOUSIG_H
#define PCSOUSIG_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class PcSousConsommateur; }
QT_END_NAMESPACE

class PcSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    PcSousConsommateur(QWidget *parent = nullptr);
    ~PcSousConsommateur();
    void setData(const QString& adresse);
    QString getAdresse();

private slots:

private:
    Ui::PcSousConsommateur *ui;
};

#endif // PCSOUSIG_H
