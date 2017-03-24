#import <StoreKit/StoreKit.h>
#include "store/CCStorePaymentTransactionWrapper.h"


NS_CC_EXTRA_BEGIN

StorePaymentTransactionWrapper* StorePaymentTransactionWrapper::createWithTransaction(void* transactionObj)
{
    StorePaymentTransactionWrapper* transaction = new StorePaymentTransactionWrapper();
    transaction->m_transactionObj = transactionObj;
    [(SKPaymentTransaction *)transactionObj retain];
    return transaction;
}

StorePaymentTransactionWrapper::~StorePaymentTransactionWrapper(void)
{
    [(SKPaymentTransaction *)m_transactionObj release];
}

NS_CC_EXTRA_END

