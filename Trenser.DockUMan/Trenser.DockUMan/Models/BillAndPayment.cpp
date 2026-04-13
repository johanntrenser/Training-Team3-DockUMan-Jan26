/*
 * File: BillAndPayment.cpp
 * Description: Handles billing and payment details including getters and setters for transaction-related information
 * Author: Akish Babu
 * Created: 30-Mar-2026
 */
#include "BillAndPayment.h"

std::string BillAndPayment::getId() const
{
    return m_id;
}

double BillAndPayment::getTotalAmount() const
{
    return m_totalAmount;
}

std::string BillAndPayment::getTimestamp() const
{
    return m_timestamp;
}

std::shared_ptr<Booking> BillAndPayment::getBookingDetails() const
{
    return m_bookingDetails;
}

Enums::BillingStatus BillAndPayment::getBillingStatus() const
{
    return m_billingStatus;
}

Enums::PaymentMethod BillAndPayment::getPaymentMethod() const
{
    return m_paymentMethod;
}

Enums::PaymentStatus BillAndPayment::getPaymentStatus() const
{
    return m_paymentStatus;
}

std::string BillAndPayment::getTransactionId() const
{
    return m_transactionId;
}

void BillAndPayment::setId(const std::string& id)
{
    m_id = id;
}

void BillAndPayment::setTotalAmount(double totalAmount)
{
    m_totalAmount = totalAmount;
}

void BillAndPayment::setTimestamp(const std::string& timestamp)
{
    m_timestamp = timestamp;
}

void BillAndPayment::setBookingDetails(const std::shared_ptr<Booking>& bookingDetails)
{
    m_bookingDetails = bookingDetails;
}

void BillAndPayment::setBillingStatus(Enums::BillingStatus billingStatus)
{
    m_billingStatus = billingStatus;
}

void BillAndPayment::setPaymentMethod(Enums::PaymentMethod paymentMethod)
{
    m_paymentMethod = paymentMethod;
}

void BillAndPayment::setPaymentStatus(Enums::PaymentStatus paymentStatus)
{
    m_paymentStatus = paymentStatus;
}

void BillAndPayment::setTransactionId(const std::string& transactionId)
{
    m_transactionId = transactionId;
}
