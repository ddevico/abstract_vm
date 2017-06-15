/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    IOperand.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IOPERAND_HPP__
#define __IOPERAND_HPP__

#include <string>
#include <iostream>

int     my_atoi(std::string);
double  my_atof(std::string);

enum eOperandType {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
};

class IOperand {
public:

  virtual int getPrecision(void) const = 0;
  virtual eOperandType getType(void) const = 0;

  virtual IOperand const *operator+(IOperand const &rhs) const = 0;
  virtual IOperand const *operator-(IOperand const &rhs) const = 0;
  virtual IOperand const *operator*(IOperand const &rhs) const = 0;
  virtual IOperand const *operator/(IOperand const &rhs) const = 0;
  virtual IOperand const *operator%(IOperand const &rhs) const = 0;

  virtual std::string const& toString(void) const = 0;


  virtual ~IOperand(void) {
  }
};

#endif /*__IOPERAND_HPP__ */
