#include <QtTest>

// add necessary includes here

class testConsommateur : public QObject
{
    Q_OBJECT

public:
    testConsommateur();
    ~testConsommateur();

private slots:
    void test_case1();

};

testConsommateur::testConsommateur()
{

}

testConsommateur::~testConsommateur()
{

}

void testConsommateur::test_case1()
{

}

QTEST_APPLESS_MAIN(testConsommateur)

#include "tst_testconsommateur.moc"
