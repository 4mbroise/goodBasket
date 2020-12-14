#ifndef CATALOGUESOUSIG_H
#define CATALOGUESOUSIG_H

#include <QWidget>
#include <produitsousig.h>

QT_BEGIN_NAMESPACE
namespace Ui { class CatalogueSousConsommateur; }
QT_END_NAMESPACE

class CatalogueSousConsommateur : public QWidget
{
    Q_OBJECT

public:
    explicit CatalogueSousConsommateur(QWidget *parent = nullptr);
    ~CatalogueSousConsommateur();
    void setData(const QString& adressePC,const QString& idConsommateur);
    Ui::CatalogueSousConsommateur& getUI();
private slots:
    void on_Retourner_clicked();
signals:
    void sendsignal();

private:
    Ui::CatalogueSousConsommateur *ui;
};

#endif // CATALOGUESOUSIG_H
