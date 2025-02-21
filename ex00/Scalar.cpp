/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:55:39 by mlamkadm          #+#    #+#             */
/*   Updated: 2025/02/17 12:55:39 by mlamkadm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

static void printAllError() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

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
      strcmp(input, "+inff") == 0) {
    handlePseudoLiterals(input);
  }
}

void ScalarConverter::convert(const char *input) {

  // if the input is one character char mode
  if (strlen(input) == 1 && !isdigit(input[0])) {
    char c = input[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
  } else {
    {
      char *end = NULL;

      double value = std::strtod(input, &end);

      // Check if the input is a valid number. Else print all impossible.
      if (*end != '\0') {
        std::cout << "BREAK ======================:" << std::endl;
        detectPseudoLiterals(input);
        printAllError();
        return;
      }

      // Converting to char if the value is within range.
      if (value >= CHAR_MIN && value <= CHAR_MAX) {
        if (std::isprint(
                static_cast<char>(value))) // Check if the value is printable
          std::cout << "char: '" << static_cast<char>(value) << "'"
                    << std::endl;
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

      // Always display the float and double representations.
      std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
      std::cout << "double: " << static_cast<double>(value) << std::endl;
    }
  }
}
