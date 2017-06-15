/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Parse.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "Parse.hpp"

Parse::Parse(void){
  return;
}

Parse::Parse(Parse const & src){
	*this = src;
  return;
}

Parse::~Parse(void){
  return;
}

Parse & 	Parse::operator=(Parse const & rhs){
  (void) rhs;
	return *this;
}

std::string Parse::deleteSpace(std::string c){
  int i = 0;

  for(i=c.size()-1; i >= 0; i-- )
  {
    if(c[i] == ' ' && c[i] == c[i-1])
    {
        c.erase( c.begin() + i );
    }
  }
  return c;
}

std::string Parse::verifCommand(std::string c){
  unsigned long i = 0;
  std::string n;
  std::size_t found;

  c = deleteSpace(c);
  if (c[0] == ' ')
  {
    for(i = 0; i <= c.size()-1; i++ )
    {
      if(c[i] != ' ')
        break;
      c.erase( c.begin() + i );
    }
  }
  if (c[i] == ';' || !c[i])
  {
    n = "NULL";
    return (n);
  }
  if (((found = c.find("push int8(")) != std::string::npos
      || (found = c.find("push int16(")) != std::string::npos
      || (found = c.find("push int32(")) != std::string::npos
      || (found = c.find("push float(")) != std::string::npos
      || (found = c.find("push double(")) != std::string::npos))
  {
    if (found != 0)
      throw Exception("Invalid command.");
    i = 0;
    while (c[i])
    {
      if (c[i] == '(')
      {
        i++;
        while (c[i] != ')')
        {
          n = n + c[i];
          i++;
        }
        if (!c[i + 1] || c[i + 1] == ' ')
          break;
        else
          throw Exception("Invalid command.");
      }
      i++;
    }
  }
  else if (((found = c.find("assert int8(")) != std::string::npos
      || (found = c.find("assert int16(")) != std::string::npos
      || (found = c.find("assert int32(")) != std::string::npos
      || (found = c.find("assert float(")) != std::string::npos
      || (found = c.find("assert double(")) != std::string::npos))
  {
    if (found != 0)
      throw Exception("Invalid command.");
    i = 0;
    while (c[i])
    {
      if (c[i] == '(')
      {
        i++;
        while (c[i] != ')')
        {
          n = n + c[i];
          i++;
        }
        if (!c[i + 1] || c[i + 1] == ' ')
          break;
        else
          throw Exception("Invalid command.");
      }
      i++;
    }
  }
  else if ((((found = c.find("pop")) != std::string::npos))
      || (((found = c.find("dump")) != std::string::npos))
      || (((found = c.find("add")) != std::string::npos))
      || (((found = c.find("sub")) != std::string::npos))
      || (((found = c.find("mul")) != std::string::npos))
      || (((found = c.find("div")) != std::string::npos))
      || (((found = c.find("mod")) != std::string::npos))
      || (((found = c.find("print")) != std::string::npos))
      || (((found = c.find("exit")) != std::string::npos)))
      {
        if (found != 0)
          throw Exception("Invalid command.");
        n = '0';
      }
  else
    throw Exception("Invalid command.");
  if (n.empty())
    throw Exception("Invalid command.");
  return (n);
}
