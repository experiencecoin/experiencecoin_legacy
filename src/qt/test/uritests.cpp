#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("experiencecoin://DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("experiencecoin:DJ7zB7c5BsB9UJLy1rKQtY7c6CQfGiaRLM?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
