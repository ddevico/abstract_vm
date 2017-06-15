/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Exception.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef __EXCEPTION_HPP__
#define	__EXCEPTION_HPP__

#include <string>
#include <exception>

class Exception : public std::exception
{
public:
  Exception(std::string const& msg) throw();
  virtual ~Exception() throw();

  virtual const char* what() const throw();

private:
  std::string   _msg;
};

#endif	/* __EXCEPTION_HPP__ */
