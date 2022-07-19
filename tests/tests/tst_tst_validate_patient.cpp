#include <QtTest>

// add necessary includes here
#include "patient.h"

class tst_validate_patient : public QObject
{
    Q_OBJECT

public:
    tst_validate_patient();
    ~tst_validate_patient();

private slots:
    void test_RXR_data();
    void test_RXR();
    void test_NHS_data();
    void test_NHS();
    void test_clean_NHS_data();
    void test_clean_NHS();
};

tst_validate_patient::tst_validate_patient()
{

}

tst_validate_patient::~tst_validate_patient()
{

}

void tst_validate_patient::test_RXR_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<bool>("expectedresult");

    QTest::newRow("Well formed") << "RXR1234567" << true;
    QTest::newRow("Leading whitespace") << "   RXR1234567" << true;
    QTest::newRow("Trailing whitespace") << "RXR1234567  " << true;
    QTest::newRow("Lower case") << " rxr1234567" << true;
    QTest::newRow("Whitespace in the middle") << "RXR  1234567" << true;

    QTest::newRow("Too few digits") << "rxr123456" << false;
    QTest::newRow("Too many digits") << "rxr12345678" << false;
    QTest::newRow("No RXR") << "xxx1234567" << false;
    QTest::newRow("Only digits") << "1234567" << false;
    QTest::newRow("Extra letters") << "RXRL1234567" << false;
    QTest::newRow("More than whitespace in the middle") << "rxr g1234567" << false;
}

void tst_validate_patient::test_RXR()
{
    QFETCH(QString, input);
    QFETCH(bool, expectedresult);

    QCOMPARE(Patient::validate_rxr(input), expectedresult);
}

void tst_validate_patient::test_NHS_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<bool>("expectedresult");

    QTest::newRow("Well formed") << "000 111 2222" << true;
    QTest::newRow("Leading whitespace") << "   000 111 2222" << true;
    QTest::newRow("Trailing whitespace") << "000 111 2222  " << true;
    QTest::newRow("No internal whitespace") << "0001112222" << true;
    QTest::newRow("Weird internal whitespace") << "000     111\t2222" << true;

    QTest::newRow("Too few digits") << "000 111 222" << false;
    QTest::newRow("Too many digits") << "000 1111 2222" << false;
    QTest::newRow("Whitespace in the wrong place") << "00 0 111 22 22" << false;
    QTest::newRow("Too many digits, no white space") << "00011122223" << false;
}

void tst_validate_patient::test_NHS()
{
    QFETCH(QString, input);
    QFETCH(bool, expectedresult);

    QCOMPARE(Patient::validate_nhs(input), expectedresult);
}

void tst_validate_patient::test_clean_NHS_data()
{
    QTest::addColumn<QString>("input");
    QTest::addColumn<QString>("expectedresult");

    QTest::newRow("Well formed") << "000 111 2222" << "000 111 2222";
    QTest::newRow("Leading whitespace") << "   000 111 2222" << "000 111 2222";
    QTest::newRow("Trailing whitespace") << "000 111 2222  " << "000 111 2222";
    QTest::newRow("No internal whitespace") << "0001112222" << "000 111 2222";
    QTest::newRow("Weird internal whitespace") << "000     111\t2222" << "000 111 2222";

    QTest::newRow("Too few digits") << "000 111 222" << "NULL";
    QTest::newRow("Too many digits") << "000 1111 2222" << "NULL";
    QTest::newRow("Whitespace in the wrong place") << "00 0 111 22 22" << "NULL";
    QTest::newRow("Too many digits, no white space") << "00011122223" << "NULL";
}

void tst_validate_patient::test_clean_NHS()
{
    QFETCH(QString, input);
    QFETCH(QString, expectedresult);

    QCOMPARE(Patient::clean_nhs(input), expectedresult);
}

QTEST_APPLESS_MAIN(tst_validate_patient)

#include "tst_tst_validate_patient.moc"
