/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Operand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef __OPERAND_HPP__
#define __OPERAND_HPP__

#include <iostream>
#include <string>
#include <sstream>
#include <float.h>
#include "IOperand.hpp"
#include "Exception.hpp"

typedef struct s_operand {
  eOperandType	type;
  std::string   name;
  int		precision;
}		t_operand;

static t_operand operands[] =
{
  {INT8, "int8", 0},
  {INT16, "int16", 1},
  {INT32, "int32", 2},
  {FLOAT, "float", 3},
  {DOUBLE, "double", 4},
};

template <typename T>
class Operand : public IOperand {
  private:
    eOperandType	_type;
    int		_precision;
    T		_value;

  public:
    Operand(eOperandType type, const double &value)
    {
      _type = type;
      if (_type == INT8)
      {
        if (value < INT8_MAX)
        {
    	     if (value > INT8_MIN)
  	         _precision = operands[type].precision;
           else
    	       throw Exception("Underflow.");
        }
        else
          throw Exception("Overflow.");
      }
      if (_type == INT16)
      {
        if (value < INT16_MAX)
        {
    	     if (value > INT16_MIN)
  	         _precision = operands[type].precision;
           else
    	       throw Exception("Underflow.");
        }
        else
          throw Exception("Overflow.");
      }
      if (_type == INT32)
      {
        if (value < INT32_MAX)
        {
    	     if (value > INT32_MIN)
  	         _precision = operands[type].precision;
           else
    	       throw Exception("Underflow.");
        }
        else
          throw Exception("Overflow.");
      }
      if (_type == FLOAT)
      {
        if (value < FLT_MAX)
        {
    	     if (value > -FLT_MAX-1)
  	         _precision = operands[type].precision;
           else
    	       throw Exception("Underflow.");
        }
        else
          throw Exception("Overflow.");
      }
      if (_type == DOUBLE)
      {
        if (value < DBL_MAX)
        {
    	     if (value > -DBL_MAX-1)
  	         _precision = operands[type].precision;
           else
    	       throw Exception("Underflow.");
        }
        else
          throw Exception("Overflow.");
      }
      _value = value;
    }

    virtual std::string const &toString(void) const
    {
      std::string *str = new std::string();
      std::ostringstream ss;

      if (_type == INT8)
        ss << (int) _value;
      else
        ss << _value;
      str->append(ss.str());
      return (*str);
    }

    virtual int getPrecision(void) const {
      return (_precision);
    }

    virtual eOperandType getType(void) const {
      return (_type);
    }

    virtual T getValue(void) const {
      return (_value);
    }

    virtual IOperand const *operator+(IOperand const &rhs) const
    {
      IOperand const *operand = NULL;
      eOperandType type;
      std::stringstream ss;
      double nb;

      ss << rhs.toString();
      ss >> nb;
      type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
      switch (type) {
      case INT8:
        operand = new Operand<char>(type, _value + nb);
        break;
      case INT16:
        operand = new Operand<short>(type, _value + nb);
        break;
      case INT32:
        operand = new Operand<int>(type, _value + nb);
        break;
      case FLOAT:
        operand = new Operand<float>(type, _value + nb);
        break;
      case DOUBLE:
        operand = new Operand<double>(type, _value + nb);
        break;
      }
      return (operand);
    }

    virtual IOperand const *operator-(IOperand const &rhs) const
    {
      IOperand *operand = NULL;
      eOperandType type;
      std::stringstream ss;
      double nb;

      ss << rhs.toString();
      ss >> nb;
      type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
      switch (type) {
      case INT8:
        operand = new Operand<char>(type, _value - nb);
        break;
      case INT16:
        operand = new Operand<short>(type, _value - nb);
        break;
      case INT32:
        operand = new Operand<int>(type, _value - nb);
        break;
      case FLOAT:
        operand = new Operand<float>(type, _value - nb);
        break;
      case DOUBLE:
        operand = new Operand<double>(type, _value - nb);
        break;
      }
      return (operand);
    }

    virtual IOperand const *operator*(IOperand const &rhs) const // mul
    {
      IOperand *operand = NULL;
      eOperandType type;
      std::stringstream ss;
      double nb;

      ss << rhs.toString();
      ss >> nb;
      type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
      switch (type) {
      case INT8:
        operand = new Operand<char>(type, _value * nb);
        break;
      case INT16:
        operand = new Operand<short>(type, _value * nb);
        break;
      case INT32:
        operand = new Operand<int>(type, _value * nb);
        break;
      case FLOAT:
        operand = new Operand<float>(type, _value * nb);
        break;
      case DOUBLE:
        operand = new Operand<double>(type, _value * nb);
        break;
      }
      return (operand);
    }

    virtual IOperand const *operator/(IOperand const &rhs) const
    {
      IOperand *operand = NULL;
      eOperandType type;
      std::stringstream ss;
      double nb;

      ss << rhs.toString();
      ss >> nb;
      if (nb == 0)
        throw Exception("Division by zero.");
      type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
      switch (type) {
      case INT8:
        operand = new Operand<char>(type, _value / nb);
        break;
      case INT16:
        operand = new Operand<short>(type, _value / nb);
        break;
      case INT32:
        operand = new Operand<int>(type, _value / nb);
        break;
      case FLOAT:
        operand = new Operand<float>(type, _value / nb);
        break;
      case DOUBLE:
        operand = new Operand<double>(type, _value / nb);
        break;
      }
      return (operand);
    }

    virtual IOperand const *operator%(IOperand const &rhs) const
    {
      IOperand *operand = NULL;
      eOperandType type;
      std::stringstream ss;
      double nb;

      ss << rhs.toString();
      ss >> nb;
      if (nb == 0)
        throw Exception("Modulo by zero.");
      type = _precision >= rhs.getPrecision() ? _type : rhs.getType();
      if (_type == FLOAT || rhs.getType() == FLOAT)
          throw Exception("Modulo with float.");
      else if (_type == DOUBLE || rhs.getType() == DOUBLE)
          throw Exception("Modulo with double.");
      operand = new Operand(type, (int)_value % (int)nb);
      return (operand);
    }

    std::ostream &operator<<(std::ostream &os) {
      os << this->getValue();
      return (os);
    }

};

#endif /*__OPERAND_HPP */
