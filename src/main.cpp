/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    main.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*    By: ddevico <ddevico@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*    Created: 2017/04/13 16:29:25 by ddevico           #+#    #+#            */
/*    Updated: 2017/04/13 17:43:07 by ddevico          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Calculator.hpp"
#include "Exception.hpp"
#include "Parse.hpp"

int cptLine = 1;


static bool isFloatNumber(const std::string& string){
  std::string::const_iterator it = string.begin();
  bool decimalPoint = false;
  size_t minSize = 0;
  if(string.size()>0 && (string[0] == '-' || string[0] == '+')){
    it++;
    minSize++;
  }
  while(it != string.end()){
    if(*it == '.'){
      if(!decimalPoint) decimalPoint = true;
      else break;
    }else if(!std::isdigit(*it) && ((*it!='f') || it+1 != string.end() || !decimalPoint)){
      break;
    }
    ++it;
  }
  return string.size()>minSize && it == string.end();
}

int main(int ac, char **av) {
    try {
      Calculator a;
      Parse p;
      std::size_t found;
      std::string filename;

      if (ac > 2)
        throw std::exception();
      else if (ac == 1)
      {
        std::ofstream ofs("test.txt");
        if (!ofs)
      	{
      		std::cerr << "Error create file" << std::endl;
      		exit(1);
      	}
        while (1)
        {
          std::string command;
          std::string n;
          getline(std::cin, command);
          if (command == ";;")
            break;
          ofs << command << std::endl;
        }
        filename = "test.txt";
      }
      if (filename != "test.txt")
        filename = av[1];
      std::ifstream ifss(filename);
      std::string linee;
      int cpt = 1;
      while (std::getline(ifss, linee)){
        if (linee.find("exit") != std::string::npos)
        {
          cpt = 0;
        }
      }
      if (cpt != 0){
        std::cout << "ERROR : Exit is not here." << std::endl;
        exit (1);
      }
      std::ifstream ifs(filename);
      std::string line;
      while (std::getline(ifs, line)){
        std::string n;
        n = p.verifCommand(line);
        cptLine++;
        if (n != "NULL" && isFloatNumber(n))
        {
          if ((found = line.find("push")) != std::string::npos)
          {
            if ((found = line.find("int8")) != std::string::npos)
              a.push(a.createOperand(INT8, n));
            if ((found = line.find("int16")) != std::string::npos)
              a.push(a.createOperand(INT16, n));
            if ((found = line.find("int32")) != std::string::npos)
              a.push(a.createOperand(INT32, n));
            if ((found = line.find("float")) != std::string::npos)
              a.push(a.createOperand(FLOAT, n));
            if ((found = line.find("double")) != std::string::npos)
              a.push(a.createOperand(DOUBLE, n));
          }
          if ((found = line.find("assert")) != std::string::npos)
          {
            if ((found = line.find("int8")) != std::string::npos)
              a.assert(a.createOperand(INT8, n));
            if ((found = line.find("int16")) != std::string::npos)
              a.assert(a.createOperand(INT16, n));
            if ((found = line.find("int32")) != std::string::npos)
              a.assert(a.createOperand(INT32, n));
            if ((found = line.find("float")) != std::string::npos)
              a.assert(a.createOperand(FLOAT, n));
            if ((found = line.find("double")) != std::string::npos)
              a.assert(a.createOperand(DOUBLE, n));
          }
          if ((found = line.find("pop")) != std::string::npos)
            a.pop();
          if ((found = line.find("dump")) != std::string::npos)
            a.dump();
          if ((found = line.find("add")) != std::string::npos)
            a.add();
          if ((found = line.find("sub")) != std::string::npos)
            a.sub();
          if ((found = line.find("mul")) != std::string::npos)
            a.mul();
          if ((found = line.find("div")) != std::string::npos)
            a.div();
          if ((found = line.find("mod")) != std::string::npos)
            a.mod();
          if ((found = line.find("print")) != std::string::npos)
            a.print();
        }
      }
    } catch (const Exception &e) {
        std::cerr << "Line ";
        std::cerr << cptLine;
        std::cerr << " : Error : " << e.what() << std::endl;
    }
    return (0);
}
