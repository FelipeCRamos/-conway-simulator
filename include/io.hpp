#ifndef IO_HPP_
#define IO_HPP_

/*!
 * \file IO.hpp
 * \brief Input/output related stuff lib
 * \author Felipe Ramos
 */

#include <fstream>
#include <iostream>
#include <sstream>

#include "generation.hpp"

Gen *parse( std::ifstream & );

#endif
