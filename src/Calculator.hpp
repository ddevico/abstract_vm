/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Calculator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CALCULATOR_HPP__
#define	__CALCULATOR_HPP__

#include <iostream>
#include <string>
#include <list>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Exception.hpp"

typedef	std::list<IOperand const *> opStack;

class	Calculator
{
  public:
    Calculator(void);
    Calculator(Calculator const & src);
    ~Calculator(void);
    Calculator & 	operator=(Calculator const & rhs);

    IOperand	const	*createOperand(eOperandType type, std::string const &value) const;

    void        push(IOperand const *rhs);
    void        pop();
    void        assert(IOperand const *rhs);
    void        dump();

    IOperand const		*get();

    IOperand const		*add();
    IOperand const		*sub();
    IOperand const		*mul();
    IOperand const		*div();
    IOperand const		*mod();
    void 		    print();


  private:
    typedef IOperand const *(Calculator::*funcPtr)(const std::string &) const;
    funcPtr		_callFunction[5];
    opStack		_stack;

    IOperand const    *createInt8(std::string const & value) const;
    IOperand const		*createInt16(std::string const &value) const;
    IOperand const		*createInt32(std::string const &value) const;
    IOperand const		*createFloat(std::string const &value) const;
    IOperand const		*createDouble(std::string const &value) const;
};


#endif	/* __CALCULATOR_HPP__ */
