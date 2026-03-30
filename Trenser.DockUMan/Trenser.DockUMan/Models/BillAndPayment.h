#pragma once
#include <iostream>
#include <string>
#include "Booking.h"
#include "Enums.h"

class BillAndPayment
{
private:
    std::string m_id;
    double m_totalAmount;
    std::string m_timestamp;
    std::shared_ptr<Booking> m_bookingDetails;
    Enums::BillingStatus m_billingStatus;
    Enums::PaymentMethod m_paymentMethod;
    Enums::PaymentStatus m_paymentStatus;
    std::string m_transactionId;
public:
    BillAndPayment()
        : m_id{ "" }, m_totalAmount{ 0.0 }, m_timestamp{ "" },
        m_bookingDetails{ nullptr }, m_transactionId{ "" }, m_billingStatus{ Enums::BillingStatus::PENDING },
        m_paymentMethod{ Enums::PaymentMethod::CASH }, m_paymentStatus{Enums::PaymentStatus::UNPAID} {
    }
    BillAndPayment(std::string id, double totalAmount, std::string timestamp, std::shared_ptr<Booking> bookingDetails, std::string transactionId,
        Enums::BillingStatus billingStatus, Enums::PaymentMethod paymentMethod, Enums::PaymentStatus paymentStatus)
        : m_id{ id }, m_totalAmount{ totalAmount }, m_timestamp{ timestamp },
        m_bookingDetails{ bookingDetails }, m_transactionId{ transactionId },
        m_billingStatus{ billingStatus }, m_paymentMethod{ paymentMethod }, m_paymentStatus{ paymentStatus } {
    }
    std::string getId() const;
    double getTotalAmount() const;
    std::string getTimestamp() const;
    std::shared_ptr<Booking> getBookingDetails() const;
    Enums::BillingStatus getBillingStatus() const;
    Enums::PaymentMethod getPaymentMethod() const;
    Enums::PaymentStatus getPaymentStatus() const;
    std::string getTransactionId() const;
    void setId(const std::string& id);
    void setTotalAmount(double totalAmount);
    void setTimestamp(const std::string& timestamp);
    void setBookingDetails(const std::shared_ptr<Booking>& bookingDetails);
    void setBillingStatus(Enums::BillingStatus billingStatus);
    void setPaymentMethod(Enums::PaymentMethod paymentMethod);
    void setPaymentStatus(Enums::PaymentStatus paymentStatus);
    void setTransactionId(const std::string& transactionId);
};

