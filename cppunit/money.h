#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money
{
public:
  Money( double amount, std::string currency )
    : m_amount( amount )
    , m_currency( currency )
  {
  }

  double getAmount() const
  {
    return m_amount;
  }

  std::string getCurrency() const
  {
    return m_currency;
  }
  bool operator ==( const Money &other ) const
  {
	  return m_amount == other.m_amount  &&  
		  m_currency == other.m_currency;
  }

  bool operator !=( const Money &other ) const
  {
	  return !(*this == other);
  }

private:
  double m_amount;
  std::string m_currency;
};

#endif
