/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Exception.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "Exception.hpp"

Exception::Exception(std::string const& msg) throw() :  _msg(msg) {

}

Exception::~Exception() throw() {

}

const char* Exception::what() const throw() {
    return (_msg.c_str());
}
