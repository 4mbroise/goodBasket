#include <QtTest>
#include <QCoreApplication>

// add necessary includes here

class testPC : public QObject
{
    Q_OBJECT

public:
    testPC();
    ~testPC();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();

};

testPC::testPC()
{

}

testPC::~testPC()
{

}

void testPC::initTestCase()
{

}

void testPC::cleanupTestCase()
{

}

void testPC::test_case1()
{

}

QTEST_MAIN(testPC)

#include "tst_testpc.moc"
