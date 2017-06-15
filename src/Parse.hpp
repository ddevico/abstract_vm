/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Parse.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSE_HPP__
#define	__PARSE_HPP__
#define MAXSTR 256

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "Exception.hpp"


class Parse
{
  public:
    Parse(void);
    Parse(Parse const & src);
		~Parse(void);
		Parse & 	operator=(Parse const & rhs);

    std::string verifCommand(std::string c);

  private:
    std::string deleteSpace(std::string c);
};

#endif	/* __PARSE_HPP__ */
