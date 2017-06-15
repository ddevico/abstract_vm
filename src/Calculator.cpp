/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Calculator.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "Calculator.hpp"
#include <iomanip>

Calculator::Calculator(void){
  _callFunction[0] = &Calculator::createInt8;
  _callFunction[1] = &Calculator::createInt16;
  _callFunction[2] = &Calculator::createInt32;
  _callFunction[3] = &Calculator::createFloat;
  _callFunction[4] = &Calculator::createDouble;
  return;
}

Calculator::Calculator(Calculator const & src){
  _callFunction[0] = &Calculator::createInt8;
  _callFunction[1] = &Calculator::createInt16;
  _callFunction[2] = &Calculator::createInt32;
  _callFunction[3] = &Calculator::createFloat;
  _callFunction[4] = &Calculator::createDouble;
  *this = src;
  return;
}

Calculator::~Calculator(void){
  return;
}

Calculator & 	Calculator::operator=(Calculator const & rhs){
  (void) rhs;
	return *this;
}

IOperand const 		*Calculator::createInt8(std::string const &value) const
{
  IOperand const		*operand;
  std::stringstream ss;
  double nb;

  ss << value;
  ss >> nb;
  operand = new Operand<char>(INT8, nb);
  return (operand);
}

IOperand const 		*Calculator::createInt16(std::string const &value) const
{
  IOperand const		*operand;
  std::stringstream ss;
  double nb;

  ss << value;
  ss >> nb;

  operand = new Operand<short>(INT16, nb);
  return (operand);
}

IOperand const 		*Calculator::createInt32(std::string const &value) const
{
  IOperand const		*operand;
  std::stringstream ss;
  double nb;

  ss << value;
  ss >> nb;
  operand = new Operand<int>(INT32, nb);
  return (operand);
}

IOperand const 		*Calculator::createFloat(std::string const &value) const
{
  IOperand const		*operand;
  std::stringstream ss;
  float flt;

  std::istringstream istrv(value);
  istrv >> flt;
  operand = new Operand<float>(FLOAT, flt);
  return (operand);
}

IOperand const 		*Calculator::createDouble(std::string const &value) const
{
  IOperand const		*operand;
  std::stringstream ss;
  double nb;

  ss << value;
  ss >> nb;
  operand = new Operand<double>(DOUBLE, nb);
  return (operand);
}

IOperand const *Calculator::createOperand(eOperandType type, std::string const &value) const
{
  return ((this->*_callFunction[type])(value));
}

void			Calculator::push(IOperand const *rhs)
{
  _stack.push_front(rhs);
}

void			Calculator::assert(IOperand const *rhs)
{
  IOperand const		*prec = get();

  if (_stack.size() == 0)
      throw Exception("Assert on empty stack.");
  if (rhs->toString() != prec->toString())
    throw Exception("assert instruction is not true.");
  if (rhs->getType() != prec->getType())
    throw Exception("assert instruction is not true.");

}

void			Calculator::pop()
{
  if (_stack.size() <= 0)
      throw Exception("Pop on empty stack.");
  _stack.pop_front();
}

void                    Calculator::dump()
{
  if (_stack.size() <= 0)
      throw Exception("Dump on empty stack.");
  for (std::list<IOperand const *>::iterator it = _stack.begin(); it != _stack.end(); ++it)
    std::cout << (*it)->toString() << std::endl;
}

IOperand const		*Calculator::get()
{
  if (_stack.size() <= 0)
    return (NULL);
  return (_stack.front());
}

IOperand const		*Calculator::add()
{
  if (_stack.size() < 2)
    throw Exception("Add on stack with less than two values");
  IOperand const		*val1 = get();
  pop();
  IOperand const	*val2 = get();
  pop();

  push(*val1 + *val2);
  return (get());
}

IOperand const		*Calculator::sub()
{
  if (_stack.size() < 2)
    throw Exception("Sub on stack with less than two values");
  IOperand const		*val1 = get();
  pop();
  IOperand const		*val2 = get();
  pop();

  push(*val2 - *val1);
  return (get());
}

IOperand const		*Calculator::mul()
{
  if (_stack.size() < 2)
    throw Exception("Mul on stack with less than two values");
  IOperand const		*val1 = get();
  pop();
  IOperand const		*val2 = get();
  pop();

  push(*val2 * *val1);
  return (get());
}

IOperand const		*Calculator::div()
{
  if (_stack.size() < 2)
    throw Exception("Div on stack with less than two values.");
  IOperand const		*val1 = get();
  pop();
  IOperand const		*val2 = get();
  pop();

  push(*val2 / *val1);
  return (get());
}

IOperand const		*Calculator::mod()
{
  if (_stack.size() < 2)
    throw Exception("Mod on stack with less than two values");
  IOperand const		*val1 = get();
  pop();
  IOperand const		*val2 = get();
  pop();

  push(*val2 % *val1);
  return (get());
}

void 		Calculator::print()
{
  if (_stack.size() == 0)
    throw Exception("Print instruction on empty stack");
  IOperand const		*prec = get();

  if (prec->getType() != 0)
    throw Exception("Print instruction on no 8-bit integer");
  std::cout << static_cast<char>(std::stoi(prec->toString()));
}
