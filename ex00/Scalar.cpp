/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:55:39 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/21 17:40:00 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <iostream>

static void printAllError() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

// 10x hardcoded values to avoid redundant calculations/parsing
static void handlePseudoLiterals(const char *input) {
  if (strcmp(input, "nanf") == 0) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (strcmp(input, "-inff") == 0) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  } else if (strcmp(input, "+inff") == 0) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
  }
  exit(0);
}

static void detectPseudoLiterals(const char *input) {
  if (strcmp(input, "nanf") == 0 || strcmp(input, "-inff") == 0 ||
      strcmp(input, "+inff") == 0 ||
      strcmp(input, "nan") == 0) {
    handlePseudoLiterals(input);
  }
}

void ScalarConverter::convert(const char *input) {

  // if the input is one character and non-digit, handle as char mode:
  if (strlen(input) == 1 && !isdigit(input[0])) {
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1)
              << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << static_cast<double>(c) << std::endl;
  } else {
      char *end = NULL;
      double value = std::strtod(input, &end);

      // Check if a trailing 'f' is present (valid float literal in C++)
      if (*end == 'f' && *(end + 1) == '\0')
          ; // valid conversion, do nothing extra
      else if (*end != '\0') {
        detectPseudoLiterals(input);
        printAllError();
        return;
      }

      // Converting to char if the value is within range.
      if (value >= CHAR_MIN && value <= CHAR_MAX) {
        if (std::isprint(static_cast<char>(value)))
          std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
          std::cout << "char: Non displayable" << std::endl;
      } else {
        std::cout << "char: impossible" << std::endl;
      }

      // Converting to int if within int range
      if (value >= INT_MIN && value <= INT_MAX) {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
      } else {
        std::cout << "int: impossible" << std::endl;
      }

      float f = static_cast<float>(value);
      double d = static_cast<double>(value);

      // For float: if the fractional part is 0, force one decimal digit.
      if (f - static_cast<int>(f) == 0)
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << f << "f" << std::endl;
      else
        std::cout << "float: " << f << "f" << std::endl;

      // For double: if the fractional part is 0, force one decimal digit.
      if (d - static_cast<int>(d) == 0)
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << d << std::endl;
      else
        std::cout << "double: " << d << std::endl;
  }
}
