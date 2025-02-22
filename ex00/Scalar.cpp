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
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>

static void printAllError() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

// 10x hardcoded values to avoid redundant calculations/parsing
static void handlePseudoLiterals(const std::string &input) {
  if (input == "nanf") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  } else if (input == "-inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  } else if (input == "+inff") {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: inff" << std::endl;
    std::cout << "double: inf" << std::endl;
  } else {
    // In case input us actually wrong.
    printAllError();
  }
}

// static bool isPseudoLiteral(const std::string &input) {
//   return input == "nanf" || input == "-inff" || input == "+inff" ||
//          input == "nan" || input == "-inf" || input == "+inf" || input == "inf";
// }

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

    //// Check for pseudo literals before since stdtod does not handle all of
    /// them, and does direct string matching, Probably better of to handle them
    /// first. normal number => Psuedo literals are handled automatically.

    std::string savedInput = input;
    // after handling pseudo literals, we can proceed with normal conversion.
    // anything that is not a pseudo and is a string should be parsed for errors
    // eg. (InfinitY) should not pass, it does.

    // if (std::strspn(input, "0123456789.-+f") != strlen(input))
    // {
    //   printAllError();
    //     return;
    // }

    char *end = NULL;
    double value = std::strtod(input, &end);

    // Check for trailing characters
    if (*end == 'f' && *(end + 1) == '\0')
      ; // valid conversion, do nothing extra
    else if (*end != '\0') {
      // if (isPseudoLiteral(input))
        handlePseudoLiterals(input);
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
      std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f"
                << std::endl;
    else
      std::cout << "float: " << f << "f" << std::endl;

    // For double: if the fractional part is 0, force one decimal digit.
    if (d - static_cast<int>(d) == 0)
      std::cout << "double: " << std::fixed << std::setprecision(1) << d
                << std::endl;
    else
      std::cout << "double: " << d << std::endl;
  }
}
